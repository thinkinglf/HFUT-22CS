class CustomSet:
    def __init__(self, elements):
        self.elements = set(elements)

    def intersection(self, other_set):
        return CustomSet(element for element in self.elements if element in other_set.elements)

    def difference(self, other_set):
        return CustomSet(element for element in self.elements if element not in other_set.elements)

    def union(self, other_set):
        return CustomSet(self.elements.union(other_set.elements))

    def __repr__(self):
        return str(self.elements)


setA = CustomSet(input("输入集合A（用逗号分隔元素）: ").split(','))
setB = CustomSet(input("输入集合B（用逗号分隔元素）: ").split(','))

# 计算交集、差集和并集
intersection = setA.intersection(setB)
difference_A_B = setA.difference(setB)
difference_A_B = setB.difference(setA)
union = setA.union(setB)

print("交集：", intersection)
print("差集（A - B）：", difference_A_B)
print("差集（B - A）：", difference_A_B)
print("并集：", union)
