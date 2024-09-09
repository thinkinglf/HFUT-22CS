class Vehicle:
    def __init__(self, max_speed, weight):
        self.__max_speed = max_speed  # 将父类属性设为私有
        self.__weight = weight  # 将父类属性设为私有

    def MaxSpeed(self, value):
        self.__max_speed = value
        return self.__max_speed


class Bicycle(Vehicle):
    def __init__(self, max_speed, weight, height):
        super().__init__(max_speed, weight)
        self.__height = height  # 将子类属性设为私有

    @property
    def height(self):
        return self.__height

    @height.setter
    def height(self, value):
        self.__height = value


def main():
    max_speed = input("请输入Bicycle对象的max_speed：")
    weight = input("请输入Bicycle对象的weight：")
    height = input("请输入Bicycle对象的height：")

    bike = Bicycle(max_speed, weight, height)

    print("----------------")
    print(f"修改前 Max Speed: {bike.MaxSpeed(max_speed)}")
    speed = bike.MaxSpeed(input("请输入修改后的 MaxSpeed 值："))
    print(f"修改后 Max Speed: {bike.MaxSpeed(speed)}")

    print("----------------")
    # 利用 property 设置和获取 height 属性
    print(f"修改前 Height: {bike.height}")
    bike.height = input("请输入修改后的 height：")
    print(f"修改后 Height: {bike.height}")


main()
