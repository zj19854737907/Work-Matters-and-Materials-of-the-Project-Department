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
    printf("����������: ");
    scanf("%d", &a.name);
    printf("����������: ");
    scanf("%s", &a.age);
    printf("�������Ա�: ");
    scanf("%s", &a.sex);
    printf("������רҵ: ");
    scanf("%s", &a.major);
    students[number++] = a;
    printf("��Ϣ��ӳɹ���\n");
}

void display_students() {
	int i; 
    if (number == 0) {
        printf("��ѧ����Ϣ����ʾ��\n");
        return;
    }
    printf("����\t����\t�Ա�\tרҵ\n");
    for (i = 0; i < number; i++) {
        printf("%s\t%d\t%s\t%s\n", students[i].name, students[i].age, students[i].sex, students[i].major);
    }
}

void menu() {
    printf("\n=== ѧ����Ϣ����ϵͳ ===\n");
    printf("1. ���ѧ����Ϣ\n");
    printf("2. �޸�ѧ����Ϣ\n");
    printf("3. ɾ��ѧ����Ϣ\n");
    printf("4. ��ѯѧ����Ϣ\n");
    printf("5. ��ʾ����ѧ����Ϣ\n");
    printf("6. ����ѧ����Ϣ���ļ�\n");
    printf("7. ���ļ�����ѧ����Ϣ\n");
    printf("0. �˳�ϵͳ\n");
}

int main() {
    int a;
    do {
        menu();
        printf("��ѡ�����: ");
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
                printf("�˳�ϵͳ��\n");
                break;
            default:
                printf("��Ч��ѡ��������ѡ��\n");
        }
    } while (a != 0);

    return 0;
}

