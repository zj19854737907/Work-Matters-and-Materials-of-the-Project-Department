// 2.利用穷举法（循环试数）的方法

#include <iostream>

// 这是一个预处理指令，告诉计算机要包含一个名为 iostream 的头文件，这样我们才可以进行输入输出
// 我们是用cin 和cout来进行输入输出的 后面会说 现在有个大致了解就好

int main()
{
    // 创建变量来存储动物的总的脚的数量
    int total_feet = 18;
    // 鸡的数量
    int chickens = 0;
    // 兔子的数量
    int rabbits = 0;

    // 这是一个循环的开始，它将从 chicken 的值为 0 开始，一直循环到 total_feet / 2，每次递增 1。
    for (int chicken = 0; chicken <= total_feet / 2; ++chicken)
    {
        // 在循环中的这一行，我们根据当前鸡的数量计算相应的兔的数量。
        // 这是通过用总脚数=2*鸡脚数+4*兔脚数 得到的
        int rabbit = (total_feet - 2 * chicken) / 4;

        // 检查是否满足条件（脚的总数和数量关系）
        if (2 * chicken + 4 * rabbit == total_feet)
        {
            // 在满足条件的情况下，我们将当前的鸡和兔的数量分别赋给 chickens 和 rabbits，
            // 然后使用 break 语句结束循环，因为我们已经找到了解。

            std::cout << "鸡的数量：" << chicken << "，兔的数量：" << rabbit << std::endl;
            // std::cout，cout 是 "character output" 的缩写。类似于python中的print
            //  "<<" 这是输出运算符，它的作用是将右侧的内容输出到左侧的流中。 它像一条绳子 将输出内容从左到右串起来
            //"鸡的数量：": 这是一个字符串文字，表示文本信息，我们要输出的是 "鸡的数量：" 这个文本。
            // " << chickens << "，兔的数量：" << rabbits: "  : 这部分是一系列的输出操作，表示 先输出chickens的值  再输出一串文字  再输出变量rabbbits的值
            // std::endl 表示的是下次输出的内容会换掉下一行
        }
        // 这个循环用来尝试所有可能的鸡的数量。
    }

    return 0;
}