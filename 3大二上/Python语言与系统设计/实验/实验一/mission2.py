import random

# 生成随机数字
target_number = random.randint(1, 100)

# 最大猜测次数
max_attempts = 5
attempts = 0

# 游戏主循环
while attempts < max_attempts:

    guess = int(input("猜一个数字（1到100之间）："))

    if guess < target_number:
        print("太小了！")
    elif guess > target_number:
        print("太大了！")
    else:
        print("恭喜你，猜对了！")
        print("游戏结束。正确答案是：", target_number)
        break

    attempts += 1

if attempts == max_attempts:
    print("游戏结束。你没有猜对。正确答案是：", target_number)
