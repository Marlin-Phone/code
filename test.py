n, a, b = input().split()

# 将字符串转换为整数或浮点数，以便进行数值比较
n = int(n)
a = int(a)
b = int(b)

if n * a < b:
    print(n * a)
else:
    print(b)
