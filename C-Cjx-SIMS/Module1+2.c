#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2000

typedef struct {
    char name[50];
    int age;
    char sex[2];
    char major[50];
} Student;

Student students[MAX];
int number = 0;

void add_student() {
    Student a;
    printf("请输入姓名: ");
    scanf("%d", &a.name);
    printf("请输入年龄: ");
    scanf("%s", &a.age);
    printf("请输入性别: ");
    scanf("%s", &a.sex);
    printf("请输入专业: ");
    scanf("%s", &a.major);
    students[number++] = a;
    printf("信息添加成功！\n");
}

void display_students() {
	int i; 
    if (number == 0) {
        printf("无学生信息可显示！\n");
        return;
    }
    printf("姓名\t年龄\t性别\t专业\n");
    for (i = 0; i < number; i++) {
        printf("%s\t%d\t%s\t%s\n", students[i].name, students[i].age, students[i].sex, students[i].major);
    }
}

void menu() {
    printf("\n=== 学生信息管理系统 ===\n");
    printf("1. 添加学生信息\n");
    printf("2. 修改学生信息\n");
    printf("3. 删除学生信息\n");
    printf("4. 查询学生信息\n");
    printf("5. 显示所有学生信息\n");
    printf("6. 保存学生信息到文件\n");
    printf("7. 从文件加载学生信息\n");
    printf("0. 退出系统\n");
}

int main() {
    int a;
    do {
        menu();
        printf("请选择操作: ");
        scanf("%d", &a);
        switch (a) {
            case 1:
                add_student();
                break;
            /*case 2:
                change_students();
                break;
            case 3:
            	delete_students();
            	break;
			case 4:
				search_students();
				break;*/
			case 5:
				display_students(); 
				break;
			/*case 6:
				save_students();
				break;
			case 7:
				run_message();
				break;*/
            case 0:
                printf("退出系统！\n");
                break;
            default:
                printf("无效的选择，请重新选择！\n");
        }
    } while (a != 0);

    return 0;
}

