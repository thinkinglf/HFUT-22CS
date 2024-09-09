import re

input_text = input("输入一段英文: ")

# 使用正则表达式查找长度为3的单词
three_letter_words = re.findall(r'\b[a-zA-Z]{3}\b', input_text)

print("输出字符串中所有长度为3的单词:")
print(three_letter_words)
