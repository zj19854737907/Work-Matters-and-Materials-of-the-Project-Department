#include <iostream>
#include <string>
using namespace std;

// ����ͼ��ṹ��
struct Book {
    string title;   // ����
    string author;  // ����
    string status;  // ״̬�����磺�ڿ⡢����ȣ�
};

const int MAX_BOOKS = 100;  // ���ɴ洢��ͼ������

int main() {
    Book books[MAX_BOOKS];   // �ṹ������洢ͼ����Ϣ
    int count = 0;           // ��ǰ�Ѵ洢��ͼ������
    char continueInput;      // �����ж��Ƿ��������

    cout << "===== ͼ����Ϣ¼��ϵͳ =====" << endl;

    do {
        // ����Ƿ��Ѵ����洢��
        if (count >= MAX_BOOKS) {
            cout << "���棺�Ѵﵽ���洢������" << MAX_BOOKS << "�������޷�����¼�룡" << endl;
            break;
        }

        // ����ͼ����Ϣ
        cout << "\n������� " << count + 1 << " ��ͼ����Ϣ��" << endl;
        
        cin.ignore();  // ������뻺�����Ļ��з�
        cout << "������";
        getline(cin, books[count].title);  // ֧�ִ��ո����������
        
        cout << "���ߣ�";
        getline(cin, books[count].author); // ֧�ִ��ո������������
        
        cout << "״̬�����磺�ڿ�/�������";
        getline(cin, books[count].status);

        count++;  // ͼ��������1

        // ѯ���Ƿ��������
        cout << "\n�Ƿ����¼�룿(y/n)��";
        cin >> continueInput;

    } while (continueInput == 'y' || continueInput == 'Y');

    // ��ʾ��¼���ͼ����Ϣ
    cout << "\n===== ��¼���ͼ����Ϣ =====" << endl;
    if (count == 0) {
        cout << "��δ¼���κ�ͼ����Ϣ��" << endl;
    } else {
        for (int i = 0; i < count; i++) {
            cout << "\n�� " << i + 1 << " ����" << endl;
            cout << "������" << books[i].title << endl;
            cout << "���ߣ�" << books[i].author << endl;
            cout << "״̬��" << books[i].status << endl;
        }
    }

    return 0;
}
