//#include "seqlist.h"
//#include <iostream>
//#include <stdio.h>
//using namespace std;
////声明所要执行的6个操作
//void test01();
//void test02();
//void test03();
//void test04();
//void test05();
//void test06();
//
//int main()
//{	
//	while (true)
//	{
//		showMenu();
//		int n;   //选择序号n
//		cout << "输入你要选择的功能序号:";
//		cin >> n;
//		switch (n)
//		{
//		case 1:
//			test01();
//			break;
//		case 2:
//			test02();
//			break;
//		case 3:
//			test03();
//			break;
//		case 4:
//			test04();
//			break;
//		case 5:
//			test05();
//			break;
//		case 6:
//			test06();
//			break;
//		default:
//			return 0;
//		}
//		system("pause");
//		system("cls");//停顿+清屏
//	}
//}
//
//void test01()
//{
//	seqList L;//L为指针
//	int i;    //插入的位置序号
//	int x;    //插入的值
//	initialList(L);	
//	listCreate(L);
//	cout << "输入要插入的位置：";
//	cin >> i;
//	cout << "输入要插入的值：";
//	cin >> x;
//	bool flag = listInsert1(L, i, x);
//	if (flag)
//	{
//		cout << "插入后的顺序表为：";
//		listOutput(L);
//	}
//}
//      
//void test02()
//{
//	seqList L;
//	int i;//删除位置序号
//	initialList(L);
//	if (listCreate(L))
//	{
//		cout << "输入要删除的位置：";
//		cin >> i;
//		if (listDelete(L, i))
//		{
//			cout << "删除后的顺序表为：";
//			listOutput(L);				
//		}		
//	}
//}
//
//void test03()
//{
//	seqList L;
//	int x;
//	initialList(L);
//	listCreate(L);
//	cout << "输入要插入的数据：";
//	cin >> x;
//	listInsert2(L, x);	
//	cout << "插入后的顺序表为：";
//	listOutput(L);		
//}
//
//void test04()
//{
//	seqList L;
//	seqList L1;
//	seqList L2;
//	initialList(L);
//	listCreate(L);
//	cout << "原顺序表为：";
//	listOutput(L);
//	listSeperate(L, L1, L2);
//	cout << "偶数顺序表为：";
//	listOutput(L1);
//	cout << "奇数顺序表为：";
//	listOutput(L2);
//}
//
//void test05()
//{
//	seqList L1;
//	seqList L2;
//	seqList L3;
//	initialList(L1);
//	listCreate(L1);
//	cout << "顺序表L1为：";
//	listOutput(L1);
//
//	initialList(L2);
//	listCreate(L2);
//	cout << "顺序表L2为：";
//	listOutput(L2);
//
//	listBoth(L1, L2, L3);
//	cout << endl;
//	cout << "含L1和L2中公共元素的新表L3为：";
//	listOutput(L3);
//}
//
//void test06()
//{
//	seqList L;
//	initialList(L);
//	listCreate(L);
//	listCancle(L);
//}