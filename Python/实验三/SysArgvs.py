# 创建输出命令行参数个数以及各参数内容的模块SysArgvs.py,并编写测试代码

import sys

def print_args():
    print("命令行参数个数为:", len(sys.argv) - 1)
    print("命令行参数为:")
    for i in range(1, len(sys.argv)):
        print(sys.argv[i])

if __name__ == '__main__':
    print_args()
