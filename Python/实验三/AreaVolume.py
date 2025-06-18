import math
def area(r):
    area = math.pi * r ** 2
    return area

def volume(r):
    volume = (4/3) * math.pi * r ** 3
    return volume

if __name__ == '__main__':
    r = float(input("请输入半径:"))
    print(f"圆的面积: {area(r):.2f}")
    print(f"球的体积: {volume(r):.2f}")
