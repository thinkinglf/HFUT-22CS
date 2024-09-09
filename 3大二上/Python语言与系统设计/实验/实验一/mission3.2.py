import math


def generate_primes(limit):
    primes = []
    for num in range(2, limit):
        is_prime = True
        for i in range(2, int(math.sqrt(num)) + 1):
            if num % i == 0:
                is_prime = False
                break
        if is_prime:
            primes.append(num)
    return primes


num = int(input("请输入一个大于2的自然数: "))
if num <= 2:
    print("输入错误，请输入大于2的数。")
else:
    primes_list = generate_primes(num)
    print(f"小于{num}的所有素数为：{primes_list}")
