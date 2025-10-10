#define _CRT_SECURE_NO_WARNINGS

// 引入必要的头文件，不必深究哦~
#include <iostream>
using namespace std;

// 创建一个简单函数演示static
int magicalCounter() 
{
    static int count = 0;  // 使用 static 修饰符的魔法计数器

    count++;  // 每次调用，魔法计数器加一

    return count;  // 返回魔法计数器的值
}

// 主角登场，这里是我们的主函数
int main()
{
    // 想象一下，我们的计算器就像是一把神奇的魔法计算棒，只需要轻轻一点，就能得到答案。
    // 而你是一位小小的商店老板，你需要用魔法计算棒算出购物的总价。
    // 而现在，跟着小猫老板一起学习怎么构造简易计算器吧，喵~

    // 快速了解一下我们的魔法工具：
    // 1. cout用于显示信息 （cout << xxxx;)
    // 2. cin用于获取输入  (cin >> xxxx >> endl(换行);)

    // 定义两个数字，这是我们的魔法数字
    double num1, num2;

    // 小猫老板输入第一个数字
    cout << "喵喵！请告诉我第一个数字：";
    cin >> num1;

    // 请注意，如果我们要进行除法，第二个数字不能是0哦喵~
    cout << "如果要进行除法运算，请确保第二个数字不是0哦喵~" << endl;

    // 小猫老板输入第二个数字
    cout << "喵喵！再告诉我第二个数字：";
    cin >> num2;

    // 让我们一起看看魔法计算棒的威力！
    cout << "嘿嘿，计算结果就要揭晓啦！" << endl;

    // 加法计算
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;

    // 减法计算
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;

    // 乘法计算
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;

    // 除法计算
    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;

    cout << endl;

    // 不同数据类型的比较与说明
    int intNum = 5;
    double doubleNum1 = 5.5;
    double doubleNum2 = 4.5;

    // 整数和浮点数在除法运算上的区别
    cout << "整数和浮点数在除法运算上的区别：" << endl;
    cout << intNum << " / " << intNum << " = " << intNum / intNum << " (整数除法，结果是整数)" << endl;
    cout << doubleNum1 << " / " << intNum << " = " << doubleNum1 / intNum << " (浮点数除以整数，结果是浮点数)" << endl;
    cout << doubleNum1 << " / " << doubleNum2 << " = " << doubleNum1 / doubleNum2 << " (浮点数除以浮点数，结果是浮点数)" << endl;

    // 修饰符的介绍
    // 再来感受一下魔法的力量，我们的计算器里有一个魔法开关，把它打开，我们就可以变出一个不可改变的数字。

    cout << endl;

    // 魔法常量，不能被改变的数字
    const double PI = 3.14159;

    // 输出常量的值
    cout << "喵，这是一个魔法常数：" << PI << endl;

    // 尝试修改常量的值，发现魔法力量阻止了我们
    // MAGIC_NUMBER = 3.14; // 错误了喵，魔法常量不可修改呢

    cout << endl;

    // static修饰符
    cout << "第一次调用魔法计数器：" << magicalCounter() << endl;  // 输出 1
    cout << "第二次调用魔法计数器：" << magicalCounter() << endl;  // 输出 2
    cout << "第三次调用魔法计数器：" << magicalCounter() << endl;  // 输出 3
    // 可以看到，我们在调用这个魔法计数器函数的时候被static修饰的变量count并没有如函数里那样被反复赋值为0，而这就是static的作用


    // 返回0是一个好的习惯哦喵~
    return 0;
}