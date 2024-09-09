import random
import string

# 生成包含1000个随机字符的字符串
random_string = ''.join(random.choices(string.ascii_letters, k=1000))
print("打印随机生成的字符串", random_string)

# 使用字典统计每个字符出现的次数
char_count = {}
for char in random_string:
    char_count[char] = char_count.get(char, 0) + 1

print("每个字符出现的次数（使用字典统计）：")
for char, count in char_count.items():
    print(f"{char}: {count}  ", end="")
