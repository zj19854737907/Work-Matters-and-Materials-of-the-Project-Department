#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define MAJOR_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    char gender; 
    char major[MAJOR_LENGTH];
} Student;


Student students[MAX_STUDENTS];
int student_count = 0;


void searchStudentByName() {
    char name[NAME_LENGTH];
    printf("请输入要查找的学生姓名: ");
    scanf("%s", name);
    
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("找到学生信息:\n");
            printf("姓名: %s\n年龄: %d\n性别: %c\n专业: %s\n", students[i].name, students[i].age, students[i].gender, students[i].major);
            return;
        }
    }
    printf("未找到学生: %s\n", name);
}


void saveStudentsToFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("无法打开文件");
        return;
    }
    fwrite(students, sizeof(Student), student_count, file);
    fclose(file);
    printf("学生信息已保存到文件 %s\n", filename);
}

int main() {
    int choice;
    while (1) {
        printf("\n学生管理系统\n");
        printf("1. 查找学生信息\n");
        printf("2. 保存学生信息到文件\n");
        printf("0. 退出\n");
        printf("请选择操作: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                searchStudentByName();
                break;
            case 2:
                saveStudentsToFile("students.dat");
                break;
            case 0:
                exit(0);
            default:
                printf("无效选项，请重新选择。\n");
        }
    }
    return 0;
}
