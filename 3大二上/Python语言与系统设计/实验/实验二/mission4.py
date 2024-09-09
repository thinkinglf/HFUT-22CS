import random

num_elements = int(input("输入列表元素个数: "))

# 生成整型列表
random_list = [random.randint(0, 100) for _ in range(num_elements)]
print("随机生成的整型列表:", random_list)

# 原列表
new_list = random_list[:]
print("包含原列表中所有元素的新列表:", new_list)

# 逆序列表
reverse_list = random_list[::-1]
print("原列表中所有元素的逆序列表:", reverse_list)

# 具有偶数位置(下标为偶数)的元素列表
even_position_list = random_list[::2]
print("具有偶数位置(下标偶数)的元素列表:", even_position_list)
