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
		{"B001", "C语言程序设计", "谭浩强",49.80,25},
		{"BOO2","数据结构与算法", "严薇敏",59.00,18},
		{"B003","计算机网络","谢希仁",45.50,32},
		{"BOO4","操作系统","汤小丹",52.80,15}
	};
	int BoojCount = sizeof(library) / sizeof(struct Book);
	printf("图书信息表:\n");
		printf("%-10s %-25s %-15s %-10s %-8s\n","图书编号", "图书名称", "作者", "价格", "库存");
	for (int i = 0; i < BoojCount; i++) {
		printf("%-10s %-25s %-15s %-10.2f %-8d\n", library[i].id, library[i].name, library[i].author, library[i].price, library[i].stock);
}
	return 0;
	};
