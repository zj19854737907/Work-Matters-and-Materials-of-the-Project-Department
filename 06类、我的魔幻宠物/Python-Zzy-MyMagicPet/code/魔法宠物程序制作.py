#"我的魔幻宠物"
#目的：通过编程创建和自己互动的虚拟宠物，学习类的一些基本概念和用法
'''现在请发挥你的想象力，把自己想象成一位宠物店的小魔法师，
    现在你的工作是创造一些讨客人喜欢的魔幻宠物
    可以是 传说中美丽的独角兽，那一定会让没见过独角兽的客人大吃一惊
    但在这之前，我们需要学习一些魔法咒语（代码）
'''
#1.定义类
'''首先，包括独角兽在内的所有魔幻宠物都需要先有个模型
    ，然后才能在这个模型的基础上去发挥想象力补充这个模型的具体细节
    所以这个模型的创建，即类的定义，是十分很重要的
    在这个过程中，我们需要使用第一条咒语"class",然后加上这个类的名称''' 
class MyMagicPet:
    #2.定义属性
    '''
    在类的下面给出魔幻宠物的基本属性：可以思考一下你要创建的一大群的宠物
    会有的共同的特点，都会有名字，年龄等等，这里的答案很多，可以按照你的喜好
    把它补充得更完整
    '''
    name = ""#名字
    age = 0#年龄
    gender = ""#性别
    color = ""#颜色
    #3.定义方法
    '''
    接下来我们可以用”函数咒语“来实现我们想要对宠物进行的操作
    比如选择他们的属性（例如：给他们取名，决定他们的性别），
    还可以给它们喂食，跟他们玩耍等等'''
    def __init__(self, name, age, gender, color):
        '''
        这个函数咒语可帮助我们定义一些创造出来的小动物可以改变的属性
        这个过程也称为初始化(要记得写self)
        '''
        self.name = name
        self.age = age
        self.gender = gender
        self.color = color
        self.physicalCondition = "健康的"
        self.mentalCondition = "快乐的"
        self.degree = 0
        self.container = 0
    def show_info(self):
        print(f"{self.name}的年龄是{self.age}岁，性别是{self.gender}，颜色是{self.color}")
        print(f"状态是{self.physicalCondition}和{self.mentalCondition},等级是{self.degree}")
    def feed_pet(self):
        '''
        这是一个喂宠物的函数咒语，
        根据宠物的健康状态进行不同的操作，
        喂食成功会改变宠物的状态并升级宠物，
        喂食失败则输出失败信息
        '''
        if self.physicalCondition == "健康的":
            print("喂食成功，你的宠物打了一个很响的饱嗝")
            self.physicalCondition = "饱食的"
            self.upgrade_pet()
        elif self.physicalCondition == "饥饿的":
            print("喂食成功，你的宠物蹭着你的腿表示感谢")
            self.physicalCondition = "健康的"
            self.upgrade_pet()
        else:
            print("喂食失败")
            print(f"{self.name}现在状态是{self.physicalCondition}")
            print("无法继续获取经验，需要玩耍")
        if self.mentalCondition == "疲劳的":
            self.mentalCondition = "快乐的"
        print(f"{self.name}现在状态是{self.physicalCondition}和{self.mentalCondition}")
    def play_with_pet(self):
        '''
        这个函数咒语根据宠物的身心状态决定是否可以和宠物玩耍，
        并根据结果更新宠物的状态信息。

        '''
        if self.physicalCondition != "饥饿的" and self.mentalCondition == "快乐的":
            print("跟他玩耍成功")
            self.mentalCondition = "兴奋的"
            print(f"{self.name}现在状态是{self.mentalCondition}")
            self.upgrade_pet()
        elif self.physicalCondition != "饥饿的" and self.mentalCondition == "兴奋的":
            print("跟他玩耍成功")
            self.mentalCondition = "疲劳的"
            self.physicalCondition = "饥饿的"
            self.upgrade_pet()
        else:
            print("跟他们玩耍失败")
            print(f"{self.name}现在状态是{self.mentalCondition}")
            print("无法继续获取经验，需要喂食")
        print(f"{self.name}现在的状态是{self.physicalCondition}和{self.mentalCondition}")
    def roll_over(self):
        '''这是一个简单的让宠物执行翻滚动作的函数咒语'''
        if self.degree >= 2:
            print("宠物翻滚成功")
            self.upgrade_pet()
        else:
            print("宠物翻滚失败")
            print(f"宠物{self.name}的等级是{self.degree},需要达到2级才能翻滚")
    def upgrade_pet(self):
        '''这个函数咒语可就厉害了，它能实现我们在游戏中经常看到的角色升级功能
            那它的操作思路是怎么样的呢
            1，首先，得用到上面初始化的存储经验的容器self.container
            在执行一次可以加经验的行为的时候，容器里的经验值加1，
            2.然后我们给这个容器一个上限：5
            然后用if咒语来判断容器在加经验后是否满了
            要是满了，就升一级，同时把容器里的经验清零，
            然后就能实现这个升级功能啦'''
        self.container = self.container + 1
        print(f"宠物{self.name}经验值加一，离升下一级还差{5 - self.container}点经验值")
        if self.container == 5:
            self.degree = self.degree + 1
            print(f"恭喜你的宠物{self.name}成功升到{self.degree}级")
            self.container = 0

'''
    class咒语还有另一种作用，叫做"继承"，就是传承基本的宠物类的各种属性及方法（也就是函数）
    在继承的过程中，你也可以根据你所希望对宠物进行的操作来进行属性和方法的修改或增加'''

class Dragon(MyMagicPet):
    def __init__(self, name, age, gender, color,tech):
        super().__init__(name, age, gender, color)
        #子类继承上面的父类，当然可以继承父类的属性和方法，当我们在调用时，还需用到另一条咒语：super()
        #在子类的基础上，我们可以添加一些独特的属性和方法
        self.size = "大型"
        self.strength = "强大"
        self.speed = "飞快"
        self.tech = tech
    def magic_transform(self):
        #这是一个简单的用来换技能的函数咒语，它会根据宠物的等级来判断是否可以进行技能转换
        if self.tech == "技能1":
            if self.degree <= 4:
                print("技能转换失败")
                print(f"宠物{self.name}的等级是{self.degree},需要达到5级才能转换")
            else:
                print("技能转换成功")
            self.tech = "技能2"
            print("技能转换成功")
        elif self.tech == "技能2":
            self.tech = "技能1"
            print("技能转换成功")
    def use_tech(self):
        #当然，既然我们创建的是魔幻宠物，那就得有些其他的的普通宠物没有的特点，
        # 比如，它可以用技能，这是一个用来使用技能的函数咒语，在里边判断宠物所持有的技能
        # 然后根据技能的效果来进行相应的操作
        if self.tech == "技能1":
            print("技能1使用成功")
            if self.physicalCondition == "饥饿的" or self.mentalCondition == "疲劳的":
                print(f"你的宠物{self.name}向前喷射了一小团小小的火焰，")
            else:
                print(f"你的宠物{self.name}向前喷射了一团巨大的火焰")
                self.physicalCondition = "饥饿的"
                self.mentalCondition = "疲劳的"
                self.upgrade_pet()
        elif self.tech == "技能2":
            print("技能2使用成功")
            if self.physicalCondition == "饥饿的" or self.mentalCondition == "疲劳的":
                print(f"你的宠物{self.name}向前刮起了一阵人畜无害的微风")
                self.upgrade_pet()
            else:
                print(f"你的宠物{self.name}将会向前刮起一阵毁灭性的龙卷风")
                choice = input("你要继续使用技能吗？(y/n)")
                if choice == "y":
                    print(f"你的宠物{self.name}向前刮起了一阵毁灭性的龙卷风")
                    print("很好，在一流魔法师店长的及时的救助下，魔法宠物店有幸没有化为废墟")
                    print("所谓大难不死必有后福，在使用了这一强力技能后，你的宠物获得了大量经验")
                    for i in range(10):
                        self.upgrade_pet()
                    print(f"现在你的宠物{self.name}的等级是{self.degree}")
                elif choice == "n":
                    print("你选择了不使用技能")
                else:
                    print("你输入了错误的选项,请在“n，y”中选一")

    def show_func(self):
        print("我是一个大型的火焰龙，我有着强大的力量，我飞快地移动")
        print(f"现在我能使用的技能是{self.tech}")
class Unicorn(MyMagicPet):
    def __init__(self, name, age, gender, color,tech):
        super().__init__(name, age, gender, color)
        self.size = "中型"
        self.strength = "壮实"
        self.speed = "飞速"
        self.tech = tech
    def show_func(self):
        print("我是一个中型的独角兽，我有着强大的力量，我飞速地移动")

#在完成上述的类的定义和继承后，我们就做足施展魔法的准备了，下面请尽情施展魔法吧！
#比如创建一个Dragon类的对象怎么样？

#比如对它进行操作怎么样？

#比如对它进行升级怎么样？

#再比如，做些更厉害的事，去发挥想象力去补充下独角兽类？

#勇敢地去试试吧！

