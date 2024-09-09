class MyQueue:
    def __init__(self, size):
        self.size = size  # 最大长度
        self.data = []  # 所有数据
        self.current = 0  # 元素个数

    def is_empty(self):
        return self.current == 0

    def is_full(self):
        return self.current == self.size

    def front(self):  # 获取队头元素
        if not self.is_empty():
            return self.data[0]
        else:
            print("队列为空，无法获取队头元素")

    def enqueue(self, element):  # 入队
        if not self.is_full():
            self.data.append(element)
            self.current += 1
            print(f"入队成功，当前队列元素个数为 {self.current}")
        else:
            print("队列已满，无法入队")

    def dequeue(self):  # 出队
        if not self.is_empty():
            removed_element = self.data.pop(0)
            self.current -= 1
            print(f"出队成功，当前队列元素个数为 {self.current}")
            return removed_element
        else:
            print("队列为空，无法出队")


# 主函数
def main():
    N = int(input("请输入队列的最大长度 N: "))
    my_queue = MyQueue(N)

    print(f"队列是否为空: {my_queue.is_empty()}")
    print(f"队列是否为满: {my_queue.is_full()}")

    num = int(input("请输入要添加元素的个数:"))
    for i in range(num):
        x = int(input("请输入想要入队的元素:"))
        my_queue.enqueue(x)

    print("----------------------------")
    print(f"队头元素: {my_queue.front()}")
    removed_element = my_queue.dequeue()
    print(f"出队元素: {removed_element}")
    print(f"队列是否为空: {my_queue.is_empty()}")
    print(f"队列是否为满: {my_queue.is_full()}")


main()
