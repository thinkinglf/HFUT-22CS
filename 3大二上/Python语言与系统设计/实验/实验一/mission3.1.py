def fibonacci_less_than_n(n):
    fib_list = []
    a, b = 0, 1
    while a < n:
        fib_list.append(a)
        a, b = b, a + b
    return fib_list


n = int(input("请输入一个整数 n："))
result = fibonacci_less_than_n(n)
print("斐波那契数列中小于", n, "的所有值为:", result)
