import random


def number_bomb():
    # 设置游戏范围和炸弹数字
    min_number = 1
    max_number = 20
    bomb_number = random.randint(min_number, max_number)

    # 初始化猜测次数计数器
    guess_count = 0

    print(f"小朋友们，欢迎来到数字炸弹游戏！只有用炸弹才能打开迷宫的大门哟！")
    print(f"请在 {min_number} 到 {max_number} 之间选择一个数字，猜猜它是不是炸弹。")

    while True:
        try:
            # 获取玩家输入
            guess = int(input("请输入你猜测的炸弹: "))

            # 猜测次数计数器
            guess_count += 1

            # 检查玩家输入是否在所给范围内
            if guess < min_number or guess > max_number:
                print(f"请输入一个 {min_number} 到 {max_number} 之间的数字。")
                continue

            # 检查是否猜中炸弹数字
            if guess == bomb_number:
                print(f"你用了 {guess_count} 次就猜中炸弹啦！")
                print("轰！炸弹成功将魔法迷宫的大门炸开啦！！")
                break
            elif guess < bomb_number:
                print("你猜的数字比炸弹数字小，再试一次！")
            else:
                print("你猜的数字比炸弹数字大，再试一次！")

        except ValueError:
            print("请输入一个整数哟！")


if __name__ == "__main__":
    number_bomb()
