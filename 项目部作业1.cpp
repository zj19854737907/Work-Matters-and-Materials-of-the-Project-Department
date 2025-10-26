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
    addBook(&library,"ħŮ֮��", "��ʯ����","1999");
    addBook(&library,"��ְת��","�ǽ�������","2014");
    addBook(&library,"һȭ����","ONE","001");
    addBook(&library,"�����","�ٱ���","2018");
    
    int choice;
    char title[MAX_TITLE_LENGTH];
    printf("===ͼ�����ϵͳ===\n");

    while(1){
        printf("\n��ѡ�����:\n");
        printf("1.��ʾ����ͼ��\n");
        printf("2.����ͼ��\n");
        printf("3.�黹ͼ��\n");
        printf("4.����ͳ�Ʊ���\n");
        printf("5.�˳�ϵͳ\n");
        printf("������ѡ��(1-5):");

        scanf("%d",&choice);
        getchar();

    switch (choice)
    {
    case 1:
        listBooks(&library);
        break;
    
    case 2:
        printf("������Ҫ���ĵ�ͼ������:");
        fgets(title,MAX_TITLE_LENGTH,stdin); 
        title[strcspn(title,"\n")] = 0;

        if(borrowBook(&library,title)){
            printf("�ɹ����ġ�%s��! \n",title);
        }else{
            printf("����ʧ��!ͼ�鲻���ڻ��ѱ������\n");
        }
        break;
        case 3:
            printf("������Ҫ�黹��ͼ������:");
            fgets(title,MAX_TITLE_LENGTH,stdin);
            title[strcspn(title,"\n")] = 0;

            if(returnBook(&library,title)){
                printf("�ɹ��黹��%s��!\n",title);
            }else{
                printf("�黹ʧ��!ͼ�鲻���ڻ�δ�������\n");
            }
            break;
        case 4:
            generateReport(&library);
            break;
        case 5:
            printf("��лʹ��ͼ�����ϵͳ!\n");
            return 0;        
    default:
        printf("��Чѡ��,����������!\n");
    
    }
    }

    return 0;
}
void initLibrary(Library *lib){
    lib->count = 0;    
}
void addBook(Library *lib, const char *title,const char *author,const char *isbn){
    if(lib->count >= MAX_BOOKS){
        printf("ͼ����������޷���Ӹ���ͼ��!\n");
        return;
    }
    Book *book = &lib->books[lib->count];
    strcpy(book->title,title);
    strcpy(book->author,author);
    strcpy(book->isbn,isbn);
    book->is_borrowed = false;

    lib->count++;
    printf("�����ͼ��:��%s��\n",title);
}

void listBooks(Library *lib){
    printf("\n=== ͼ���б� ===\n");
    printf("%-3s %-20s %-15s %-10s\n","���","����","����","״̬");
    printf("------------------------------------------------\n");

    for(int i = 0;i < lib->count;i++){
        Book *book = &lib->books[i];
        const char *status = book->is_borrowed?"�ѽ��" : "�ɽ�";
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
    printf("\n=== ͼ��ͳ�Ʊ��� ===\n");
    printf("ͼ��������:%d ��\n",total);
    printf("�ɽ�ͼ������:%d ��\n",available);
    printf("�ѽ��ͼ������:%d ��\n",borrowed);
    printf("=========================\n");
}

