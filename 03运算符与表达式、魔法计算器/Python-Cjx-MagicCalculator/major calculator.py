print('~~~~~~~~~~欢迎来到魔法口袋计算器~~~~~~~~~~')
print('~~~~~~~~~~~~~~~我们的魔法咒语有：~~~~~~~~~~~~~~~')
print ("1.加法魔法\n2.减法魔法\n3.乘法魔法\n4.除法魔法\n5.等于魔法\n6.不等于魔法\n7.小于魔法\n8.大于魔法")
while True:
    operand1 = float(input("请输入第一个数字："))
    operand2 = float(input("请输入第二个数字："))
    operator = input("请输入魔法咒语：")
    if operator == '加法魔法':
        result = operand1 + operand2
        print(result)
    if operator == '减法魔法':
        result = operand1 - operand2
        print(result)
    if operator == '乘法魔法':
        result = operand1 * operand2
        print(result)
    if operator == '除法魔法':
        if operand2 == 0:
            print('除数不能为0')
        else:
            result = operand1 / operand2
            print(result)
    if operator == '大于魔法':
        if operand1 > operand2:
            print(str(operand1) + '大于' + str(operand2))
        else:
            print(str(operand1) + '不大于' + str(operand2))
    if operator == '小于魔法':
        if operand1 < operand2:
            print(str(operand1) + '小于' + str(operand2))
        else:
            print(str(operand1) + '不小于' + str(operand2))
    if operator == '等于魔法':
        if operand1 == operand2:
            print(str(operand1) + '等于' + str(operand2))
        else:
            print(str(operand1) + '不等于' + str(operand2))
    if operator == '不等于魔法':
        if operand1 != operand2:
            print(str(operand1) + '不等于' + str(operand2))
        else:
            print(str(operand1) + '等于' + str(operand2))
    print("~~~~~~~~~~输入数字1继续程序~~~~~~~~~~")
    print("~~~~~~~~~~输入除1外任意字符退出程序~~~~~~~~~~")
    if input()!='1':
        break