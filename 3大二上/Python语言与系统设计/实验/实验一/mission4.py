def max_crossed_substring_length(str1, str2):
    # 计算两个字符串的最大交叉子串长度
    max_length = lambda x, y: sum([1 for i, j in zip(x[::-1], y) if i == j])

    cross_length = max_length(str1, str2)

    # 连接两个字符串，首尾交叉部分只保留一份
    result = str1 + str2[cross_length:]
    return result


s1 = input("请输入第一个字符串: ")
s2 = input("请输入第二个字符串: ")

result = max_crossed_substring_length(s1, s2)
print("连接后的字符串：", result)
