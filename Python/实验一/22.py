# 编写程序, 利用循环结构,使用turtle库的turtle.circle()函数
# turtle.seth()函数和turtle.left()函数绘制一个四瓣花图形,从左上角花瓣开始
import turtle

# 初始化设置
pen = turtle.Turtle()
pen.speed(5)
pen.pensize(3)
pen.color("red", "pink")

# 调整初始位置到左上花瓣起始点
pen.penup()
pen.goto(-100, 100)  # 左上角起始
pen.setheading(90)    # 初始朝上
pen.pendown()

# 使用循环绘制四瓣结构
pen.begin_fill()
for _ in range(2):
    # 绘制垂直半圆（上→下→上）
    pen.circle(100, 180)  # 向下半圆
    pen.left(90)           # 逆时针转90°
    
    # 绘制水平半圆（左→右→左）
    pen.circle(100, 180)  # 向右半圆
    pen.left(90)           # 再次逆时针转90°
pen.end_fill()

# 完成绘制
pen.hideturtle()
turtle.done()
