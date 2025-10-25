#include <iostream>
#include <string>
using namespace std;

// 定义图书结构体
struct Book {
    string title;   // 书名
    string author;  // 作者
    string status;  // 状态（例如：在库、借出等）
};

const int MAX_BOOKS = 100;  // 最大可存储的图书数量

int main() {
    Book books[MAX_BOOKS];   // 结构体数组存储图书信息
    int count = 0;           // 当前已存储的图书数量
    char continueInput;      // 用于判断是否继续输入

    cout << "===== 图书信息录入系统 =====" << endl;

    do {
        // 检查是否已达最大存储量
        if (count >= MAX_BOOKS) {
            cout << "警告：已达到最大存储容量（" << MAX_BOOKS << "本），无法继续录入！" << endl;
            break;
        }

        // 输入图书信息
        cout << "\n请输入第 " << count + 1 << " 本图书信息：" << endl;
        
        cin.ignore();  // 清除输入缓冲区的换行符
        cout << "书名：";
        getline(cin, books[count].title);  // 支持带空格的书名输入
        
        cout << "作者：";
        getline(cin, books[count].author); // 支持带空格的作者名输入
        
        cout << "状态（例如：在库/借出）：";
        getline(cin, books[count].status);

        count++;  // 图书数量加1

        // 询问是否继续输入
        cout << "\n是否继续录入？(y/n)：";
        cin >> continueInput;

    } while (continueInput == 'y' || continueInput == 'Y');

    // 显示已录入的图书信息
    cout << "\n===== 已录入的图书信息 =====" << endl;
    if (count == 0) {
        cout << "尚未录入任何图书信息！" << endl;
    } else {
        for (int i = 0; i < count; i++) {
            cout << "\n第 " << i + 1 << " 本：" << endl;
            cout << "书名：" << books[i].title << endl;
            cout << "作者：" << books[i].author << endl;
            cout << "状态：" << books[i].status << endl;
        }
    }

    return 0;
}
