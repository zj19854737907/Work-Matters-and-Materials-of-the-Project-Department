#include <iostream>
#include <vector>
#include <string>
#include <cstdio>  // ����printf()

using namespace std;

// ͼ��ṹ�壬�洢ͼ����Ϣ
struct Book {
    string title;       // ����
    string author;      // ����
    double price;       // �۸�
    bool isAvailable;   // ״̬��true�ɽ��ģ�false�ѽ��

    // ���캯��
    Book(string t, string a, double p, bool available = true)
        : title(t), author(a), price(p), isAvailable(available) {}
};

int main() {
    // ʹ��vector�洢ͼ�飨C++98֧��vector��
    vector<Book> books;

    // ���ʾ��ͼ��
    books.push_back(Book("C++ Primer", "Stanley B. Lippman", 89.0));
    books.push_back(Book("���ݽṹ���㷨����", "Mark Allen Weiss", 79.5));
    books.push_back(Book("���������", "Andrew S. Tanenbaum", 69.0, false));
    books.push_back(Book("Python��̣������ŵ�ʵ��", "Eric Matthes", 59.8));
    books.push_back(Book("�����������ϵͳ", "Randal E. Bryant", 128.0));

    // ����Ƿ���ͼ��
    if (books.empty()) {
        printf("��ǰû��ͼ����Ϣ��\n");
        return 0;
    }

    // ���������
    printf("\n===== ͼ���ͼ����Ϣ =====\n\n");
    // ʹ��printf��ʽ���ַ��������п�
    printf("%-30s %-20s %-10s %-10s\n", "����", "����", "�۸�(Ԫ)", "״̬");
    
    // ����ָ���
    for (int i = 0; i < 70; ++i) {
        printf("-");
    }
    printf("\n");

    // ʹ��forѭ������ͼ�飨C++98���
    for (int i = 0; i < books.size(); ++i) {
        const Book& book = books[i];
        // ��ʽ�����ÿ����Ϣ��%-ns��ʾ����룬ռn���ַ����
        printf("%-30s %-20s %-10.2f %-10s\n",
               book.title.c_str(),          // stringתconst char*
               book.author.c_str(),
               book.price,
               book.isAvailable ? "�ɽ���" : "�ѽ��");
    }
    printf("\n");

    return 0;
}
