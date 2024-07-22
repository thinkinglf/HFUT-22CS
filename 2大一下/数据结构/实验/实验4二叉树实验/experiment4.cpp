#include"BiTree.h" 
#include<iostream>
#include <stdlib.h>
using namespace std;
int main() {
	char strLine[100][3];
	char fileName_1[100] = { "bt151.btr" };
	char fileName_2[100] = { "bt21.btr" };
	char fileName_3[100] = { "bt261.btr" };
	char fileName_4[100] = { "bt31.btr" };
	char fileName_5[100] = { "bt262.btr" };
	char fileName_6[100] = { "bt8.btr" };
	char fileName_7[100] = { "bt14.btr" };
	int nRow, Ye = 0, Du = 0;
	char X;
	bool f = false;
	bool f1 = false;
	char A[12] = { '0', '1', '2', '8', '3', '6', '0', '0', '4', '5', '0', '7' };
	char A1[22] = { '0', 'A', 'B', '0', 'C', 'I', '0', '0', 'D', 'F', 'J', '0', '0', '0', '0', '0', '0', 'E', 'G', '0', 'K', 'L' ,};
	char path[100];
	int pathlen;
	BiNode* T, * T1;//������
	char p, q;
	int choice;

	while (true) 
	{
		cout << "**************************************************************************************" << endl;
		cout << "*          1.�����������������и�����ֵ��������Ӧ�Ĳ����                        *" << endl;
		cout << "*          2.���������Ҷ�ӽ������1�Ƚ����                                         *" << endl;
		cout << "*          3.�󸸽ڵ㡢�ֵܽ�㡢�ӽ���ֵ(��ȷ����)                                *" << endl;
		cout << "*          4.�������еĲ��                                                          *" << endl;
		cout << "*          5.��˳��ʽ�洢�������еĶ�����ת��Ϊ��������������Ҫ��չΪ��ȫ��������*" << endl;
		cout << "*          6.��������ÿ��Ҷ�ӽ�㵽������·��                                      *" << endl;
		cout << "*          7.����α������ӡ                                                        *" << endl;
		cout << "*          8.�˳�����                                                                *" << endl;
		cout << "**************************************************************************************" << endl;

		cout << "������Ҫ������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "��������Ϊ��" << endl;
			cout << "��һ�����ݣ�bt151.btr" << endl;
			if (ReadFileToArray(fileName_1, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 15, nRow);
				outMidOrder(T, 1);
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "�ڶ������ݣ� bt21.btr" << endl;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 21, nRow);
				outMidOrder(T, 1);
			}
			DestroyBiTree(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			cout << "��������Ϊ��" << endl;
			cout << "��һ�����ݣ� bt261.btr" << endl;
			if (ReadFileToArray(fileName_3, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 26, nRow);
				Ye = 0;
				Du = 0;
				YeAnd1Du(T, Ye, Du);
				cout << "Ҷ�ӽ�����Ϊ��" << Ye << endl;
				cout << "1�Ƚ�����Ϊ��" << Du << endl;
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "�ڶ������ݣ� bt21.btr" << endl;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 21, nRow);
				Ye = 0;
				Du = 0;
				YeAnd1Du(T, Ye, Du);
				cout << "Ҷ�ӽ�����Ϊ��" << Ye << endl;
				cout << "1�Ƚ�����Ϊ��" << Du << endl;
			}
			DestroyBiTree(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			cout << "��������Ϊ��" << endl;
			cout << "��һ�����ݣ� bt31.btr" << endl;
			cout << "������Ԫ��X" << endl;
			cin >> X;
			if (ReadFileToArray(fileName_4, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 31, nRow);
				f = false;
				find(T, X, f);
				if (f == false) {
					cout << "û�иý��" << endl;
				}
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "�ڶ������ݣ� bt21.btr" << endl;
			cout << "������Ԫ��X" << endl;
			cin >> X;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 21, nRow);
				f = false;
				find(T, X, f);
				if (f == false) {
					cout << "û�иý��" << endl;
				}
			}
			DestroyBiTree(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			cout << "��������Ϊ��" << endl;
			cout << "��һ�����ݣ� bt262.btr" << endl;
			cout << "������Ԫ��X" << endl;
			cin >> X;
			if (ReadFileToArray(fileName_5, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 26, nRow);
				f = false;
				findH(T, 1, X, f);
				if (!f) {
					cout << "û�иý��" << endl;
				}
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "�ڶ������ݣ� bt21.btr" << endl;
			cout << "������Ԫ��X" << endl;
			cin >> X;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 21, nRow);
				f = false;
				findH(T, 1, X, f);
				if (!f) {
					cout << "û�иý��" << endl;
				}
			}
			DestroyBiTree(T);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			cout << "��������Ϊ��" << endl;
			cout << "��һ�����ݣ� bt8.btr" << endl;
			ArrayToBiTree(T, A, 1, 11);
			outTree(T);
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "�ڶ������ݣ� bt14.btr" << endl;
			ArrayToBiTree(T, A1, 1, 21);
			outTree(T);
			DestroyBiTree(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			cout << "��������Ϊ��" << endl;
			cout << "��һ�����ݣ� bt261.btr" << endl;
			if (ReadFileToArray(fileName_3, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 26, nRow);
				pathlen = 0;
				Route(T, path, pathlen);
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "�ڶ������ݣ� bt21.btr" << endl;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 21, nRow);
				pathlen = 0;
				Route(T, path, pathlen);
			}
			DestroyBiTree(T);
			system("pause");
			system("cls");
			break;
		}
		case 7:
		{
			cout << "��������Ϊ��" << endl;
			cout << "��һ�����ݣ� bt261.btr" << endl;
			if (ReadFileToArray(fileName_3, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 26, nRow);
				LevelOrder(T);
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "�ڶ������ݣ� bt21.btr" << endl;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "�ļ��򿪳ɹ�" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 21, nRow);
				LevelOrder(T);
			}
			DestroyBiTree(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 8:
		{
			cout << "���н�����" << endl;
			system("pause");
			system("cls");
			return 0;
		}
		default:
		{
			cout << "������������������" << endl;
			system("pause");
			system("cls");
		}
		}
	}
	return 0;
}

