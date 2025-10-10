#个人日记系统
import datetime as da
#这是一个python自带的模块，可以直接引用，da是我们自定义的，写起来更方便一些
from api import user_i
#而这个模块，则是我们自己写的，可以让我们代码看起来更好看一点，也方便我们去查找和修改

from DB import db_handle
#这个模块也是我们自己写的
class LogIn():
    '''
    这是一个用于实现登录和注册功能的类LogIn，
    其中包含了两个方法register和login。
    register方法用于用户注册，通过输入姓名和密码，
    将用户信息注册到用户数据库中。login方法用于用户登录，
    通过输入用户名和密码，验证用户登录信息并返回用户名
    '''
    def __init__(self, name):
        self.name = name

    def register(self):
        while 1:
            user_name = input('请输入姓名>>>')
            password = input('请输入你的密码>>>')
            re_password = input('请再次输入你的密码>>>')
            #下面的if语句用来判断用户输入数据是否一致
            if password == re_password:
                flag, msg = user_i.register_info(user_name, password)
                # flag为True则表示注册成功，为False则表示注册失败
                #可以移步到user_i.py中查看具体的返回值
                if flag:
                    print(msg)
                    break
                else:
                    print(msg)

            else:
                print('密码不一致,重新注册')

    def login(self):
        user_name = input('请输入用户名')
        password = input('请输入密码')
        # 写到这，先去取数据再来写判断
        flag, msg = user_i.login_info(user_name, password)
        #flag为True则表示登录成功，为False则表示登录失败
        #可以移步到user_i.py中查看具体的返回值
        #
        if flag:
            print(msg)
            login_user = user_name
        else:
            print(msg)
            login_user = None
        #这个return值用来判断是否成功登录
        return login_user
class Note(LogIn):
    '''
    Note类是一个日记应用的类，继承自LogIn类。
    初始化函数接受一个name参数，并调用父类的初始化函数。
    在初始化过程中，设置了当前日期和时间、空的标题和内容，
    以及一个Note_operation字典，用于存储所有的操作。
    '''
    def __init__(self, name):
        super().__init__(name)
        self.date = da.datetime.now().strftime("%Y-%m-%d %H:%M")
        #通过调用python的内置模块，获取当前日期和时间
        #如果不加上strftime，则默认是%Y-%m-%d %H:%M:%S
        #那要是我们只想把日期精确到几月几日呢？
        #这个写法是精确到时分的
        #试着在观察"%Y-%m-%d %H:%M"后，写一下
        self.title = ""
        self.content = "  "
        self.Note_operation = {"1": self.write, "2": self.read, "3": self.update,"4":self.backup,"5":self.restore}
        #这个Note_operation字典，用来存储所有的操作，键为数字，值为对应的操作函数
        #这样可以少写一些elif语句，直接通过键值来调用对应的操作函数
    def write(self):
        '''
        这是一个用来写日记的函数
        '''
        user_data = db_handle.get_data(self.name,db_handle.main_file)
        #这里通过调用get_data方法，获取用户数据（是一个字典）
        self.title = input("请输入日记标题：")
        if self.title in user_data["content"]:
            # 用来判断用户输入的标题是否已经存在
            # 不存在就通过再调用一下这个函数，来实现循环的效果
            print("该标题已经存在，请重新输入")
            self.write()
            return 0
        content_list = []
        #这是一个用来存储用户输入的日记内容的列表
        while self.content[-1]!="*":
            #这是一个循环，用来判断用户输入的内容是否已经结束
            #如果没有结束，就继续输入
            self.content = input("请输入日记内容，并在末尾加上*来结束写作,")
            if len(self.content)<=2:
                self.content = "  "+self.content
            content_list.append(self.content.strip())
        content_list[-1] = content_list[-1][:-1]
        #[:-1]用切片来去除列表中的最后一个元素的*
        content = ["日记题目："+self.title , content_list,"编写日期："+ self.date]
        user_data["content"][self.title] = content
        db_handle.save_data(user_data,db_handle.main_file)

    def read(self):
        '''
        这是一个用来根据指定日记标题来查询日记功能的函数
        '''
        user_data = db_handle.get_data(self.name,db_handle.main_file)
        #这里通过调用get_data方法，获取用户数据（是一个字典）
        print("已有的日记标题有")
        for i in user_data["content"]:
            #展示已有的日记标题
            print(i)
        title = input("请输入你要查看的日记标题：")
        if title not in user_data["content"]:
            #判断用户输入的标题是否已经存在
            print("该标题不存在，请重新输入")
        else:
            for i in range(3):
                #content对应的列表有三个元素，分别是题目，内容，日期，所以循环3次
                if i == 1:
                #1是内容的的下标，当i等于1时，就打印内容
                #而内容是分行保存在一个列表中的，所以需要遍历这个列表
                    for j in user_data["content"][title][i]:
                        print(j)
                else:
                    print(user_data["content"][title][i])

    def backup(self):
        #这是一个用来备份日记的函数，原理跟write差不多
        user_data = db_handle.get_data(self.name,db_handle.main_file)
        db_handle.save_data(user_data,db_handle.backup_file)
        print("备份成功")

    def restore(self):
        #这是一个用来还原日记的函数，原理跟backup差不多
        user_data = db_handle.get_data(self.name,db_handle.backup_file)
        db_handle.save_data(user_data,db_handle.main_file)
        print("还原成功")


    def update(self):
        #这是一个准备用来修改日记的函数
        #可以大胆运用你在本节课中学习的知识，结合我们前边学过的循环和条件判断，来实现修改日记的功能
        #这里我先提供一点小提示
        #1.可以参考write函数
        #2.直接全改的话，貌似在我们实际使用过程中不会太方便，可不可以一行一行的改呢？
        #3.在实在想不出来怎么写的时候，不要忘记考虑我们自定义的模块
        pass

def run():
    while 1:
        print("欢迎使用个人日志系统")
        print("1.登录")
        print("2.注册")
        print("3.退出")
        print("请输入你的选择：")
        choice = input()
        login_user = LogIn("")
        #这里的login_user是LogIn类的实例化对象，用来处理登录和注册的功能
        if choice == "1":
            note = Note(login_user.login())
            #这里的note是Note类的实例化对象，用来处理写日记、读日记、修改日记的功能
            if note.name == None:
                #如果note.name为空，则表示用户没有登录，就继续循环
                continue
            while 1:
                print("1.写日志")
                print("2.读日志")
                print("3.修改日记")
                print("4.备份")
                print("5.恢复")
                print("6.退出")


                choice = input()
                if choice in note.Note_operation:
                    note.Note_operation[choice]()
                    #这里通过键值来调用对应的操作函数
                elif choice == "6":
                    print("退出成功")
                    break
                else:
                    print("输入有误，请重新输入")

        elif choice == "2":
            login_user.register()
        elif choice == "3":
            print("感谢使用个人日志系统")
            exit()
        else:
            print("输入有误，请重新输入")
#注意:这里的主函数是不能直接运行的，需要移步到run文件中运行


