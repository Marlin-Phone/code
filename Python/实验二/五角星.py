import turtle

# 设置画布
screen = turtle.Screen()
screen.title("五角星绘制")
screen.bgcolor("white")

# 创建海龟对象
star = turtle.Turtle()
star.shape("turtle")  # 设置海龟形状
star.color("red")     # 设置海龟颜色
star.speed(5)         # 设置绘制速度（1-10，10最快）

# 开始绘制五角星
star.penup()          # 抬起画笔（移动到起始位置时不画线）
star.goto(-50, 0)     # 移动到起始位置
star.pendown()        # 放下画笔（开始绘制）

# 填充五角星
star.begin_fill()     # 开始填充

# 绘制五角星的五个顶点
for _ in range(5):
    star.forward(100)  # 向前移动100像素
    star.right(144)    # 向右转144度（五角星的角度）

star.end_fill()       # 结束填充

# 添加文字说明
star.penup()
star.goto(0, -150)    # 移动到文字位置
star.color("blue")
star.write("五角星", align="center", font=("Arial", 24, "bold"))

# 完成绘制
star.hideturtle()     # 隐藏海龟图标
turtle.done()         # 保持窗口打开