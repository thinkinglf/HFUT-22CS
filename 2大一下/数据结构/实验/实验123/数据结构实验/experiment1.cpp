//#include "seqlist.h"
//#include <iostream>
//#include <stdio.h>
//using namespace std;
////������Ҫִ�е�6������
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
//		int n;   //ѡ�����n
//		cout << "������Ҫѡ��Ĺ������:";
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
//		system("cls");//ͣ��+����
//	}
//}
//
//void test01()
//{
//	seqList L;//LΪָ��
//	int i;    //�����λ�����
//	int x;    //�����ֵ
//	initialList(L);	
//	listCreate(L);
//	cout << "����Ҫ�����λ�ã�";
//	cin >> i;
//	cout << "����Ҫ�����ֵ��";
//	cin >> x;
//	bool flag = listInsert1(L, i, x);
//	if (flag)
//	{
//		cout << "������˳���Ϊ��";
//		listOutput(L);
//	}
//}
//      
//void test02()
//{
//	seqList L;
//	int i;//ɾ��λ�����
//	initialList(L);
//	if (listCreate(L))
//	{
//		cout << "����Ҫɾ����λ�ã�";
//		cin >> i;
//		if (listDelete(L, i))
//		{
//			cout << "ɾ�����˳���Ϊ��";
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
//	cout << "����Ҫ��������ݣ�";
//	cin >> x;
//	listInsert2(L, x);	
//	cout << "������˳���Ϊ��";
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
//	cout << "ԭ˳���Ϊ��";
//	listOutput(L);
//	listSeperate(L, L1, L2);
//	cout << "ż��˳���Ϊ��";
//	listOutput(L1);
//	cout << "����˳���Ϊ��";
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
//	cout << "˳���L1Ϊ��";
//	listOutput(L1);
//
//	initialList(L2);
//	listCreate(L2);
//	cout << "˳���L2Ϊ��";
//	listOutput(L2);
//
//	listBoth(L1, L2, L3);
//	cout << endl;
//	cout << "��L1��L2�й���Ԫ�ص��±�L3Ϊ��";
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