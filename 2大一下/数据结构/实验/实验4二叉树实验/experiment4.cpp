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
	BiNode* T, * T1;//二叉树
	char p, q;
	int choice;

	while (true) 
	{
		cout << "**************************************************************************************" << endl;
		cout << "*          1.中序次序输出二叉树中各结点的值及其所对应的层次数                        *" << endl;
		cout << "*          2.求二叉树的叶子结点数和1度结点数                                         *" << endl;
		cout << "*          3.求父节点、兄弟结点、子结点的值(明确左右)                                *" << endl;
		cout << "*          4.求在树中的层次                                                          *" << endl;
		cout << "*          5.按顺序方式存储在数组中的二叉树转换为二叉链表（数组中要扩展为完全二叉树）*" << endl;
		cout << "*          6.二叉树从每个叶子结点到根结点的路径                                      *" << endl;
		cout << "*          7.按层次遍历序打印                                                        *" << endl;
		cout << "*          8.退出程序                                                                *" << endl;
		cout << "**************************************************************************************" << endl;

		cout << "输入你要做出的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "测试数据为：" << endl;
			cout << "第一组数据：bt151.btr" << endl;
			if (ReadFileToArray(fileName_1, strLine, 0)) {
				cout << "文件打开成功" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 15, nRow);
				outMidOrder(T, 1);
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "第二组数据： bt21.btr" << endl;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "文件打开成功" << endl;
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
			cout << "测试数据为：" << endl;
			cout << "第一组数据： bt261.btr" << endl;
			if (ReadFileToArray(fileName_3, strLine, 0)) {
				cout << "文件打开成功" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 26, nRow);
				Ye = 0;
				Du = 0;
				YeAnd1Du(T, Ye, Du);
				cout << "叶子结点个数为：" << Ye << endl;
				cout << "1度结点个数为：" << Du << endl;
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "第二组数据： bt21.btr" << endl;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "文件打开成功" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 21, nRow);
				Ye = 0;
				Du = 0;
				YeAnd1Du(T, Ye, Du);
				cout << "叶子结点个数为：" << Ye << endl;
				cout << "1度结点个数为：" << Du << endl;
			}
			DestroyBiTree(T);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			cout << "测试数据为：" << endl;
			cout << "第一组数据： bt31.btr" << endl;
			cout << "请输入元素X" << endl;
			cin >> X;
			if (ReadFileToArray(fileName_4, strLine, 0)) {
				cout << "文件打开成功" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 31, nRow);
				f = false;
				find(T, X, f);
				if (f == false) {
					cout << "没有该结点" << endl;
				}
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "第二组数据： bt21.btr" << endl;
			cout << "请输入元素X" << endl;
			cin >> X;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "文件打开成功" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 21, nRow);
				f = false;
				find(T, X, f);
				if (f == false) {
					cout << "没有该结点" << endl;
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
			cout << "测试数据为：" << endl;
			cout << "第一组数据： bt262.btr" << endl;
			cout << "请输入元素X" << endl;
			cin >> X;
			if (ReadFileToArray(fileName_5, strLine, 0)) {
				cout << "文件打开成功" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 26, nRow);
				f = false;
				findH(T, 1, X, f);
				if (!f) {
					cout << "没有该结点" << endl;
				}
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "第二组数据： bt21.btr" << endl;
			cout << "请输入元素X" << endl;
			cin >> X;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "文件打开成功" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 21, nRow);
				f = false;
				findH(T, 1, X, f);
				if (!f) {
					cout << "没有该结点" << endl;
				}
			}
			DestroyBiTree(T);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			cout << "测试数据为：" << endl;
			cout << "第一组数据： bt8.btr" << endl;
			ArrayToBiTree(T, A, 1, 11);
			outTree(T);
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "第二组数据： bt14.btr" << endl;
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
			cout << "测试数据为：" << endl;
			cout << "第一组数据： bt261.btr" << endl;
			if (ReadFileToArray(fileName_3, strLine, 0)) {
				cout << "文件打开成功" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 26, nRow);
				pathlen = 0;
				Route(T, path, pathlen);
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "第二组数据： bt21.btr" << endl;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "文件打开成功" << endl;
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
			cout << "测试数据为：" << endl;
			cout << "第一组数据： bt261.btr" << endl;
			if (ReadFileToArray(fileName_3, strLine, 0)) {
				cout << "文件打开成功" << endl;
				nRow = 0;
				CreateBiTreeFromFile(T, strLine, 26, nRow);
				LevelOrder(T);
			}
			DestroyBiTree(T);
			cout << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << "第二组数据： bt21.btr" << endl;
			if (ReadFileToArray(fileName_2, strLine, 0)) {
				cout << "文件打开成功" << endl;
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
			cout << "运行结束！" << endl;
			system("pause");
			system("cls");
			return 0;
		}
		default:
		{
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
		}
		}
	}
	return 0;
}

