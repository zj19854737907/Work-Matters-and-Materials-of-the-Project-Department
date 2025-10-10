#本节课的重点内容，文件操作
import json
import os
#获取路径
current_directory = os.path.dirname(os.path.abspath(__file__))
#这个函数使用os模块获取当前脚本所在目录的绝对路径，并将其与'user_info'拼接成新的路径。
# 这个函数的目的是获取存放用户信息文件的完整路径
main_file = os.path.join(current_directory, 'user_info')
backup_file = os.path.join(current_directory, 'user_info_backup')


def save_data(user_info,file_directory):
    #实现文件的保存
    name =user_info['user_name']
    #文件不存在则新建，存在清空原有内容
    with open(fr'{file_directory}\{name}.json','w',encoding='utf-8') as f:
    #这是我们要新学的语句，f""是我们学过的格式化输出，那fr"是什么呢？
    #fr""是f""和r""叠加的结果，f""是格式化输出，r""是原始输出（说白了就是不转义）
    #回顾转义的内容，转义其实就是指在字符串中插入特殊字符，比如\n，\t等
    #因为文件的地址中可能包含特殊字符，所以需要转义

    #{file_directory}\{name}.json'是在指定文件地址存储以name为文件名的json文件
    #'w'是写入模式，'w'是写模式，如果文件不存在，则会新建一个文件，如果文件存在，则会清空原有内容
        json.dump(user_info,f)
        #json.dump()函数是将python对象转化为json格式，然后写入文件中
        #json.dump()函数的第一个参数是要转化的对象，第二个参数是要写入的文件，第三个参数是写入文件的编码格式
        #这里我们将user_info对象转化为json格式，然后写入文件中，并使用utf-8编码格式
        #这样就实现了文件的保存
        #json文件的保存格式是json格式，json格式是一种数据交换格式，可以用来存储各种数据
        #文件创建后，我们可以在DB文件夹中的user_info文件夹中看到对应的文件

def get_data(user_name,file_directory):
    user =fr'{file_directory}\{user_name}.json'
    #user表示按用户名查找我们需要的文件地址
    if os.path.exists(user):#判断文件是否存在，存在则返回True
        with open(user,'r',encoding='utf-8') as f:
        #这里的r表示读取模式，'r'是读模式，如果文件不存在，则会报错，所以最好加个异常处理
        #我相信强大的你肯定会写的，试着写一下
        #提示：文件不存在的错误是FileNotFoundError
            user_data = json.load(f)
            #json.load()函数是将json格式的文件转化为python对象，然后返回
            #json.load()函数的第一个参数是要读取的文件，第二个参数是读取文件的编码格式
            #这里我们将读取的文件转化为python对象，并返回
        return user_data
