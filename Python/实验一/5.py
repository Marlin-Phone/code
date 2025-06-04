def getValue(b, r, n):
    """
    计算复利最终收益
    :param b: 本金
    :param r: 年利率（小数形式，如0.05表示5%）
    :param n: 年数
    :return: 最终收益（保留两位小数）
    """
    amount = b * (1 + r) ** n  # 复利计算公式
    interest = amount - b       # 总利息
    print(f"最终收益: {amount:.2f} 元")  # 保留2位小数
    print(f"总利息: {interest:.2f} 元")
    return round(amount, 2)     # 返回数值结果

# 示例使用
getValue(10000, 0.05, 3)  # 1万元本金，年利率5%，存3年
