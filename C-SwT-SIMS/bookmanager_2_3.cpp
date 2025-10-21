#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

// 图书状态枚举
typedef enum {
    AVAILABLE,      // 可借阅
    BORROWED        // 已借出
} BookStatus;

// 图书结构体
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float price;
    BookStatus status;
} Book;

// 虚拟数据库 - 初始化一些图书数据
Book virtualDatabase[MAX_BOOKS] = {
    {"C程序设计语言", "Brian Kernighan", 45.50, AVAILABLE},
    {"数据结构与算法", "严蔚敏", 39.80, BORROWED},
    {"深入理解计算机系统", "Randal Bryant", 89.00, AVAILABLE},
    {"百年孤独", "加西亚·马尔克斯", 32.00, AVAILABLE},
    {"三体", "刘慈欣", 28.50, BORROWED},
    {"红楼梦", "曹雪芹", 55.00, AVAILABLE},
    {"活着", "余华", 25.00, BORROWED},
    {"人类简史", "尤瓦尔·赫拉利", 68.00, AVAILABLE},
    {"1984", "乔治·奥威尔", 30.00, AVAILABLE},
    {"围城", "钱钟书", 26.50, BORROWED}
};

int bookCount = 10; // 当前图书数量

// 函数声明
void displayAllBooks();
void searchBookByTitle();
void displayBookInfo(Book book);
char* getStatusText(BookStatus status);
void toLowerCase(char *str);

int main() {
    int choice;
    
    printf("=== 图书管理系统 ===\n");
    printf("虚拟数据库已初始化，包含 %d 本图书\n\n", bookCount);
    
    do {
        printf("\n请选择操作：\n");
        printf("1. 显示所有图书信息\n");
        printf("2. 按书名查找图书\n");
        printf("3. 退出系统\n");
        printf("请输入选择 (1-3): ");
        
        scanf("%d", &choice);
        getchar(); // 清除输入缓冲区
        
        switch(choice) {
            case 1:
                displayAllBooks();
                break;
            case 2:
                searchBookByTitle();
                break;
            case 3:
                printf("感谢使用图书管理系统！\n");
                break;
            default:
                printf("无效选择，请重新输入！\n");
        }
    } while(choice != 3);
    
    return 0;
}

// 显示所有图书信息（表格形式）
void displayAllBooks() {
    printf("\n%-30s %-20s %-10s %-10s\n", 
           "书名", "作者", "价格(元)", "状态");
    printf("------------------------------------------------------------------------\n");
    
    for(int i = 0; i < bookCount; i++) {
        printf("%-30s %-20s %-10.2f %-10s\n", 
               virtualDatabase[i].title,
               virtualDatabase[i].author,
               virtualDatabase[i].price,
               getStatusText(virtualDatabase[i].status));
    }
    printf("------------------------------------------------------------------------\n");
    printf("总计: %d 本图书\n", bookCount);
}

// 按书名查找图书
void searchBookByTitle() {
    char searchTitle[MAX_TITLE_LENGTH];
    int found = 0;
    
    printf("\n请输入要查找的书名: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    
    // 去除换行符
    searchTitle[strcspn(searchTitle, "\n")] = 0;
    
    if(strlen(searchTitle) == 0) {
        printf("书名不能为空！\n");
        return;
    }
    
    // 转换为小写以便不区分大小写搜索
    toLowerCase(searchTitle);
    
    printf("\n查找结果：\n");
    printf("------------------------------------------------------------------------\n");
    
    for(int i = 0; i < bookCount; i++) {
        char currentTitle[MAX_TITLE_LENGTH];
        strcpy(currentTitle, virtualDatabase[i].title);
        toLowerCase(currentTitle);
        
        // 检查是否包含搜索关键词
        if(strstr(currentTitle, searchTitle) != NULL) {
            displayBookInfo(virtualDatabase[i]);
            found = 1;
        }
    }
    
    if(!found) {
        printf("未找到包含 \"%s\" 的图书。\n", searchTitle);
    }
    printf("------------------------------------------------------------------------\n");
}

// 显示单本图书的详细信息
void displayBookInfo(Book book) {
    printf("书名: %s\n", book.title);
    printf("作者: %s\n", book.author);
    printf("价格: %.2f 元\n", book.price);
    printf("状态: %s\n", getStatusText(book.status));
    printf("----------------------------------------\n");
}

// 获取状态文本
char* getStatusText(BookStatus status) {
    switch(status) {
        case AVAILABLE: return "可借阅";
        case BORROWED: return "已借出";
        default: return "未知状态";
    }
}

// 将字符串转换为小写
void toLowerCase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
