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
        {"C Programming Language", "Brian Kernighan","�ɽ�" ,9.9},
        {"Data Structures and Algorithms", "Robert Sedgewick", "�ɽ�",59.9},
        {"The C++ Programming Language", "Bjarne Stroustrup", "�ɽ�",19.9},
        {"Introduction to Algorithms", "Thomas Cormen", "�ɽ�",29.9},
        {"1984", "George Orwell", "�ɽ�",19.44}
    };

	
	printf("------------=����ͼ�����ϵͳ=------------\n\n");
	printf("-(*�㨌��*):�û����ã�������ʹ��ϵͳ�����¹��ܣ�\n");
	printf("\n");
	printf(" *1:ͼ����Ϣ¼��\n");
	printf(" *2:��ʾ����ͼ����Ϣ\n");
	printf(" *3:����ͼ����Ϣ(������)\n");
	printf(" *4:�޸�ͼ����Ϣ\n");
	printf(" *5:ɾ��ͼ����Ϣ\n");
	printf(" *6:������黹(������)\n");
	printf("\n");
	printf("-----------------------------------------\n");
	printf("\n");
	printf("-(*@��@*):�������Ҫ��ʼʹ��ϵͳ�������������1 ~\n	 ��������ھ����˳��������������0 ~\n");
	scanf("%d",&m);
	while(m==1){
		printf("=======================================\n");	
		printf("\n");
		printf("-(*^ ��^*):����Ҫʹ��ʲô���ܣ��������������Ӧ��ţ���");
		scanf("%d",&mode);
		getchar();
//-------------------------	
		if(mode==3){
			sec=1;
			printf("\n�����������ѯ��������");
			fflush(stdout);
			gets(name);
			searchbook(library,name,sec);
		}
		
		else if(mode==6){
			sec=0;
			printf("\n������������");
			fflush(stdout);
			gets(name);
			searchbook(library,name,sec);
			scanf("%c",&an);
			if(an=='y'){
				printf("-�����ɹ���\n");
				change(library); 
			}
		}
		
		else{
			printf("\n->>>404 NOT FOUND...(���㧥��)\n\n-(**@��@**):���Ͱ���\n");
		}
//----------------------------
		printf("=======================================\n");	
		printf("\n-(*@��@*):���������ʹ��ϵͳ��\n	 �����������������������1 ~\n	 ��������˳��������������0 ~\n");
		scanf("%d",&m);
	}
	printf("-----------------------------------------\n");
	printf("\n");
	printf("-(*^ �� ^*):�õģ��û��ټ� ~\n");  
	if(m!=0){
		printf("( (������):�Ѻ��˻�������ϸ�Ķ�����ָ���ޣ�������ǻ������ʹ��%d���ܵĻ�Ӧ��������1�� )\n",m); 
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
            	printf("\n-(*#_#*):���ҵ���ȷƥ���ͼ��-->\n");
            	printf("->>>����: %s\n",library[i].title);
            	printf("->>>����: %s\n",library[i].author);
				printf("->>>״̬: %s\n",library[i].state);
				printf("->>>�۸�: %.2lf\n",library[i].price);		            
     	    	break;
			}
			if(sec==0){
				printf("->>>״̬: %s\n",library[i].state);
				if(strcmp("�ɽ�",library[i].state)==0){
					printf("\n�Ƿ���ģ���y/n��:"); 
					fflush(stdout);
					mar=i;
					break; 
				}else{
					printf("\n�Ƿ�黹����y/n��:");
					fflush(stdout);
					mar=i;
					break;					
				}
			}
		}
    }
        if(m==0){
        	printf("\n-(**@��@**):�ʳ���Ǹ�������û���Ȿ�顣���������У�\n");
        	for(i=0;i<5;i++){
        		printf(" ��%s��\n",library[i].title);
			}
			printf("\n-(*U��U*):�������������ҵ���\n\n");
		}
}
void change(struct book library[]){	
    struct book {
   		char title[MAX_TITLE_LENGTH];
   		char author[MAX_AUTHOR_LENGTH];
   		char state[MAX_STATE_LENGTH];
   		double price;
	};
	if(strcmp("�ɽ�",library[mar].state)==0){
		strcpy(library[mar].state,"�ѽ��");
	}else{
		strcpy(library[mar].state,"�ɽ�");
	}
}

