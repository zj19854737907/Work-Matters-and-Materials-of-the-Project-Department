#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// 定义学生结构体
struct Student {
    char name[NAME_LENGTH];
    int age;
    float score;
};

// 函数声明
void addStudent(struct Student students[], int *count);
void modifyStudent(struct Student students[], int count);
void displayStudents(const struct Student students[], int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        // 显示菜单
        printf("\n学生信息管理系统\n");
        printf("1. 添加学生\n");
        printf("2. 修改学生信息\n");
        printf("3. 显示所有学生信息\n");
        printf("4. 退出\n");
        printf("请选择一个选项: ");
        scanf("%d", &choice);
        getchar(); // 清除输入缓冲区中的换行符

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                modifyStudent(students, studentCount);
                break;
            case 3:
                displayStudents(students, studentCount);
                break;
            case 4:
                printf("退出系统\n");
                return 0;
            default:
                printf("无效选项，请重新选择\n");
        }
    }

    return 0;
}

// 添加学生信息
void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("学生数量已满，无法添加更多学生\n");
        return;
    }
    printf("请输入学生姓名: ");
    fgets(students[*count].name, NAME_LENGTH, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = 0; // 去除换行符

    printf("请输入学生年龄: ");
    scanf("%d", &students[*count].age);
    printf("请输入学生成绩: ");
    scanf("%f", &students[*count].score);
    getchar(); // 清除输入缓冲区中的换行符

    (*count)++;
    printf("学生添加成功\n");
}

// 修改学生信息
void modifyStudent(struct Student students[], int count) {
    char name[NAME_LENGTH];
    printf("请输入要修改的学生姓名: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // 去除换行符

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("找到学生 %s，请输入新年龄: ", students[i].name);
            scanf("%d", &students[i].age);
            printf("请输入新成绩: ");
            scanf("%f", &students[i].score);
            getchar(); // 清除输入缓冲区中的换行符
            printf("学生信息修改成功\n");
            return;
        }
    }
    printf("未找到学生 %s\n", name);
}

// 显示所有学生信息
void displayStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("没有学生信息\n");
        return;
    }

    printf("\n所有学生信息:\n");
    printf("%-20s %-5s %-5s\n", "姓名", "年龄", "成绩");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-5d %-5.2f\n", students[i].name, students[i].age, students[i].score);
    }
}