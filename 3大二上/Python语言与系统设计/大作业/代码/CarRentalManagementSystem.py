import os
import os


class Car:  # 汽车类  包含汽车的基本信息
    def __init__(self, plate, brand, price):
        self.plate = plate  # 车牌号
        self.brand = brand  # 品牌
        self.price = price  # 每个小时的租金
        self.is_rented = False  # 是否已经出租
        self.time = 0  # 使用时间


class CarManager:
    def __init__(self):
        self.car_list = []  # 存储汽车信息的列表，存储着不同Car的对象

    def load_cars_from_file(self):  # 读取文件中的信息
        try:
            with open("cars.txt", "r") as ct:
                for line in ct:
                    plate, brand, price = line.split()
                    self.car_list.append(Car(plate, brand, float(price)))
        except FileNotFoundError:  # 文件不存在时，将创建一个新文件。
            print("文件不存在，将创建一个新文件。")
            # 创建一个新文件并继续
            with open("cars.txt", "w") as ct:
                pass  # 这里先不做任何操作，只是创建一个空文件

    def save_cars_to_file(self):  # 保存信息到文件中
        with open("cars.txt", "w") as ct:
            for car in self.car_list:
                # 将车牌号   车的品牌    车的每小时租金存入文件录入系统
                ct.write(f"{car.plate} {car.brand} {car.price}\n")

    def add_car(self):  # 添加新的汽车
        plate = input("请输入车辆的车牌号: ")
        brand = input("请输入车辆品牌: ")
        price = float(input("请输入租车价格: "))
        self.car_list.append(Car(plate, brand, price))
        self.save_cars_to_file()

    def remove_car(self):  # 依据车牌号删除汽车
        plate = input("请输入要删除车辆的车牌号: ")
        for car in self.car_list:
            if car.plate == plate:
                self.car_list.remove(car)
                self.save_cars_to_file()
                print("删除成功！")
                return
        print("未找到该车辆！")

    def modify_car(self):  # 依据车牌号修改汽车
        plate = input("请输入要修改车辆信息的车牌号: ")
        for car in self.car_list:
            if car.plate == plate:
                car.plate, car.brand, car.price = input("请输入新的车辆信息(车牌号、车品牌、租车价格，用空格分隔): ").split()
                car.price = float(car.price)
                self.save_cars_to_file()
                return
        print("未找到该车辆！")

    def rent_car(self):  # 出租汽车
        plate = input("请输入要租用的车辆车牌号: ")
        for car in self.car_list:
            if car.plate == plate:
                if car.is_rented:
                    print("该车已被租用！")
                else:
                    car.is_rented = True
                    car.time = int(input("请输入你的租车时间: "))
                    print("租用成功！")
                self.save_cars_to_file()
                return
        print("未找到该车辆！")

    def return_car(self):  # 归还汽车
        plate = input("请输入要归还车辆的车牌号: ")
        for car in self.car_list:
            if car.plate == plate:
                if car.is_rented:
                    car.is_rented = False  # 归还后将车变成未租用状态
                    total_price = int(car.time * car.price)
                    print(f"租金总额: {total_price} 元")
                    self.save_cars_to_file()
                else:
                    print("该车未被租用，无需归还！")
                return
        print("未找到该车辆！")

    def show_cars(self):  # 展示现有的汽车信息
        if not self.car_list:
            print("目前系统内还没有车辆")
        else:
            print("车牌号\t车品牌\t租金\t状态")
            for car in self.car_list:
                print(f"{car.plate}\t{car.brand}\t{car.price}\t{'已租用' if car.is_rented else '未租用'}")

    def show_stats(self):  # 展示目前的出租状况
        total_num = len(self.car_list)
        # 已出租的车辆
        rented_num = sum(1 for car in self.car_list if car.is_rented)
        # 已赚取的总金额
        total_fee = sum(car.price * car.time for car in self.car_list if car.is_rented)
        rent_rate = (rented_num / total_num) * 100 if total_num != 0 else 0
        print(f"系统内汽车的出租率: {rent_rate:.2f}%")
        print(f"系统已赚取的总金额: {total_fee:.2f} 元")


def main():
    manager = CarManager()
    manager.load_cars_from_file()
    while True:
        print("*******    欢迎使用汽车管家         *********")
        print("*******     1.添加新的车辆              ****")
        print("*******     2.删除已有车辆              ****")
        print("*******     3.修改车辆信息              ****")
        print("*******     4.租用车辆                  ****")
        print("*******     5.归还车辆                  ****")
        print("*******     6.展示现有的车辆信息         ****")
        print("*******     7.统计目前的出租率和赚取金额 ****")
        print("*******     0.退出程序                  ****")
        print("********************************************")
        choice = input("请选择您现在要执行的操作: ")
        if choice.isdigit():  # 检查字符串是否由数字字符组成
            choice = int(choice)
            if 0 <= choice <= 7:
                if choice == 1:
                    manager.add_car()
                elif choice == 2:
                    manager.remove_car()
                elif choice == 3:
                    manager.modify_car()
                elif choice == 4:
                    manager.rent_car()
                elif choice == 5:
                    manager.return_car()
                elif choice == 6:
                    manager.show_cars()
                elif choice == 7:
                    manager.show_stats()
                else:
                    manager.save_cars_to_file()
                    print("欢迎您的下次使用\n再见")
                    break
            else:
                print("输入错误，请重新输入！")
        else:
            print("输入错误，请重新输入！")


main()
