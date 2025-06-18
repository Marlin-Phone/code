# 统计字符串中英文字母,数字,空格和其他字符的个数

string = input("请输入字符串：")

letter_count = 0
digit_count = 0
space_count = 0
other_count = 0

for char in string:
    if char >= 'a' and char <= 'z' or char >= 'A' and char <= 'Z':
        letter_count += 1
    elif char >= '0' and char <= '9':
        digit_count += 1
    elif char == ' ':
        space_count += 1
    else:
        other_count += 1

print("字母个数：", letter_count)
print("数字个数：", digit_count)
print("空格个数：", space_count)
print("其他字符个数：", other_count)