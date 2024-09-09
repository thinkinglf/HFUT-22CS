import random
import string


# 随机生成指定长度的字符串
def generate_random_string(length):
    return ''.join(random.choice(string.ascii_letters + string.digits) for _ in range(length))


num = int(input("请输入生成字符串的个数："))
length = int(input("请输入生成字符串的长度："))

strings_to_write = [generate_random_string(length) for _ in range(num)]

# 将字符串写入文件
file_path = "strings_file.txt"
with open(file_path, "w") as file:
    for string in strings_to_write:
        file.write(string + "\n")

# 读取文件并统计字符串个数
with open(file_path, "r") as file:
    read_strings = file.readlines()
    num_strings = len(read_strings)

print(f"读取到的字符串个数: {num_strings}")
print("读取到的字符串内容:")
for string in read_strings:
    print(string.strip())
