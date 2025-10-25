#include <bits/stdc++.h>
using namespace std;

struct Book {
    string title;       
    string author;     
    double price;     
    bool isAvailable;  

 Book(string t, string a, double p, bool available = true)
        : title(t), author(a), price(p), isAvailable(available) {}
};

int main() {
  
    vector<Book> books;
    books.push_back(Book("C++ Primer", "Stanley B. Lippman", 89.0));
    books.push_back(Book("数据结构与算法分析", "Mark Allen Weiss", 79.5));
    books.push_back(Book("计算机网络", "Andrew S. Tanenbaum", 69.0, false));
    books.push_back(Book("Python编程：从入门到实践", "Eric Matthes", 59.8));
    books.push_back(Book("深入理解计算机系统", "Randal E. Bryant", 128.0));

   
    if (books.empty()) {
        printf("当前没有图书信息！\n");
        return 0;
    }
  printf("\n===== 图书馆图书信息 =====\n\n");
  printf("%-30s %-20s %-10s %-10s\n", "书名", "作者", "价格(元)", "状态");
    
   for (int i = 0; i < 70; ++i) {
        printf("-");
    }
    printf("\n");

    for (int i = 0; i < books.size(); ++i) {
        const Book& book = books[i];
       
        printf("%-30s %-20s %-10.2f %-10s\n",
               book.title.c_str(),          // string转const char*
               book.author.c_str(),
               book.price,
               book.isAvailable ? "可借阅" : "已借出");
    }
    printf("\n");
    return 0;
}
