def fun(x):
    effect = 1.0
    for i in range(365):
        if (i % 7 == 0 or i % 7 == 6):
            effect *= (1 - 0.01)
        else:
            effect *= (1 + x)
    return effect


start = 0.01
while fun(start) < 37.78:
    start += 0.0001  # 暴力求解  每次提高0.01%
print(f"工作日每天努力近似提高{start:.2%}即可")
