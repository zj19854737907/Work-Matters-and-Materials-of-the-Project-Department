import random

# 根据玩家选择采取不同的路径和使用控制流工具的代码

print("欢迎来到魔法迷宫！你是一名勇敢的探险者。")

# 角色选择
while True:
    role = input("请选择你的角色（骑士、巫师、猎人）: ")
    if role in ['骑士', '巫师', '猎人']:
        break
    else:
        print("无效的角色，请重新选择。")

task = input("请问你要穿过这个魔法迷宫是为了干什么呢？")

print(f"原来你来到这里是为了{task}啊，听起来也太棒了吧！！")

print(f"那么勇敢的{role}，现在开始你的冒险之旅！")

# 初始化游戏状态
magic_items_collected = 0
exit_found = False
player_inventory = []

# 这里声明两个变量 表示玩家的健康值 和 龙的健康值
player_health = 100
dragon_health = 50
while magic_items_collected < 3:
    print("\n你来到一个岔路口，你要选择走向哪个方向？ 小提示：勇于尝试不同的道路哦~~")
    direction = input("左边（left）右边（right） ")

    # 如果选择的是向左走，会随机碰到巫师（获得药水）；遇到陷阱（失去健康值）
    if direction == 'left':
        encounter = random.choice(['善良巫师', '陷阱'])
        if encounter == '善良巫师':
            print("你遇到了一位善良的巫师，他给了你一瓶魔法药水和治疗药水。")
            player_inventory.append('治疗药水')
            magic_items_collected += 1
        elif encounter == '陷阱':
            print("哎呀！这是个陷阱！你失去了15点健康值。")
            player_health -= 15
            print(f"\n你的健康值: {player_health}")

    # 向右走会碰到龙，玩家会与龙展开战斗
    elif direction == 'right':
        while player_health > 0 and dragon_health > 0:

            print("\n你遇到了一条恶龙！一场激烈的战斗就此展开！")
            action = input("你要使用魔法攻击（magic）、普通攻击（attack）、"
                           "使用治疗药水（item）还是进行防御（defend）？: ")
            if action == 'magic':
                print("你使用了魔法攻击，造成20点伤害！")
                dragon_health -= 20
            elif action == 'attack':
                print("你发起了普通攻击，造成10点伤害。")
                dragon_health -= 10
            elif action == 'item':
                if '治疗药水' in player_inventory:
                    print("你使用了治疗药水，恢复了20点健康值。")
                    player_health += 20
                    player_inventory.remove('治疗药水')
                else:
                    print("你没有治疗药水，无法使用道具，由于耽误了时间，只能被攻击了。")
            elif action == 'defend':
                print("你选择进行防御，减少了龙的伤害。")
                player_health += 10
            else:
                print("无效的行动，请重新选择。")

            # 龙的反击
            print("龙发起了反击，造成15点伤害！")
            player_health -= 15

            # 显示战斗状态
            print(f"\n你的健康值: {player_health}")
            print(f"龙的健康值: {dragon_health}")

        # 判断战斗结果
        if player_health > 0:
            print("你成功战胜了龙！")
        else:
            print("很遗憾，你被龙击败了。")

    else:
        print("请问你要走到哪里去呀？重新选择一下吧~")

    # 检查玩家是否已经收集到足够的魔法物品
    if magic_items_collected >= 3:
        print("你已经找到了3瓶魔法药水!此时岔路口在魔法药水的作用下消失了！\n")
    else:
        print("继续探险，寻找更多的魔法物品。")

print("此时你的眼前出现了障碍物！需要你使用魔法药水将它们移开！")
score = 0
obstacles = ["tree", "rock", "fire"]

# 随机打乱障碍物的顺序
random.shuffle(obstacles)

while score < 3 and obstacles:
    obstacle = obstacles.pop(0)
    print(f"你面前的障碍物是一个{obstacle}。")

    # 给玩家三次机会说出正确的咒语
    for attempt in range(3):
        words = input(f"第{attempt+1}次尝试，快说出魔法咒语来消除障碍{obstacle}："
                      f"（咒语例子：如“fire消失吧！”）")
        if words == f"{obstacle}消失吧！":
            print("看！眼前的障碍物消失了!")
            score += 1
            break
        else:
            print("咒语似乎不对哦，再试一次吧！")

    # 如果三次都没说对，游戏变得更具挑战性
        if attempt == 2 and words != f"{obstacle}消失吧！":
            print(f"很遗憾，你没有成功消除{obstacle}，它变得更大了！")
            obstacles.append(obstacle)  # 将障碍物重新加入列表
            random.shuffle(obstacles)  # 重新打乱障碍物顺序

if score == 3:
    print("恭喜移开了所有障碍物！你成功找到了迷宫的出口，完成了冒险之旅。")
else:
    print("\n很遗憾，你没有成功移开所有障碍物。")
