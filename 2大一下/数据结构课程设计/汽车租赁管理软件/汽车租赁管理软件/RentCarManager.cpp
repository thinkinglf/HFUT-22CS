#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

// 定义汽车类
class Car {
public:
    string plate;   //车牌号码
    string brand;   //车品牌
    double price;   //租车价格
    bool is_rented; //是否出租
    int     time;   //租车时间
    Car(string p, string b, double pr) : plate(p), brand(b), price(pr), is_rented(false) {}
};

// 定义汽车租赁管理系统类
class CarManager {
private:
    vector<Car> car_list; //车辆列表

public:
    CarManager() {} //构造函数

    void loadCarsFromFile() { //从文件读取车辆信息
        ifstream input_file("cars.txt");
        string plate, brand;
        double price;
        while (input_file >> plate >> brand >> price) {
            car_list.push_back(Car(plate, brand, price));
        }
        input_file.close();
    }

    void saveCarsToFile() { //将车辆信息保存到文件
        ofstream output_file("cars.txt");
        for (int i = 0; i < car_list.size(); i++) {
            output_file << car_list[i].plate << " " << car_list[i].brand << " " << car_list[i].price << endl;
        }
        output_file.close();
    }

    void addCar() { //添加车辆
        string plate, brand;
        double price;
        cout << "请输入车辆的车牌号码: ";
        cin >> plate;
        cout << "请输入车辆品牌: ";
        cin >> brand;
        cout << "请输入租车价格: ";
        cin >> price;
        car_list.push_back(Car(plate, brand, price));
        saveCarsToFile();
    }

    void removeCar() { //删除车辆
        string plate;
        cout << "请输入要删除车辆的车牌号码: ";
        cin >> plate;
        for (int i = 0; i < car_list.size(); i++) {
            if (car_list[i].plate == plate) {
                car_list.erase(car_list.begin() + i);
                saveCarsToFile();
                cout << "删除成功！" << endl;
                return;
            }
        }
        cout << "未找到该车辆！" << endl;
    }

    void modifyCar() { //修改车辆信息
        string plate;
        cout << "请输入要修改车辆信息的车牌号码: ";
        cin >> plate;
        for (int i = 0; i < car_list.size(); i++) {
            if (car_list[i].plate == plate) {
                cout << "请输入要修改的车辆信息(车牌号码、车品牌、租车价格，用空格分隔): ";
                cin >> car_list[i].plate >> car_list[i].brand >> car_list[i].price;
                saveCarsToFile();
                return;
            }
        }
        cout << "未找到该车辆！" << endl;
    }

    void rentCar() { //租车
        string plate;
        cout << "请输入要租用的车辆车牌号码: ";
        cin >> plate;
        for (int i = 0; i < car_list.size(); i++) {
            if (car_list[i].plate == plate) {
                if (car_list[i].is_rented) { //已经被租用
                    cout << "该车已被租用！" << endl;
                }
                else { //未被租用
                    car_list[i].is_rented = true;
                    cout << "请输入你的租车时间:";
                    int m_time; cin >> m_time;
                    car_list[i].time = m_time;
                    cout << "租用成功！" << endl;
                }
                saveCarsToFile();
                return;
            }
        }
        cout << "未找到该车辆！" << endl;
    }

    void returnCar() { //归还车辆
        string plate;
        double  total_price;
        cout << "请输入要归还的车辆车牌号码: ";
        cin >> plate;
        for (int i = 0; i < car_list.size(); i++) {
            if (car_list[i].plate == plate) {
                if (car_list[i].is_rented) { // 已经被租用
                    car_list[i].is_rented = false;
             
                    total_price = car_list[i].time * car_list[i].price;
                    cout << "租金总额: " << total_price << " 元" << endl;
                    saveCarsToFile();
                }
                else { // 未被租用
                    cout << "该车未被租用，无需归还！" << endl;
                }
                return;
            }
        }
        cout << "未找到该车辆！" << endl;
    }

    void showCars() { //展示所有车辆信息
        cout << "车牌\t" << "号码\t" << "车品牌\t" << "租车价格状态\t" << endl;
        for (int i = 0; i < car_list.size(); i++) {
            cout << car_list[i].plate << "\t" << car_list[i].brand << "\t" << car_list[i].price << "\t" << (car_list[i].is_rented ? "已租用" : "未租用") << endl;
        }
    }

    void showStats() { //展示出租率和出租费用
        int total_num = car_list.size(); //总车辆数
        int rented_num = 0;              //已出租车辆数
        double total_fee = 0;            //出租费用总额
        for (int i = 0; i < car_list.size(); i++) {
            if (car_list[i].is_rented) {
                rented_num++;
                total_fee += car_list[i].price * car_list[i].time;
            }
        }
        double rent_rate = (double)rented_num / total_num * 100;
        cout << "出租率: " << rent_rate << "%" << endl;
        cout << "出租费用总额: " << total_fee << " 元" << endl;
    }
};

int main() {
    CarManager manager;
    manager.loadCarsFromFile();
    while (true) {
        cout << "*********欢迎使用汽车租赁管理系统***********" << endl;
        cout << "*******     1.添加新的车辆              ****" << endl;
        cout << "*******     2.删除已有车辆              ****" << endl;
        cout << "*******     3.修改车辆信息              ****" << endl;
        cout << "*******     4.租用车辆                  ****" << endl;
        cout << "*******     5.归还车辆                  ****" << endl;
        cout << "*******     6.展示现有的车辆信息        ****" << endl;
        cout << "*******     7.统计目前的出租率和出租费用****" << endl;
        cout << "*******     0.退出程序                  ****" << endl;
        cout << "********************************************" << endl;
        cout << "请选择您现在要执行的操作: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            manager.addCar();//添加新的车辆
            system("pause");
            system("cls");
            break;
        case 2:
            manager.removeCar();//删除已有车辆
            system("pause");
            system("cls");
            break;
        case 3:
            manager.modifyCar();//修改车辆信息
            system("pause");
            system("cls");
            break;
        case 4:
            manager.rentCar();//租用车辆
            system("pause");
            system("cls");
            break;
        case 5:
            manager.returnCar();//归还车辆
            system("pause");
            system("cls");
            break;
        case 6:
            manager.showCars();//展示现有的车辆信息
            system("pause");
            system("cls");
            break;
        case 7:
            manager.showStats();//统计目前的出租率和出租费用
            system("pause");
            system("cls");
            break;
        case 0:
        {
            manager.saveCarsToFile();//退出程序
            cout << "欢迎您的下次使用" << endl << "再见";
            system("pause");
            system("cls");
            return 0;
        }
        default:
        {
            cout << " 输入错误，请重新输入！" << endl;
            system("pause");
            system("cls");
        }
        }
    }
    return 0;
}
