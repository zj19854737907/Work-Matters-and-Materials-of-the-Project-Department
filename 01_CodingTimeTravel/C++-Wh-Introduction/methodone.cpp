// c++ 求解鸡兔同笼
// #1.运用代数（解方程）的方法来求鸡兔同笼问题

#include <iostream>

// 这是一个预处理指令，告诉计算机要包含一个名为 iostream 的头文件，这样我们才可以进行输入输出
// 我们是用cin 和cout来进行输入输出的 后面会说 现在有个大致了解就好

int main()
{
    // 定义鸡和兔的总数量为10 定义总的脚的数量为32
    // 解方程组  为了方便我们看 我们先用b来表示rabbits a表示chikins
    // 2a + 4b = total_feet
    // a + b = total_quantity
    // 解得 a = total_quantity - b
    // 2(total_quantity - b) + 4b = total_feet
    // 2 * total_quantity - 2b + 4b = total_feet
    // b = (total_feet - 2 * total_quantity) / 2
    int total_quantity = 10;
    int total_feet = 32;

    // 根据第一个方程解出兔的数量
    int rabbits = (total_feet - 2 * total_quantity) / 2;

    // 得到鸡的数量
    int chickens = total_quantity - rabbits;

        // 打印结果
    std::cout<< "鸡的数量：" << chickens << "，兔的数量：" << rabbits << std::endl;
       //std::cout，cout 是 "character output" 的缩写。类似于python中的print

        //  "<<" 这是输出运算符，它的作用是将右侧的内容输出到左侧的流中。 它像一条绳子 将输出内容从左到右串起来
        //"鸡的数量：": 这是一个字符串文字，表示文本信息，我们要输出的是 "鸡的数量：" 这个文本。
        // " << chickens << "，兔的数量：" << rabbits: "  : 这部分是一系列的输出操作，表示 先输出chickens的值  再输出一串文字  再输出变量rabbbits的值
        // std::endl 表示的是下次输出的内容会换掉下一行

    return 0;
}