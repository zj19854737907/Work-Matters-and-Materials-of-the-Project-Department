# 运行程序，__name__是python中一个内置变量，用来判断当前文件是否被直接运行，还是被导入
from core import src
if __name__ == '__main__':
#运行core文件中的src中的run函数
#把要运行的主函数放到一个函数中，这样可以避免主函数过长，不易于维护
#而且也有利于管理
    src.run()