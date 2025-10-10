# name = input("请输入虚拟小助手的名字: ")  # 提示用户输入虚拟小助手的名字
# age = int(input("请输入年龄(数字)/岁: "))  # 提示用户输入年龄，并将输入的字符串转换为整数类型
# weight = float(input("请输入体重(可以有小数)/kg: "))  # 提示用户输入体重，并将输入的字符串转换为浮点数类型
# is_online = input("是否在线 (True/False): ").lower() == "true"  # 提示用户输入是否在线，并将输入的字符串转换为布尔值
# print("\n虚拟宠物或小助手信息:")
# print(f"名字: {name}")
# print(f"年龄: {age} 岁")
# print(f"体重: {weight} 公斤")
# print(f"是否在线: {is_online}")


friends = []  # 创建一个空列表，用于存储好友信息
num_friends = int(input("请输入好友数量: "))  # 获取用户输入的好友数量
for i in range(num_friends):  # 循环遍历每个好友
    print(f"第 {i + 1} 个好友:")  # 打印当前好友的序号
    friend_name = input("好友名称: ")  # 获取用户输入的好友名称
    contact_info = input("好友联系方式: ")  # 获取用户输入的好友联系方式
    friend = {              # 创建字典，表示一个好友
        "name": friend_name,  # 好友名称
        "contact_info": contact_info  # 好友联系方式
    }
    friends.append(friend)  # 将该好友添加到好友列表中

print("\n好友列表:")
for friend in friends:
    print(f"名字: {friend['name']}, 联系方式: {friend['contact_info']}")
