import os.path

student_lst = []  # 记录学生的列表


class Student:
    def __init__(self, id, name, sex, age, classes, math, physics, python):
        self.id = id
        self.name = name
        self.sex = sex
        self.age = age
        self.classes = classes
        self.math = math
        self.physics = physics
        self.python = python
        self.average_score = round((self.math + self.physics + self.python) / 3, 2)

    def __toString__(self):  # 返回学生信息
        return (
            f"{self.id} {self.name} {self.sex} {self.age} {self.classes}班"
            f" 高数:{self.math} 大物:{self.physics} python:{self.python}"
            f" 平均分：{self.average_score}"
        )


def main():
    s1 = "学生信息管理系统"
    print(s1.center(20, "*"))
    s2 = "功能菜单"
    print(s2.center(22, "*"))
    print(5 * " " + "1.录入学生信息")
    print(5 * " " + "2.修改学生成绩")
    print(5 * " " + "3.显示成绩排名")
    print(5 * " " + "0.退出系统")
    print(24 * "*")


def add():
    while True:

        s_id = input("请输入您要添加学生的学号：")
        name = input("请输入您要添加学生的姓名：")
        sex = input("请输入您要添加学生的性别：")
        age = input("请输入您要添加学生的年龄：")
        classes = input("请输入您添加学生的班级：")

        while True:
            try:
                math = int(input("请输入您要添加学生的高数成绩："))
                physics = int(input("请输入您要添加学生的大物成绩:"))
                python = int(input("请输入您要添加学生的python成绩:"))
                break
            except:
                print("不是整数类型，请重新输入")
                continue

        student_lst.append(Student(s_id, name, sex, age, classes, math, physics, python))
        s = input("是否要继续添加学生(y or n):")
        if s == "y":
            continue
        elif s == "n":
            break
        else:
            print("输入错误")

    save(student_lst)  # 保存文件


def save(student_lst):  # 将学生信息存储到文件中
    try:
        stutxt = open("Student.txt", "a", encoding="utf-8")  # 追加形式
    except:
        stutxt = open("Student.txt", "w", encoding="utf-8")  # 文件不存在就创建并写入

    for item in student_lst:
        stutxt.write(item.__toString__() + "\n")

    stutxt.close()
    print("学生信息录入成功")


def modify():
    while True:
        stuid = input("请输入您想要修改学生的id：")

        studentld = []
        if os.path.exists("Student.txt"):
            with open("Student.txt", "r", encoding="utf-8") as file:
                studentld = file.readlines()  # 文件每行的内容

        flag = False

        if studentld:  # 文件存在并且不为空
            i = 0  # 记录读取的行数
            for element in studentld:  # 读取每行的内容
                each = element.split()  # 字符串分割
                if each[0] == stuid:
                    flag = True  # 找到了对于的id

                    name = each[1]  # 读取之前不需要修改的信息
                    sex = each[2]
                    age = each[3]
                    classes = each[4]

                    while True:
                        try:
                            math = int(input("请输入修改后学生的高数成绩："))
                            physics = int(input("请输入修改后学生的大物成绩:"))
                            python = int(input("请输入修改后学生的python成绩:"))
                            break
                        except:
                            print("不是整数类型，请重新输入")
                            continue

                    # 创建新的学生对象
                    s = Student(stuid, name, sex, age, classes, math, physics, python)

                    # 只修改查找到行的内容 防止修改文件后删除之前的内容  非常重要
                    studentld[i] = s.__toString__() + '\n'
                    with open("Student.txt", 'w', encoding='utf-8') as file:
                        file.writelines(studentld)  # 将新的内容写入文件中
                    print("修改成功")
                    break

                i += 1  # 行数+1

        if not flag:
            print("没有找到id为" + stuid + "的学生")

        question = input("是否要继续进行修改操作,请输入y or n:")
        if question == "y":
            continue
        else:
            break


def sort_and_show():
    temp = []
    with open("Student.txt", "r", encoding="utf-8") as w:
        lst = w.readlines()
    for item in lst:
        x = item.split()  # 要从文件中读取内容才行
        if x:
            for i in range(len(x)):
                if i == 0:
                    id = x[0]
                elif i == 1:
                    name = x[1]
                elif i == 2:
                    sex = x[2]
                elif i == 3:
                    age = x[3]
                elif i == 4:
                    classes = x[4][:-1]
                elif i == 5:
                    math = int(x[5][-2:])  # 成绩为整数   在对应字符串的最后两位
                elif i == 6:
                    physics = int(x[6][-2:])
                else:
                    python = int(x[7][-2:])
            temp.append(Student(id, name, sex, age, classes, math, physics, python))
    temp.sort(key=lambda x: x.average_score, reverse=True)  # 依据平均分降序排序

    for i in range(len(temp)):
        # 浮点数与字符串拼接要转化为字符串
        print("学生：", temp[i].name + " " +
              "平均分：" + str(temp[i].average_score) +
              " 排名为：", (i + 1))


while True:
    main()
    choose = int(input("请输入您的选择："))

    if choose == 1:
        add()
    elif choose == 2:
        modify()
    elif choose == 3:
        sort_and_show()
    elif choose == 0:
        break
    else:
        print("输入错误，请重新输入")
