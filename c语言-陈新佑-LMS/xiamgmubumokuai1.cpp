#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;   
    string author;  
    string status;  
};

const int MAX_BOOKS = 100;  

int main() {
    Book books[MAX_BOOKS];   
    int count = 0;          
    char continueInput;    

    cout << "===== 图书信息录入系统 =====" << endl;

    do {
        if (count >= MAX_BOOKS) {
            cout << "警告：已达到最大存储容量（" << MAX_BOOKS << "本），无法继续录入！" << endl;
            break;
        }
        cout << "\n请输入第 " << count + 1 << " 本图书信息：" << endl;
        
        cin.ignore();  
        cout << "书名：";
        getline(cin, books[count].title);  
        
        cout << "作者：";
        getline(cin, books[count].author); 
        
        cout << "状态（例如：在库/借出）：";
        getline(cin, books[count].status);

        count++;  

        cout << "\n是否继续录入？(y/n)：";
        cin >> continueInput;

    } while (continueInput == 'y' || continueInput == 'Y');

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

