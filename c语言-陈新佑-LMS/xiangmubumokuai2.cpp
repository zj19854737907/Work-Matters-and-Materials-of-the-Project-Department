#include <iostream>
#include <vector>
#include <string>
#include <cstdio>  // 用于printf()

using namespace std;

// 图书结构体，存储图书信息
struct Book {
    string title;       // 书名
    string author;      // 作者
    double price;       // 价格
    bool isAvailable;   // 状态：true可借阅，false已借出

    // 构造函数
    Book(string t, string a, double p, bool available = true)
        : title(t), author(a), price(p), isAvailable(available) {}
};

int main() {
    // 使用vector存储图书（C++98支持vector）
    vector<Book> books;

    // 添加示例图书
    books.push_back(Book("C++ Primer", "Stanley B. Lippman", 89.0));
    books.push_back(Book("数据结构与算法分析", "Mark Allen Weiss", 79.5));
    books.push_back(Book("计算机网络", "Andrew S. Tanenbaum", 69.0, false));
    books.push_back(Book("Python编程：从入门到实践", "Eric Matthes", 59.8));
    books.push_back(Book("深入理解计算机系统", "Randal E. Bryant", 128.0));

    // 检查是否有图书
    if (books.empty()) {
        printf("当前没有图书信息！\n");
        return 0;
    }

    // 输出表格标题
    printf("\n===== 图书馆图书信息 =====\n\n");
    // 使用printf格式化字符串设置列宽
    printf("%-30s %-20s %-10s %-10s\n", "书名", "作者", "价格(元)", "状态");
    
    // 输出分隔线
    for (int i = 0; i < 70; ++i) {
        printf("-");
    }
    printf("\n");

    // 使用for循环遍历图书（C++98风格）
    for (int i = 0; i < books.size(); ++i) {
        const Book& book = books[i];
        // 格式化输出每列信息，%-ns表示左对齐，占n个字符宽度
        printf("%-30s %-20s %-10.2f %-10s\n",
               book.title.c_str(),          // string转const char*
               book.author.c_str(),
               book.price,
               book.isAvailable ? "可借阅" : "已借出");
    }
    printf("\n");

    return 0;
}
