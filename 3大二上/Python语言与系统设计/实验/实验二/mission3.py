import random
import string

#随机生成要求的列表
def generate_nested_list(n, m):
    nested_list = []
    for _ in range(n):
        sub_list = [''.join(random.choices(string.ascii_letters + string.digits, k=random.randint(1, m))) for _ in
                    range(random.randint(1, m))]
        nested_list.append(sub_list)
    return nested_list

#列表内元素降序
def sort_nested_list(nested_list):
    for sub_list in nested_list:
        sub_list.sort(key=len, reverse=True)
    return nested_list


n = int(input("输入嵌套列表中元素的个数n: "))
m = int(input("输入每个元素的最大长度m: "))

nested_list = generate_nested_list(n, m)
sorted_list = sort_nested_list(nested_list)
print("生成的列表：", nested_list)
print("降序后的列表", sorted_list)
