#include <stdio.h>
#include<stdlib.h>
#include <string.h>


struct Book {
    char title[100];
    char author[50];
    float price;
    char status[20];   //孩子已经不记得状态的英文了，还要上网找翻译。。。。
};
int main() {
    struct Book books[] = {
        {"《正道魁首是如何养成的》", "不言归", 43.73, "可借"},    //这是我最近比较喜欢看的小说
        {"《朕真的不会开机甲》", "归鸿落雪", 28.27, "可借"},      //欢迎大家品鉴
        {"《我在废土世界扫垃圾》", "有花在野", 36.00, "已借出"},  //(๑ᵔ⌔ᵔ๑)
        {"《揽明月》", "归鸿落雪", 63.00, "可借"},
        {"《我的师妹不可能是傻白甜》", "归山玉", 18.50, "作者断更"},  //避雷这个作家啊啊啊啊她断更了啊啊啊但是作品实在美味嘻嘻
        {"《奇洛李维斯回信》" ,"清明谷雨",99.00,"可借"},
        {"《小谭山没有天文台》","清明谷雨",99.99,"连载"},
        {"《穿进赛博游戏后干掉BOSS成功上位》","桉柏",66.00,"已借出"}
    };
    int bookCount = sizeof(books) / sizeof(books[0]);
    printf("================================== 超级好看的小说推荐（划掉）图书信息管理系统 =========================\n\n\n");
    printf("┌─────────────────────────────────────────┬───────────────────────┬─────────────┬────────────┐\n");
    printf("│ %-35s     │ %-20s  │ %-10s  │ %-10s │\n", "书名", "作者", "价格", "状态");
    printf("├─────────────────────────────────────────┼───────────────────────┼─────────────┼────────────┤\n");
        for (int i = 0; i < bookCount; i++) {
        printf("│ %-35s     │ %-20s  │ %10.2f  │ %-10s │\n",
            books[i].title,
            books[i].author,
            books[i].price,
            books[i].status);
    }
    printf("└─────────────────────────────────────────┴───────────────────────┴─────────────┴────────────┘\n");
    
    //救救孩子吧，这个表格好难对齐啊啊啊啊

    char searchTitle[100];
    int found = 0;
    int numBooks = 8;

    printf("请输入要查找的书名: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);

    searchTitle[strcspn(searchTitle, "\n")] = '\0';    //我也不知道为什么这一大段的全部有绿色波浪线

    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, searchTitle) == 0) {
            found = 1;
            printf("书名: %s\n", books[i].title);
            printf("作者: %s\n", books[i].author);
            printf("价格: %.2f\n", books[i].price);
            printf("状态：%s\n", books[i].status);
            break;
        }
    }

    if (!found) {
        printf("没有找到哟\n");
    }
    return 0;
}