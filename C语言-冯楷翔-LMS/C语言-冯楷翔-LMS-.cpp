#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Book {
    char id[20];      
    char name[50];    
    char author[30];  
    float price;      
    int stock;       
};


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Book library[10];  
    int maxCount = sizeof(library) / sizeof(struct Book);
    int currentCount = 0;     
    char choice;              

    do {
       
        if (currentCount >= maxCount) {
            printf("��ʾ��ͼ������������洢%d�������޷�������ӣ�\n", maxCount);
            break;
        }

       
        printf("\n----- �����%d��ͼ����Ϣ -----\n", currentCount + 1);

        
        printf("ͼ���ţ�������19�ַ�����");
        if (scanf("%19s", library[currentCount].id, (unsigned)_countof(library[currentCount].id)) != 1) {
            printf("�����������������\n");
            clearInputBuffer();  
            continue;
        }
        clearInputBuffer();  

        
        printf("ͼ�����ƣ�������49�ַ�����");
        if (fgets(library[currentCount].name, sizeof(library[currentCount].name), stdin) == NULL) {
            printf("�����������������\n");
            clearInputBuffer();
            continue;
        }
        
        size_t len = strlen(library[currentCount].name);
        if (len > 0 && library[currentCount].name[len - 1] == '\n') {
            library[currentCount].name[len - 1] = '\0';
        }

       
        printf("���ߣ�������29�ַ�����");
        if (fgets(library[currentCount].author, sizeof(library[currentCount].author), stdin) == NULL) {
            printf("�����������������\n");
            clearInputBuffer();
            continue;
        }
        len = strlen(library[currentCount].author);
        if (len > 0 && library[currentCount].author[len - 1] == '\n') {
            library[currentCount].author[len - 1] = '\0';
        }

        
        printf("ͼ��۸�");
        if (scanf("%f", &library[currentCount].price) != 1) {
            printf("�����������������\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

       
        printf("���������");
        if (scanf("%d", &library[currentCount].stock) != 1) {
            printf("�����������������\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        
        currentCount++;

        
        printf("\n�Ƿ�������ͼ�飿(y/n)��");
        if (scanf("%c", &choice, 1) != 1) {
            printf("�������Ĭ�Ͻ������\n");
            break;
        }
        clearInputBuffer();  

    } while (choice == 'y' || choice == 'Y');

    
    printf("\n================================ ͼ������Ϣ ================================\n");
    printf("%-10s %-25s %-15s %-10s %-8s\n", "���", "����", "����", "�۸�Ԫ��", "���");
    printf("==============================================================================\n");
    for (int i = 0; i < currentCount; i++) {
        printf("%-10s %-25s %-15s %-10.2f %-8d\n",
               library[i].id,
               library[i].name,
               library[i].author,
               library[i].price,
               library[i].stock);
    }

    return 0;
}

