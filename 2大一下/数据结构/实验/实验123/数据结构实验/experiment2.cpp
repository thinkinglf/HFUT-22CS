#include "linkedList.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//������Ҫִ�е�7������
void test01();
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();

int main()
{	
	while (true)
	{
		showMenu();
		int n;   //ѡ�����n
		cout << "������Ҫѡ��Ĺ������:";
		cin >> n;
		switch (n)
		{
		case 1:
			test01();
			break;
		case 2:
			test02();
			break;
		case 3:
			test03();
			break;
		case 4:
			test04();
			break;
		case 5:
			test05();
			break;
		case 6:
			test06();
			break;
		case 7:
			test07();
			break;
		default:
			return 0;
		}
		system("pause");
		system("cls");//ͣ��+����
	}
}


void test01()
{
	LinkList L;
	initList(L);
	List_TailInsert(L);
	cout << "����������λ�ú���ֵ:   ";
	int i, x; cin >> i >> x;
	if (ListInsert(L, i, x))
	{
		cout << "�������ݺ����������:   ";
		showList(L);
	}		
}

void test02()
{
	LinkList L;
	initList(L);
	List_TailInsert(L);
	cout << "������ɾ����λ��:   ";
	int i; cin >> i;
	if (ListDelete(L, i))
	{
		cout << "ɾ�����ݺ����������:   ";
		showList(L);
	}
	else
		cout << "ɾ��ʧ��" << endl;
}

void test03()
{
	LinkList L;
	initList(L);
	List_TailInsert(L);
	cout << "������������ֵ:   ";
	int x; cin >> x;
	InsertSort(L, x);
	cout << "�������ݺ����������:   ";
	showList(L);
}

void test04()
{
	LinkList L, L1, L2;
	initList(L); 	initList(L1); 	initList(L2);
	List_TailInsert(L);
	part(L, L1, L2);
	cout << "���ݷֿ���3�������������:   " << endl;
	cout << "������L :    "; showList(L); 	
	cout << "������L1:    "; showList(L1);
	cout << "������L2:    "; showList(L2);
}

void test05()
{
	LinkList L1, L2, L3;
	initList(L1); 	initList(L2); 	initList(L3);
	List_TailInsert(L1);
	List_TailInsert(L2);
	listCommon(L1, L2, L3);
	cout << "�󹫹�Ԫ�غ�����L3������:   ";
	showList(L3);
}

void test06()
{
	LinkList L;
	initList(L);
	List_TailInsert(L);
	incListDelete(L);
	cout << "ȥ������Ԫ�غ�����L������:   ";
	showList(L);
}

void test07()
{
	LinkList L1, L2;
	initList(L1); 	initList(L2);
	List_TailInsert(L1); List_TailInsert(L2);
	ListUnite(L1, L2);
	cout << "�ϲ�������L1,L2��L1������L1������:   ";
	showList(L1);
}
