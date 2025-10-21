#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

// ͼ��״̬ö��
typedef enum {
    AVAILABLE,      // �ɽ���
    BORROWED        // �ѽ��
} BookStatus;

// ͼ��ṹ��
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float price;
    BookStatus status;
} Book;

// �������ݿ� - ��ʼ��һЩͼ������
Book virtualDatabase[MAX_BOOKS] = {
    {"C�����������", "Brian Kernighan", 45.50, AVAILABLE},
    {"���ݽṹ���㷨", "��ε��", 39.80, BORROWED},
    {"�����������ϵͳ", "Randal Bryant", 89.00, AVAILABLE},
    {"����¶�", "�����ǡ������˹", 32.00, AVAILABLE},
    {"����", "������", 28.50, BORROWED},
    {"��¥��", "��ѩ��", 55.00, AVAILABLE},
    {"����", "�໪", 25.00, BORROWED},
    {"�����ʷ", "���߶���������", 68.00, AVAILABLE},
    {"1984", "���Ρ�������", 30.00, AVAILABLE},
    {"Χ��", "Ǯ����", 26.50, BORROWED}
};

int bookCount = 10; // ��ǰͼ������

// ��������
void displayAllBooks();
void searchBookByTitle();
void displayBookInfo(Book book);
char* getStatusText(BookStatus status);
void toLowerCase(char *str);

int main() {
    int choice;
    
    printf("=== ͼ�����ϵͳ ===\n");
    printf("�������ݿ��ѳ�ʼ�������� %d ��ͼ��\n\n", bookCount);
    
    do {
        printf("\n��ѡ�������\n");
        printf("1. ��ʾ����ͼ����Ϣ\n");
        printf("2. ����������ͼ��\n");
        printf("3. �˳�ϵͳ\n");
        printf("������ѡ�� (1-3): ");
        
        scanf("%d", &choice);
        getchar(); // ������뻺����
        
        switch(choice) {
            case 1:
                displayAllBooks();
                break;
            case 2:
                searchBookByTitle();
                break;
            case 3:
                printf("��лʹ��ͼ�����ϵͳ��\n");
                break;
            default:
                printf("��Чѡ�����������룡\n");
        }
    } while(choice != 3);
    
    return 0;
}

// ��ʾ����ͼ����Ϣ�������ʽ��
void displayAllBooks() {
    printf("\n%-30s %-20s %-10s %-10s\n", 
           "����", "����", "�۸�(Ԫ)", "״̬");
    printf("------------------------------------------------------------------------\n");
    
    for(int i = 0; i < bookCount; i++) {
        printf("%-30s %-20s %-10.2f %-10s\n", 
               virtualDatabase[i].title,
               virtualDatabase[i].author,
               virtualDatabase[i].price,
               getStatusText(virtualDatabase[i].status));
    }
    printf("------------------------------------------------------------------------\n");
    printf("�ܼ�: %d ��ͼ��\n", bookCount);
}

// ����������ͼ��
void searchBookByTitle() {
    char searchTitle[MAX_TITLE_LENGTH];
    int found = 0;
    
    printf("\n������Ҫ���ҵ�����: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    
    // ȥ�����з�
    searchTitle[strcspn(searchTitle, "\n")] = 0;
    
    if(strlen(searchTitle) == 0) {
        printf("��������Ϊ�գ�\n");
        return;
    }
    
    // ת��ΪСд�Ա㲻���ִ�Сд����
    toLowerCase(searchTitle);
    
    printf("\n���ҽ����\n");
    printf("------------------------------------------------------------------------\n");
    
    for(int i = 0; i < bookCount; i++) {
        char currentTitle[MAX_TITLE_LENGTH];
        strcpy(currentTitle, virtualDatabase[i].title);
        toLowerCase(currentTitle);
        
        // ����Ƿ���������ؼ���
        if(strstr(currentTitle, searchTitle) != NULL) {
            displayBookInfo(virtualDatabase[i]);
            found = 1;
        }
    }
    
    if(!found) {
        printf("δ�ҵ����� \"%s\" ��ͼ�顣\n", searchTitle);
    }
    printf("------------------------------------------------------------------------\n");
}

// ��ʾ����ͼ�����ϸ��Ϣ
void displayBookInfo(Book book) {
    printf("����: %s\n", book.title);
    printf("����: %s\n", book.author);
    printf("�۸�: %.2f Ԫ\n", book.price);
    printf("״̬: %s\n", getStatusText(book.status));
    printf("----------------------------------------\n");
}

// ��ȡ״̬�ı�
char* getStatusText(BookStatus status) {
    switch(status) {
        case AVAILABLE: return "�ɽ���";
        case BORROWED: return "�ѽ��";
        default: return "δ֪״̬";
    }
}

// ���ַ���ת��ΪСд
void toLowerCase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
