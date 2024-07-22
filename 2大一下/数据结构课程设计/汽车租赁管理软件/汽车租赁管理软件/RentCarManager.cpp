#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

// ����������
class Car {
public:
    string plate;   //���ƺ���
    string brand;   //��Ʒ��
    double price;   //�⳵�۸�
    bool is_rented; //�Ƿ����
    int     time;   //�⳵ʱ��
    Car(string p, string b, double pr) : plate(p), brand(b), price(pr), is_rented(false) {}
};

// �����������޹���ϵͳ��
class CarManager {
private:
    vector<Car> car_list; //�����б�

public:
    CarManager() {} //���캯��

    void loadCarsFromFile() { //���ļ���ȡ������Ϣ
        ifstream input_file("cars.txt");
        string plate, brand;
        double price;
        while (input_file >> plate >> brand >> price) {
            car_list.push_back(Car(plate, brand, price));
        }
        input_file.close();
    }

    void saveCarsToFile() { //��������Ϣ���浽�ļ�
        ofstream output_file("cars.txt");
        for (int i = 0; i < car_list.size(); i++) {
            output_file << car_list[i].plate << " " << car_list[i].brand << " " << car_list[i].price << endl;
        }
        output_file.close();
    }

    void addCar() { //��ӳ���
        string plate, brand;
        double price;
        cout << "�����복���ĳ��ƺ���: ";
        cin >> plate;
        cout << "�����복��Ʒ��: ";
        cin >> brand;
        cout << "�������⳵�۸�: ";
        cin >> price;
        car_list.push_back(Car(plate, brand, price));
        saveCarsToFile();
    }

    void removeCar() { //ɾ������
        string plate;
        cout << "������Ҫɾ�������ĳ��ƺ���: ";
        cin >> plate;
        for (int i = 0; i < car_list.size(); i++) {
            if (car_list[i].plate == plate) {
                car_list.erase(car_list.begin() + i);
                saveCarsToFile();
                cout << "ɾ���ɹ���" << endl;
                return;
            }
        }
        cout << "δ�ҵ��ó�����" << endl;
    }

    void modifyCar() { //�޸ĳ�����Ϣ
        string plate;
        cout << "������Ҫ�޸ĳ�����Ϣ�ĳ��ƺ���: ";
        cin >> plate;
        for (int i = 0; i < car_list.size(); i++) {
            if (car_list[i].plate == plate) {
                cout << "������Ҫ�޸ĵĳ�����Ϣ(���ƺ��롢��Ʒ�ơ��⳵�۸��ÿո�ָ�): ";
                cin >> car_list[i].plate >> car_list[i].brand >> car_list[i].price;
                saveCarsToFile();
                return;
            }
        }
        cout << "δ�ҵ��ó�����" << endl;
    }

    void rentCar() { //�⳵
        string plate;
        cout << "������Ҫ���õĳ������ƺ���: ";
        cin >> plate;
        for (int i = 0; i < car_list.size(); i++) {
            if (car_list[i].plate == plate) {
                if (car_list[i].is_rented) { //�Ѿ�������
                    cout << "�ó��ѱ����ã�" << endl;
                }
                else { //δ������
                    car_list[i].is_rented = true;
                    cout << "����������⳵ʱ��:";
                    int m_time; cin >> m_time;
                    car_list[i].time = m_time;
                    cout << "���óɹ���" << endl;
                }
                saveCarsToFile();
                return;
            }
        }
        cout << "δ�ҵ��ó�����" << endl;
    }

    void returnCar() { //�黹����
        string plate;
        double  total_price;
        cout << "������Ҫ�黹�ĳ������ƺ���: ";
        cin >> plate;
        for (int i = 0; i < car_list.size(); i++) {
            if (car_list[i].plate == plate) {
                if (car_list[i].is_rented) { // �Ѿ�������
                    car_list[i].is_rented = false;
             
                    total_price = car_list[i].time * car_list[i].price;
                    cout << "����ܶ�: " << total_price << " Ԫ" << endl;
                    saveCarsToFile();
                }
                else { // δ������
                    cout << "�ó�δ�����ã�����黹��" << endl;
                }
                return;
            }
        }
        cout << "δ�ҵ��ó�����" << endl;
    }

    void showCars() { //չʾ���г�����Ϣ
        cout << "����\t" << "����\t" << "��Ʒ��\t" << "�⳵�۸�״̬\t" << endl;
        for (int i = 0; i < car_list.size(); i++) {
            cout << car_list[i].plate << "\t" << car_list[i].brand << "\t" << car_list[i].price << "\t" << (car_list[i].is_rented ? "������" : "δ����") << endl;
        }
    }

    void showStats() { //չʾ�����ʺͳ������
        int total_num = car_list.size(); //�ܳ�����
        int rented_num = 0;              //�ѳ��⳵����
        double total_fee = 0;            //��������ܶ�
        for (int i = 0; i < car_list.size(); i++) {
            if (car_list[i].is_rented) {
                rented_num++;
                total_fee += car_list[i].price * car_list[i].time;
            }
        }
        double rent_rate = (double)rented_num / total_num * 100;
        cout << "������: " << rent_rate << "%" << endl;
        cout << "��������ܶ�: " << total_fee << " Ԫ" << endl;
    }
};

int main() {
    CarManager manager;
    manager.loadCarsFromFile();
    while (true) {
        cout << "*********��ӭʹ���������޹���ϵͳ***********" << endl;
        cout << "*******     1.����µĳ���              ****" << endl;
        cout << "*******     2.ɾ�����г���              ****" << endl;
        cout << "*******     3.�޸ĳ�����Ϣ              ****" << endl;
        cout << "*******     4.���ó���                  ****" << endl;
        cout << "*******     5.�黹����                  ****" << endl;
        cout << "*******     6.չʾ���еĳ�����Ϣ        ****" << endl;
        cout << "*******     7.ͳ��Ŀǰ�ĳ����ʺͳ������****" << endl;
        cout << "*******     0.�˳�����                  ****" << endl;
        cout << "********************************************" << endl;
        cout << "��ѡ��������Ҫִ�еĲ���: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            manager.addCar();//����µĳ���
            system("pause");
            system("cls");
            break;
        case 2:
            manager.removeCar();//ɾ�����г���
            system("pause");
            system("cls");
            break;
        case 3:
            manager.modifyCar();//�޸ĳ�����Ϣ
            system("pause");
            system("cls");
            break;
        case 4:
            manager.rentCar();//���ó���
            system("pause");
            system("cls");
            break;
        case 5:
            manager.returnCar();//�黹����
            system("pause");
            system("cls");
            break;
        case 6:
            manager.showCars();//չʾ���еĳ�����Ϣ
            system("pause");
            system("cls");
            break;
        case 7:
            manager.showStats();//ͳ��Ŀǰ�ĳ����ʺͳ������
            system("pause");
            system("cls");
            break;
        case 0:
        {
            manager.saveCarsToFile();//�˳�����
            cout << "��ӭ�����´�ʹ��" << endl << "�ټ�";
            system("pause");
            system("cls");
            return 0;
        }
        default:
        {
            cout << " ����������������룡" << endl;
            system("pause");
            system("cls");
        }
        }
    }
    return 0;
}
