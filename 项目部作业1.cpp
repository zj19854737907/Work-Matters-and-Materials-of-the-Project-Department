#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char isbn[20];
    bool is_borrowed;
}Book;
typedef struct 
{
    Book books[MAX_BOOKS];
    int count;
}Library;
void initLibrary(Library *lib);
void addBook(Library *lib,const char *title,const char *author,const char *isbn);
void listBooks(Library *lib);
bool borrowBook(Library *lib,const char *title);
bool returnBook(Library *lib,const char *title);
void generateReport(Library *lib);
int findBookByTitle(Library *lib,const char *title);

int main(){
    Library library;
    initLibrary(&library);
    addBook(&library,"魔女之旅", "白石定规","1999");
    addBook(&library,"无职转生","是讲理不求人","2014");
    addBook(&library,"一拳超人","ONE","001");
    addBook(&library,"电锯人","藤本树","2018");
    
    int choice;
    char title[MAX_TITLE_LENGTH];
    printf("===图书管理系统===\n");

    while(1){
        printf("\n请选择操作:\n");
        printf("1.显示所有图书\n");
        printf("2.借阅图书\n");
        printf("3.归还图书\n");
        printf("4.生成统计报告\n");
        printf("5.退出系统\n");
        printf("请输入选择(1-5):");

        scanf("%d",&choice);
        getchar();

    switch (choice)
    {
    case 1:
        listBooks(&library);
        break;
    
    case 2:
        printf("请输入要借阅的图书书名:");
        fgets(title,MAX_TITLE_LENGTH,stdin); 
        title[strcspn(title,"\n")] = 0;

        if(borrowBook(&library,title)){
            printf("成功借阅《%s》! \n",title);
        }else{
            printf("借阅失败!图书不存在或已被借出。\n");
        }
        break;
        case 3:
            printf("请输入要归还的图书书名:");
            fgets(title,MAX_TITLE_LENGTH,stdin);
            title[strcspn(title,"\n")] = 0;

            if(returnBook(&library,title)){
                printf("成功归还《%s》!\n",title);
            }else{
                printf("归还失败!图书不存在或未被借出。\n");
            }
            break;
        case 4:
            generateReport(&library);
            break;
        case 5:
            printf("感谢使用图书管理系统!\n");
            return 0;        
    default:
        printf("无效选择,请重新输入!\n");
    
    }
    }

    return 0;
}
void initLibrary(Library *lib){
    lib->count = 0;    
}
void addBook(Library *lib, const char *title,const char *author,const char *isbn){
    if(lib->count >= MAX_BOOKS){
        printf("图书馆已满，无法添加更多图书!\n");
        return;
    }
    Book *book = &lib->books[lib->count];
    strcpy(book->title,title);
    strcpy(book->author,author);
    strcpy(book->isbn,isbn);
    book->is_borrowed = false;

    lib->count++;
    printf("已添加图书:《%s》\n",title);
}

void listBooks(Library *lib){
    printf("\n=== 图书列表 ===\n");
    printf("%-3s %-20s %-15s %-10s\n","序号","书名","作者","状态");
    printf("------------------------------------------------\n");

    for(int i = 0;i < lib->count;i++){
        Book *book = &lib->books[i];
        const char *status = book->is_borrowed?"已借出" : "可借";
        printf("%-3d %-20s %-15s %-10s\n",
        i + 1,book->title,book->author,status);
}
printf("-------------------------------------------------\n");
}
int findBookByTitle(Library *lib,const char *title){
    for (int i =0;i<lib->count;i++){
        if(strcmp(lib->books[i].title,title) == 0){
            return i;
        }
    }
    return -1;
}
bool borrowBook(Library *lib,const char *title){
    int index =findBookByTitle(lib,title);
    if(index == -1){
        return false;
    }

    Book *book = &lib->books[index];
    if(book->is_borrowed){
        return false;
    }

    book->is_borrowed = true;
        return true;
}
bool returnBook(Library *lib,const char *title){
    int index = findBookByTitle(lib,title);
    if(index == -1){
        return false;
    }

    Book *book = &lib->books[index];
    if(book->is_borrowed){
        return false;
    }
   
    book->is_borrowed = false;
    return true;
}
void generateReport(Library *lib){
    int total = lib->count;
    int available = 0;
    int borrowed = 0;

    for(int i = 0;i < lib->count;i++){
        if(!lib->books[i].is_borrowed){
            available++;
        }else{
            borrowed++;
        }
    }
    printf("\n=== 图书统计报告 ===\n");
    printf("图书总数量:%d 本\n",total);
    printf("可借图书数量:%d 本\n",available);
    printf("已借出图书数量:%d 本\n",borrowed);
    printf("=========================\n");
}

