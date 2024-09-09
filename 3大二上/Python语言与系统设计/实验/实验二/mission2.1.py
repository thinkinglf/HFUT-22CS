setA = set(input("输入集合A（用逗号分隔元素）: ").split(','))
setB = set(input("输入集合B（用逗号分隔元素）: ").split(','))

# 计算交集、差集和并集
intersection = setA.intersection(setB)
difference_A_B = setA.difference(setB)
difference_B_A = setB.difference(setA)
union = setA.union(setB)

print("交集：", intersection)
print("差集（A - B）：", difference_A_B)
print("差集（B - A）：", difference_B_A)
print("并集：", union)
