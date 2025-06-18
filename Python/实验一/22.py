# 编写程序, 利用循环结构,使用turtle库的turtle.circle()函数
# turtle.seth()函数和turtle.left()函数绘制一个四瓣花图形,从左上角花瓣开始
import turtle

# 初始化设置
pen = turtle.Turtle()
# pen.speed(10)
# pen.pensize(3)
# pen.color("red", "pink")

# 调整初始位置和角度
# pen.penup()

# pen.goto(0, 0)
# pen.setheading(90)  # 初始朝上
pen.pendown()

# 单循环绘制四瓣花（核心改进部分）
# pen.begin_fill()
for i in range(4):
    pen.circle(100, 180)  # 绘制半圆花瓣
    pen.left(90)          # 每次旋转90度（360/4）
# pen.end_fill()

# 完成绘制
pen.hideturtle()
turtle.done()
