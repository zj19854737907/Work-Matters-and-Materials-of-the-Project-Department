#include <iostream>
#include <string>

// �ӷ����ܺ���
std::string addEncrypt(const std::string& input, int key) {
    std::string encryptedText = input;

    for (char& c : encryptedText) {
        c = c + key; // ʹ�üӷ��������
    }

    return encryptedText;
}

// �ӷ����ܺ���
std::string addDecrypt(const std::string& input, int key) {
    return addEncrypt(input, -key); // ʹ�ü����������
}

// ����������ʽ�����Ǿ��ܺ����׵�д�������������ֻ���������ļ������ͽ�������

// �������ܺ���
std::string subtractEncrypt(const std::string& input, int key) {
    std::string encryptedText = input;

    for (char& c : encryptedText) {
        c = c - key; // ʹ�ü����������
    }

    return encryptedText;
}

// �������ܺ���
std::string subtractDecrypt(const std::string& input, int key) {
    return subtractEncrypt(input, -key); // ʹ�üӷ��������
}

// �˷����ܺ���
std::string multiplyEncrypt(const std::string& input, int key) {
    std::string encryptedText = input;

    for (char& c : encryptedText) {
        c = c * key; // ʹ�ó˷��������
    }

    return encryptedText;
}

// �˷����ܺ���
std::string multiplyDecrypt(const std::string& input, int key) {
    if (key != 0) {
        return multiplyEncrypt(input, 1 / key); // ʹ�ó����������
    } else {
        std::cerr << "���󣺳�������Ϊ��" << std::endl;
        return input;
    }
}

// �������ܺ���
std::string divideEncrypt(const std::string& input, int key) {
    if (key != 0) {
        std::string encryptedText = input;

        for (char& c : encryptedText) {
            c = c / key; // ʹ�ó����������
        }

        return encryptedText;
    } else {
        std::cerr << "���󣺳�������Ϊ��" << std::endl;
        return input;
    }
}

// �������ܺ���
std::string divideDecrypt(const std::string& input, int key) {
    if (key != 0) {
        return divideEncrypt(input, 1 / key); // ʹ�ó˷��������
    } else {
        std::cerr << "���󣺳�������Ϊ��" << std::endl;
        return input;
    }
}

int main() {
    std::string originalText;
    std::cout << "������Ҫ���ܵ��ı�: ";
    std::getline(std::cin, originalText);

    int encryptionKey;
    std::cout << "��������Կ(һ������): ";
    std::cin >> encryptionKey;

    std::string encryptedText;
    std::string decryptedText;

    int choice;
    std::cout << "��ѡ����ܷ�ʽ��\n"
              << "1. �ӷ�\n"
              << "2. ����\n"
              << "3. �˷�\n"
              << "4. ����\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            encryptedText = addEncrypt(originalText, encryptionKey);
            decryptedText = addDecrypt(encryptedText, encryptionKey);
            break;
        case 2:
            encryptedText = subtractEncrypt(originalText, encryptionKey);
            decryptedText = subtractDecrypt(encryptedText, encryptionKey);
            break;
        case 3:
            encryptedText = multiplyEncrypt(originalText, encryptionKey);
            decryptedText = multiplyDecrypt(encryptedText, encryptionKey);
            break;
        case 4:
            encryptedText = divideEncrypt(originalText, encryptionKey);
            decryptedText = divideDecrypt(encryptedText, encryptionKey);
            break;
        default:
            std::cerr << "�����ѡ��" << std::endl;
            return 1;
    }

    std::cout << "���ܺ���ı�: " << encryptedText << std::endl;
    std::cout << "���ܺ���ı�: " << decryptedText << std::endl;

    return 0;
}


