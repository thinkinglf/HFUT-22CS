input_string = input("输入任意长度的字符串: ")

# 将字符串按空格分割成单词，并统计每个单词出现的次数
word_count = {}
words = input_string.split()
for word in words:
    # 使用字典的get方法获取单词出现的次数，如果单词不存在则默认为0，然后加1
    word_count[word] = word_count.get(word, 0) + 1

print("每个单词出现的次数:")
for word, count in word_count.items():
    print(f"{word}: {count}")
