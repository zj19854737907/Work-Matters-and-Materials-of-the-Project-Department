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
            printf("提示：图书库已满（最多存储%d本），无法继续添加！\n", maxCount);
            break;
        }

       
        printf("\n----- 输入第%d本图书信息 -----\n", currentCount + 1);

        
        printf("图书编号（不超过19字符）：");
        if (scanf("%19s", library[currentCount].id, (unsigned)_countof(library[currentCount].id)) != 1) {
            printf("输入错误！请重新输入\n");
            clearInputBuffer();  
            continue;
        }
        clearInputBuffer();  

        
        printf("图书名称（不超过49字符）：");
        if (fgets(library[currentCount].name, sizeof(library[currentCount].name), stdin) == NULL) {
            printf("输入错误！请重新输入\n");
            clearInputBuffer();
            continue;
        }
        
        size_t len = strlen(library[currentCount].name);
        if (len > 0 && library[currentCount].name[len - 1] == '\n') {
            library[currentCount].name[len - 1] = '\0';
        }

       
        printf("作者（不超过29字符）：");
        if (fgets(library[currentCount].author, sizeof(library[currentCount].author), stdin) == NULL) {
            printf("输入错误！请重新输入\n");
            clearInputBuffer();
            continue;
        }
        len = strlen(library[currentCount].author);
        if (len > 0 && library[currentCount].author[len - 1] == '\n') {
            library[currentCount].author[len - 1] = '\0';
        }

        
        printf("图书价格：");
        if (scanf("%f", &library[currentCount].price) != 1) {
            printf("输入错误！请输入数字\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

       
        printf("库存数量：");
        if (scanf("%d", &library[currentCount].stock) != 1) {
            printf("输入错误！请输入整数\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        
        currentCount++;

        
        printf("\n是否继续添加图书？(y/n)：");
        if (scanf("%c", &choice, 1) != 1) {
            printf("输入错误，默认结束添加\n");
            break;
        }
        clearInputBuffer();  

    } while (choice == 'y' || choice == 'Y');

    
    printf("\n================================ 图书库存信息 ================================\n");
    printf("%-10s %-25s %-15s %-10s %-8s\n", "编号", "名称", "作者", "价格（元）", "库存");
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

