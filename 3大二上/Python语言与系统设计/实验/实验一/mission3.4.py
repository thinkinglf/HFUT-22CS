import random


def generate_random_tuple(n):
    total = 0
    random_numbers = []

    for i in range(n):
        num = random.randint(0, 100)
        random_numbers.append(num)
        total += num
    print("生成的随机列表是", random_numbers)  # 打印随机列表
    average = total / n
    temp = [average]
    for i in range(n):
        if random_numbers[i] > average:
            temp.append(random_numbers[i])
    return tuple(temp)  # 返回指定元组


n = int(input('请输入随机列表长度n：'))

result_tuple = generate_random_tuple(n)
print("返回的元组是", result_tuple)
