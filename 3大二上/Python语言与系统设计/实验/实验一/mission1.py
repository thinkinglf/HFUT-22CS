import random

# 生成随机数字
target_number = random.randint(1, 100)

# 用户输入猜测的数字
guess = int(input("猜一个数字（1到100之间）："))

if guess < target_number:
    print("太小了！")
    print("游戏结束。正确答案是：", target_number)
elif guess > target_number:
    print("太大了！")
    print("游戏结束。正确答案是：", target_number)
else:
    print("恭喜你，猜对了！")
    print("游戏结束。正确答案是：", target_number)
