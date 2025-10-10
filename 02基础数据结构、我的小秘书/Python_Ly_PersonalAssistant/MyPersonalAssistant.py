# 导入datetime模块来处理日期和时间
import datetime


# 定义一个Pet类，可以想象成一个虚拟的小助手或宠物
class Pet:
    # 初始化函数，用来设置小助手的基本属性
    def __init__(self, name, age, weight, is_online):
        self.name = name  # 名字，用字符串（str）类型来存储
        self.age = age  # 年龄，用整数（int）类型来存储
        self.weight = weight  # 体重，用浮点数（float）类型来存储
        self.is_online = is_online  # 是否在线，用布尔值（bool）类型来存储
        self.friends = []  # 朋友列表，用列表（list）来存储朋友的信息

    # 添加朋友的方法
    def add_friend(self, friend_name, contact_info):
        # 创建一个字典来存储朋友的名字和联系方式
        friend = {
            "name": friend_name,  # 朋友的名字
            "contact_info": contact_info  # 朋友的联系方式
        }
        self.friends.append(friend)  # 将朋友的信息添加到朋友列表中

    # 将年龄数字转换成字符串的方法
    def age_to_string(self):
        return str(self.age)  # 使用str()函数将年龄转换为字符串


# 创建虚拟小助手
# 让孩子们通过输入来创建他们自己的小助手
name = input("请输入虚拟小助手的名字: ")
age = int(input("请输入年龄(数字)/岁: "))  # 使用int()函数将输入的字符串转换为整数
weight = float(input("请输入体重(可以有小数)/kg: "))  # 使用float()函数将输入的字符串转换为浮点数
is_online = input("是否在线 (True/False): ").lower() == "true"  # 将输入的字符串转换为布尔值

# 使用提供的信息创建Pet类的实例
pet = Pet(name, age, weight, is_online)

# 添加好友
# 让孩子们输入他们小助手的朋友数量，并为每个朋友输入名字和联系方式
num_friends = int(input("请输入好友数量: "))
for i in range(num_friends):
    print(f"第 {i + 1} 个好友:")
    friend_name = input("好友名称: ")
    contact_info = input("好友联系方式: ")
    pet.add_friend(friend_name, contact_info)

# 显示虚拟小助手的信息
# 将小助手的信息打印出来，让孩子们看到他们创造的小助手
print("\n虚拟宠物或小助手信息:")
print(f"名字: {pet.name}")
print(f"年龄: {pet.age_to_string()} 岁")
print(f"体重: {pet.weight} 公斤")
print(f"是否在线: {pet.is_online}")

# 显示好友列表
# 将小助手的朋友列表打印出来
print("\n好友列表:")
for friend in pet.friends:
    print(f"名字: {friend['name']}, 联系方式: {friend['contact_info']}")
