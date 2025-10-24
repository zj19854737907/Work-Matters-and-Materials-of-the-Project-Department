#include<stdio.h>
#include<string.h>
#define MAX_TITLE_LENGTH 40
#define MAX_AUTHOR_LENGTH 40
#define MAX_STATE_LENGTH 20
#define MAX_BOOKS 20
struct book {
   	char title[MAX_TITLE_LENGTH];
   	char author[MAX_AUTHOR_LENGTH];
   	char state[MAX_STATE_LENGTH];
   	float price;
};
void searchbook(struct book library[],char name[],int sec);
void change(struct book library[]);
int mar=2;
int main(){
	char an; 
	int mode,m,sec;
	char name[20];
    struct book library[MAX_BOOKS] = {
        {"C Programming Language", "Brian Kernighan","可借" ,9.9},
        {"Data Structures and Algorithms", "Robert Sedgewick", "可借",59.9},
        {"The C++ Programming Language", "Bjarne Stroustrup", "可借",19.9},
        {"Introduction to Algorithms", "Thomas Cormen", "可借",29.9},
        {"1984", "George Orwell", "可借",19.44}
    };

	
	printf("------------=简易图书管理系统=------------\n\n");
	printf("-(*°▽°*):用户您好！您可以使用系统的以下功能：\n");
	printf("\n");
	printf(" *1:图书信息录入\n");
	printf(" *2:显示所有图书信息\n");
	printf(" *3:查找图书信息(开放中)\n");
	printf(" *4:修改图书信息\n");
	printf(" *5:删除图书信息\n");
	printf(" *6:借阅与归还(开放中)\n");
	printf("\n");
	printf("-----------------------------------------\n");
	printf("\n");
	printf("-(*@▽@*):如果您想要开始使用系统——请接着输入1 ~\n	 如果您现在就想退出——请接着输入0 ~\n");
	scanf("%d",&m);
	while(m==1){
		printf("=======================================\n");	
		printf("\n");
		printf("-(*^ ▽^*):您想要使用什么功能？——（请输入对应序号）：");
		scanf("%d",&mode);
		getchar();
//-------------------------	
		if(mode==3){
			sec=1;
			printf("\n请输入您想查询的书名：");
			fflush(stdout);
			gets(name);
			searchbook(library,name,sec);
		}
		
		else if(mode==6){
			sec=0;
			printf("\n请输入书名：");
			fflush(stdout);
			gets(name);
			searchbook(library,name,sec);
			scanf("%c",&an);
			if(an=='y'){
				printf("-操作成功！\n");
				change(library); 
			}
		}
		
		else{
			printf("\n->>>404 NOT FOUND...(＃°Д°)\n\n-(**@▽@**):阿巴阿巴\n");
		}
//----------------------------
		printf("=======================================\n");	
		printf("\n-(*@▽@*):您还想继续使用系统吗？\n	 如果您想继续——请接着输入1 ~\n	 如果您想退出——请接着输入0 ~\n");
		scanf("%d",&m);
	}
	printf("-----------------------------------------\n");
	printf("\n");
	printf("-(*^ ▽ ^*):好的，用户再见 ~\n");  
	if(m!=0){
		printf("( (〒▽〒):窝很人机，请仔细阅读操作指令噢，您如果是还想继续使用%d功能的话应该先输入1的 )\n",m); 
	} 
	
	return 0;
}

void searchbook(struct book library[],char name[],int sec){
    int i,m=0;
    struct book {
   		char title[MAX_TITLE_LENGTH];
   		char author[MAX_AUTHOR_LENGTH];
   		char state[MAX_STATE_LENGTH];
   		double price;
	};
    for (i=0;i<5;i++) {
        if (strcmp(library[i].title, name) == 0) {
        	m=1;
        	if(sec==1){
            	printf("\n-(*#_#*):！找到精确匹配的图书-->\n");
            	printf("->>>书名: %s\n",library[i].title);
            	printf("->>>作者: %s\n",library[i].author);
				printf("->>>状态: %s\n",library[i].state);
				printf("->>>价格: %.2lf\n",library[i].price);		            
     	    	break;
			}
			if(sec==0){
				printf("->>>状态: %s\n",library[i].state);
				if(strcmp("可借",library[i].state)==0){
					printf("\n是否借阅？（y/n）:"); 
					fflush(stdout);
					mar=i;
					break; 
				}else{
					printf("\n是否归还？（y/n）:");
					fflush(stdout);
					mar=i;
					break;					
				}
			}
		}
    }
        if(m==0){
        	printf("\n-(**@▽@**):肥肠抱歉！书库里没有这本书。但是我们有：\n");
        	for(i=0;i<5;i++){
        		printf(" 《%s》\n",library[i].title);
			}
			printf("\n-(*U▽U*):您看看有您想找的吗？\n\n");
		}
}
void change(struct book library[]){	
    struct book {
   		char title[MAX_TITLE_LENGTH];
   		char author[MAX_AUTHOR_LENGTH];
   		char state[MAX_STATE_LENGTH];
   		double price;
	};
	if(strcmp("可借",library[mar].state)==0){
		strcpy(library[mar].state,"已借出");
	}else{
		strcpy(library[mar].state,"可借");
	}
}

