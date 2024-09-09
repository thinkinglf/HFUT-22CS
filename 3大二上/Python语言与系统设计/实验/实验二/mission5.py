import random

n = int(input("请输入整数元素的个数 n："))
m = int(input("请输入整数元素的最大值 m："))

# 使用生成器推导式生成包含 n 个整数元素的元组
original_tuple = tuple(random.randint(1, m) for _ in range(n))

# 使用生成器推导式过滤掉偶数整数
filtered_tuple = tuple(x for x in original_tuple if x % 2 != 0)

print("第一次生成的元组：", original_tuple)
print("过滤后的新元组：", filtered_tuple)
