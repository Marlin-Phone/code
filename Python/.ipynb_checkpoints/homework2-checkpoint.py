# 导入所需库
import pandas as pd
import matplotlib.pyplot as plt
# %matplotlib inline  # 确保图表在Notebook中显示

# (1) 导入数据包、读取数据csv文件、查看前10行数据
# 定义列名（根据数据集描述）
column_names = [
    'CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 
    'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT', 'MEDV'
]

# 读取CSV文件（确保文件路径正确）
df = pd.read_csv('housing.csv', header=None, names=column_names, delim_whitespace=True)

# 查看前10行数据
print("前10行数据：")
print(df.head(10))  # 在Jupyter中美观显示

# (2) 数据的描述统计
print("\n描述性统计：")
print(df.describe())

# (3) 绘制数据的箱形图
plt.figure(figsize=(14, 10))
df.plot(kind='box', vert=True, patch_artist=True)
plt.title('Boston Housing Dataset Boxplot')
plt.xticks(rotation=45)  # 旋转x轴标签
plt.tight_layout()
plt.savefig('boxplot.png')  # 保存图片（可选）
plt.show()

# (4) 查看数据的10%和90%分位数，查看目标值
# 计算所有数值列的分位数
quantiles = df.quantile([0.1, 0.9])

print("\n10%和90%分位数：")
print(quantiles)

# 单独查看目标值(MEDV)的分位数
medv_quantiles = df['MEDV'].quantile([0.1, 0.9])
print("\n目标值(MEDV)的10%和90%分位数：")
print(medv_quantiles)