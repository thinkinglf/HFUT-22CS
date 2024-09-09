class Employee:
    def __init__(self, name, emp_id, monthly_salary):
        self.name = name
        self.emp_id = emp_id
        self.monthly_salary = monthly_salary

    def pay(self):
        pass  # 暂时不写入内容

    def show(self):
        pass


class Manager(Employee):
    def __init__(self, name, emp_id, monthly_salary):
        super().__init__(name, emp_id, monthly_salary)

    def pay(self):
        # 调用父类的 pay 方法
        super().pay()
        # 添加 Manager 特有的逻辑
        print(f'Manager的月薪为：{self.monthly_salary}')

    def show(self):
        # 调用父类的 show 方法
        super().show()
        # 添加 Manager 特有的逻辑
        print(f'Manager信息为 姓名：{self.name}，ID: {self.emp_id}，月薪：{self.monthly_salary}')


class Salesman(Employee):
    def __init__(self, name, emp_id, monthly_salary):
        super().__init__(name, emp_id, monthly_salary)

    def pay(self):
        # 调用父类的 pay 方法
        super().pay()
        # 添加 Salesman 特有的逻辑
        print(f'Salesman的月薪为：{self.monthly_salary}')

    def show(self):
        # 调用父类的 show 方法
        super().show()
        # 添加 Salesman 特有的逻辑
        print(f'Salesman的信息为 姓名：{self.name}，ID: {self.emp_id}，月薪：{self.monthly_salary}')


def main():
    name = input("请输入Manager的姓名:")
    id = input("请输入Manager的ID:")
    monthly_salary = input("请输入Manager的月薪:")

    manager = Manager(name, id, monthly_salary)

    name = input("请输入Salesman的姓名:")
    id = input("请输入Salesman的ID:")
    monthly_salary = input("请输入Salesman的月薪:")
    salesman = Salesman(name, id, monthly_salary)

    print("-----------------------")
    manager.pay()
    salesman.pay()
    print("-----------------------")
    manager.show()
    salesman.show()


main()
