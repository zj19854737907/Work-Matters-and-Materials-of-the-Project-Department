//模块2:显示所有图书信息
//模块6:借阅与归还操作
#include<stdio.h>
#include<string.h>
#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 30

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    float price;
    int status;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void initializeBooks();
void displayAllBooks();
void borrowBook();
void returnBook();
void showMenu();

int main() {
    initializeBooks();
    int choice;
    do {
        showMenu();
        printf("请选择操作(1-4):");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            displayAllBooks();
            break;

        case 2:
            borrowBook();
            break;

        case 3:
            returnBook();
            break;

        case 4:
            printf("谢谢使用！\n");
            break;

        default:
            printf("无效选择，请重新输入！\n");
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}

void initializeBooks() {
    strcpy(library[0].title, "C程序设计语言");
    strcpy(library[0].author, "Brian W. Kernighan");
    library[0].price = 45.0;
    library[0].status = 0;

    strcpy(library[1].title, "数据结构与算法分析");
    strcpy(library[1].author, "Mark Allen Weiss");
    library[1].price = 68.5;
    library[1].status = 1;

    strcpy(library[2].title, "深入理解计算机系统");
    strcpy(library[2].author, "Randal E. Bryant");
    library[2].price = 89.0;
    library[2].status = 0;

    strcpy(library[3].title, "算法导论");
    strcpy(library[3].author, "Thomas H. Cormen");
    library[3].price = 128.0;
    library[3].status = 0;

    bookCount = 4;
}

//模块2
void displayAllBooks() {
    printf("\n————————————————————————————————————————\n");
    printf("                    图书信息列表\n");
    printf("————————————————————————————————————————\n");
    printf("%-30s %-20s %-8s %-8s\n", "书名", "作者", "价格", "状态");
    printf("————————————————————————————————————————\n");

    for (int i = 0; i < bookCount; i++) {
        printf("%-30s %-20s %-8.1f %-8s\n",
            library[i].title,
            library[i].author,
            library[i].price,
            library[i].status == 0 ? "可借" : "已借出");
    }
    printf("————————————————————————————————————————\n");
}

//模块6
void borrowBook() {
    char bookTitle[TITLE_LEN];
    printf("请输入要借阅的书名：");
    getchar();
    fgets(bookTitle, TITLE_LEN, stdin);
    bookTitle[strcspn(bookTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, bookTitle) == 0) {
            found = 1;
            if (library[i].status == 0) {
                library[i].status = 1;
                printf("成功借阅《%s》! \n", bookTitle);
            }
            else {
                printf("《%s》已被借出，暂时不可借！\n", bookTitle);
            }
            break;
        }
    }
    if (!found) {
        printf("未找到图书《%s》! \n", bookTitle);
    }
}

void returnBook() {
    char bookTitle[TITLE_LEN];
    printf("请输入要归还的书名：");
    getchar();
    fgets(bookTitle, TITLE_LEN, stdin);
    bookTitle[strcspn(bookTitle, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, bookTitle) == 0) {
            found = 1;
            if (library[i].status == 1) {
                library[i].status = 0;
                printf("成功归还《%s》! \n", bookTitle);
            }
            else {
                printf("《%S》未被借出，无需归还! \n", bookTitle);
            }
            break;
        }
    }
    if (!found) {
        printf("未找到图书《%s》! \n", bookTitle);
    }
}
void showMenu() {
    printf("————————————————————————————————————————\n");
    printf("                      图书管理系统\n");
    printf("————————————————————————————————————————\n");
    printf("1. 显示所有图书信息\n");
    printf("2. 借阅图书\n");
    printf("3. 归还图书\n");
    printf("4. 退出系统\n");
    printf("————————————————————————————————————————\n");
}
