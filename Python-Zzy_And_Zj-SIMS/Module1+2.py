def init_students():
    # 初始化学生信息文件，如果文件不存在则创建一个空文件
    with open('students.txt', 'a') as txt:
        pass  # 创建空文件

def read_students():
    # 从文件中读取学生信息，并返回一个学生列表
    students = []
    try:
        with open('students.txt', 'r', encoding='UTF-8') as txt:
            # 以只读模式打开文件
            for line in txt:
                parts = line.strip().split('，')
                # 去除空白及用中文逗号分隔元素
                if len(parts) == 4:
                    name, age, gender, major = parts
                    student = {
                        'name': name,
                        'age': int(age),
                        'gender': gender,
                        'major': major
                    }
                    students.append(student)
                else:
                    print(f"错误：'{line.strip()}' 不符合格式！")
    except FileNotFoundError:
        print("找不到目标文件，将为您创建一个新文件。请写入数据后，重启程序")
        init_students()
        exit()
    return students

while True:
    message = input("是否开始读取文件（1是，2否）：")
    if message == '1':
        students = read_students()
        break
    elif message == '是' or message == '否':
        print("请输入数字！")
        continue
    elif message == '2':
        print("已经退出程序！")
        exit()
    else:
        print("无效输入！")
        continue

# 统计所有学生的总人数
def count_students(students):
    return len(students)

# 统计男女生的人数
def count_gender(students):
    male = sum(1 for student in students if student['gender'] == '男')
    female = sum(1 for student in students if student['gender'] == '女')
    return male, female

# 计算学生的平均年龄
def cal_average_age(students):
    if students:
        total_age = sum(student['age'] for student in students)
        num_students = len(students)
        return total_age / num_students
    else:
        return 0

# 主程序部分
if __name__ == "__main__":
    total_students = count_students(students)
    male, female = count_gender(students)
    average_age = cal_average_age(students)

    print(f"总人数: {total_students}")
    print(f"男生人数: {male}")
    print(f"女生人数: {female}")
    print(f"平均年龄: {average_age:.2f}")