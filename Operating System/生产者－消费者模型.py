#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
生产者-消费者问题演示程序
该程序演示了多线程环境下生产者和消费者如何通过有限缓冲区进行协作
当生产速度慢于消费速度时，缓冲区会被填满，此时生产者会被阻塞

程序使用了Python的threading模块来实现多线程同步：
1. threading.Thread: 创建和管理线程
2. threading.Semaphore: 信号量，用于控制对共享资源的访问
3. threading.Lock: 锁，用于保护临界区

信号量(Semaphore)是一种同步原语，用于控制同时访问特定资源的线程数量。
它内部维护一个计数器（称为许可数）：
- 当线程调用acquire()方法时，计数器减1；如果计数器为0，则线程被阻塞
- 当线程调用release()方法时，计数器加1，并唤醒等待的线程

在本程序中使用了三种信号量：
1. mutex: 互斥信号量，确保同一时间只有一个线程访问缓冲区（初始值为1）
2. empty: 空槽位信号量，表示可用的空槽数量（初始值为缓冲区大小）
3. full: 满槽位信号量，表示已占用的槽数量（初始值为0）
"""

# 导入所需的模块
import threading  # 多线程支持
                  # threading模块提供了高级别的线程编程接口
                  # 包括Thread类（创建线程）、Lock类（互斥锁）、Semaphore类（信号量）等
import time       # 时间相关函数
import random     # 随机数生成
import os         # 操作系统接口
from collections import deque  # 双端队列，用作循环缓冲区

# 配置参数
BUF_SIZE = 5                    # 缓冲区大小：最多容纳5个元素
ITEMS_PER_PRODUCER = 15         # 每个生产者生产15件商品
PRODUCERS = 2                   # 生产者线程数量
CONSUMERS = 3                   # 消费者线程数量

# 共享资源定义
buf = deque(maxlen=BUF_SIZE)    # 使用双端队列作为循环缓冲区，最大长度为BUF_SIZE
                                # deque是double-ended queue的缩写，支持从两端高效地添加和删除元素
                                
mutex = threading.Semaphore(1)  # 互斥信号量，用于保护对缓冲区的访问，初始值为1
                                # 这确保了同一时间只有一个线程可以访问缓冲区（互斥访问）
                                
empty = threading.Semaphore(BUF_SIZE)  # 空槽位信号量，表示可用的空槽数量，初始值为BUF_SIZE
                                       # 当生产者想要生产时，需要获取一个空槽位
                                       # 当消费者消费完一个商品后，会释放一个空槽位
                                       
full = threading.Semaphore(0)   # 满槽位信号量，表示已占用的槽数量，初始值为0
                                # 当生产者生产一个商品后，会释放一个满槽位
                                # 当消费者想要消费时，需要获取一个满槽位

# 线程安全打印锁
print_lock = threading.Lock()   # 打印锁，确保多个线程的输出不会相互干扰
                                # Lock是互斥锁，同一时间只能有一个线程获得锁

# 终端颜色输出辅助函数
def c(code, s):
    """根据ANSI转义码设置文本颜色"""
    return f'\033[{code}m{s}\033[0m'

def red(s):
    """红色文本"""
    return c(91, s)

def green(s):
    """绿色文本"""
    return c(92, s)

def yellow(s):
    """黄色文本"""
    return c(93, s)

def cyan(s):
    """青色文本"""
    return c(96, s)

def flash_red(s):
    """闪烁红底白字效果"""
    return f'\033[5;41;97m{s}\033[0m'  # 5=闪烁, 41=红底, 97=白字

# 线程安全打印函数
def safe_print(*args, **kw):
    """
    线程安全的打印函数
    使用print_lock确保同一时间只有一个线程可以打印
    """
    with print_lock:
        print(*args, **kw)

# 缓冲区状态可视化函数
def print_bar():
    """
    显示缓冲区当前状态的可视化进度条
    返回格式化的字符串显示缓冲区占用情况
    """
    filled = len(buf)                           # 获取当前缓冲区已占用槽数量
    bar = '█'*filled + '░'*(BUF_SIZE-filled)   # 构造进度条：实心块表示已占用，空心块表示空闲
    if filled == BUF_SIZE:
        # 如果缓冲区已满，以闪烁红底白字显示
        return flash_red(f'[{bar}] FULL!')
    # 否则显示普通状态
    return f'[{bar}] {filled}/{BUF_SIZE}'

# 生产者函数
def producer(pid):
    """
    生产者线程函数
    参数:
        pid: 生产者ID
    """
    produced = 0  # 已生产商品计数器
    # 持续生产直到达到指定数量
    while produced < ITEMS_PER_PRODUCER:
        # 随机选择一个水果作为生产的商品
        item = random.choice(['🍎','🍊','🍌','🍇','🥝'])
        
        # 先尝试获取空槽位信号量（非阻塞方式）
        acquired = empty.acquire(timeout=0)
        if not acquired:
            # 如果没有空槽位，说明缓冲区已满
            safe_print(f'{print_bar()}  {red("[缓冲区已满!]")} '
                       f'Producer{pid} 阻塞中...')
            # 真正阻塞等待直到有空槽位
            empty.acquire()
        
        # 获取互斥锁，保护对缓冲区的访问
        mutex.acquire()
        # 将商品放入缓冲区
        buf.append(item)
        # 释放互斥锁
        mutex.release()
        
        # 增加满槽位信号量，表示有一个新商品可供消费
        full.release()
        
        # 更新已生产商品计数
        produced += 1
        
        # 打印生产信息
        safe_print(f'{print_bar()}  {green("Producer"+str(pid))} → {item}  '
                   f'(total={produced})')
        
        # 模拟生产过程需要时间（随机休眠5-10秒）
        time.sleep(random.uniform(5, 10))
    
    # 生产者完成所有生产任务
    safe_print(f'Producer{pid} 完成，不再生产。')

# 消费者函数
def consumer(cid):
    """
    消费者线程函数
    参数:
        cid: 消费者ID
    """
    consumed = 0  # 已消费商品计数器
    
    # 持续消费直到所有生产者完成且缓冲区为空
    while True:
        # 尝试获取满槽位信号量（超时0.5秒）
        if full.acquire(timeout=0.5):
            # 获取互斥锁，保护对缓冲区的访问
            mutex.acquire()
            # 从缓冲区取出一个商品
            item = buf.popleft()
            # 释放互斥锁
            mutex.release()
            
            # 增加空槽位信号量，表示有一个新空槽位可用
            empty.release()
            
            # 更新已消费商品计数
            consumed += 1
            
            # 打印消费信息
            safe_print(f'{print_bar()}  {cyan("Consumer"+str(cid))} ← {item}  '
                       f'(total={consumed})')
            
            # 模拟消费过程需要时间（随机休眠10-20秒）
            time.sleep(random.uniform(10, 20))
        else:
            # 超时未获取到满槽位信号量
            # 检查是否所有生产者都已完成且缓冲区为空
            if all(t.is_alive() is False for t in prod_threads) and len(buf)==0:
                # 如果是，则退出消费循环
                break
    
    # 消费者线程结束
    safe_print(f'Consumer{cid} 退出。')

# 主函数
def main():
    """主函数：初始化并启动所有线程"""
    # 清屏（Linux/Mac使用clear，Windows使用cls）
    os.system('clear' if os.name=='posix' else 'cls')
    
    # 显示程序标题和说明
    safe_print(cyan('=== 观察"缓冲区满"演示 ==='))
    safe_print('BUF_SIZE=5，生产慢/消费快，满时红底闪烁提示\n')
    
    # 创建全局变量存储生产者线程引用
    global prod_threads
    prod_threads = []
    
    # 创建并启动所有生产者线程
    for i in range(PRODUCERS):
        t = threading.Thread(target=producer, args=(i,))  # 创建生产者线程
        t.start()  # 启动线程
        prod_threads.append(t)  # 保存线程引用
    
    # 创建并启动所有消费者线程
    cons_threads = []
    for i in range(CONSUMERS):
        t = threading.Thread(target=consumer, args=(i,))  # 创建消费者线程
        t.start()  # 启动线程
        cons_threads.append(t)  # 保存线程引用
    
    # 等待所有生产者线程完成
    for t in prod_threads:
        t.join()
    
    # 等待所有消费者线程完成
    for t in cons_threads:
        t.join()
    
    # 所有线程完成后显示结束信息
    safe_print(yellow('\n全部结束。'))

# 程序入口点
if __name__ == '__main__':
    main()  # 调用主函数
