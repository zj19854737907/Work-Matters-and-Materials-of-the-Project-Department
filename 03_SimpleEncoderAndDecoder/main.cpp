#include <iostream>
#include <string>

// 加法加密函数
std::string addEncrypt(const std::string& input, int key) {
    std::string encryptedText = input;

    for (char& c : encryptedText) {
        c = c + key; // 使用加法运算加密
    }

    return encryptedText;
}

// 加法解密函数
std::string addDecrypt(const std::string& input, int key) {
    return addEncrypt(input, -key); // 使用减法运算解密
}

// 仿照以上形式，我们就能很轻易的写出基于其他几种基本运算符的加密器和解密器了

// 减法加密函数
std::string subtractEncrypt(const std::string& input, int key) {
    std::string encryptedText = input;

    for (char& c : encryptedText) {
        c = c - key; // 使用减法运算加密
    }

    return encryptedText;
}

// 减法解密函数
std::string subtractDecrypt(const std::string& input, int key) {
    return subtractEncrypt(input, -key); // 使用加法运算解密
}

// 乘法加密函数
std::string multiplyEncrypt(const std::string& input, int key) {
    std::string encryptedText = input;

    for (char& c : encryptedText) {
        c = c * key; // 使用乘法运算加密
    }

    return encryptedText;
}

// 乘法解密函数
std::string multiplyDecrypt(const std::string& input, int key) {
    if (key != 0) {
        return multiplyEncrypt(input, 1 / key); // 使用除法运算解密
    } else {
        std::cerr << "错误：除数不能为零" << std::endl;
        return input;
    }
}

// 除法加密函数
std::string divideEncrypt(const std::string& input, int key) {
    if (key != 0) {
        std::string encryptedText = input;

        for (char& c : encryptedText) {
            c = c / key; // 使用除法运算加密
        }

        return encryptedText;
    } else {
        std::cerr << "错误：除数不能为零" << std::endl;
        return input;
    }
}

// 除法解密函数
std::string divideDecrypt(const std::string& input, int key) {
    if (key != 0) {
        return divideEncrypt(input, 1 / key); // 使用乘法运算解密
    } else {
        std::cerr << "错误：除数不能为零" << std::endl;
        return input;
    }
}

int main() {
    std::string originalText;
    std::cout << "请输入要加密的文本: ";
    std::getline(std::cin, originalText);

    int encryptionKey;
    std::cout << "请输入密钥(一个整数): ";
    std::cin >> encryptionKey;

    std::string encryptedText;
    std::string decryptedText;

    int choice;
    std::cout << "请选择加密方式：\n"
              << "1. 加法\n"
              << "2. 减法\n"
              << "3. 乘法\n"
              << "4. 除法\n";
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
            std::cerr << "错误的选择" << std::endl;
            return 1;
    }

    std::cout << "加密后的文本: " << encryptedText << std::endl;
    std::cout << "解密后的文本: " << decryptedText << std::endl;

    return 0;
}


