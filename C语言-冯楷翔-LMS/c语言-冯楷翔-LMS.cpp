#include <stdio.h>
#include <string.h>
struct Book {
	char id[20];
	char name[50];
	char author[30];
	float price;
	int stock;
};
int main() {
	struct Book library[] = {
		{"B001", "C���Գ������", "̷��ǿ",49.80,25},
		{"BOO2","���ݽṹ���㷨", "��ޱ��",59.00,18},
		{"B003","���������","лϣ��",45.50,32},
		{"BOO4","����ϵͳ","��С��",52.80,15}
	};
	int BoojCount = sizeof(library) / sizeof(struct Book);
	printf("ͼ����Ϣ��:\n");
		printf("%-10s %-25s %-15s %-10s %-8s\n","ͼ����", "ͼ������", "����", "�۸�", "���");
	for (int i = 0; i < BoojCount; i++) {
		printf("%-10s %-25s %-15s %-10.2f %-8d\n", library[i].id, library[i].name, library[i].author, library[i].price, library[i].stock);
}
	return 0;
	};
