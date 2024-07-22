#include "linkedList.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//声明所要执行的7个操作
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
		int n;   //选择序号n
		cout << "输入你要选择的功能序号:";
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
		system("cls");//停顿+清屏
	}
}


void test01()
{
	LinkList L;
	initList(L);
	List_TailInsert(L);
	cout << "请输入插入的位置和数值:   ";
	int i, x; cin >> i >> x;
	if (ListInsert(L, i, x))
	{
		cout << "插入数据后单链表的内容:   ";
		showList(L);
	}		
}

void test02()
{
	LinkList L;
	initList(L);
	List_TailInsert(L);
	cout << "请输入删除的位置:   ";
	int i; cin >> i;
	if (ListDelete(L, i))
	{
		cout << "删除数据后单链表的内容:   ";
		showList(L);
	}
	else
		cout << "删除失败" << endl;
}

void test03()
{
	LinkList L;
	initList(L);
	List_TailInsert(L);
	cout << "请输入插入的数值:   ";
	int x; cin >> x;
	InsertSort(L, x);
	cout << "插入数据后单链表的内容:   ";
	showList(L);
}

void test04()
{
	LinkList L, L1, L2;
	initList(L); 	initList(L1); 	initList(L2);
	List_TailInsert(L);
	part(L, L1, L2);
	cout << "数据分开后3个单链表的内容:   " << endl;
	cout << "单链表L :    "; showList(L); 	
	cout << "单链表L1:    "; showList(L1);
	cout << "单链表L2:    "; showList(L2);
}

void test05()
{
	LinkList L1, L2, L3;
	initList(L1); 	initList(L2); 	initList(L3);
	List_TailInsert(L1);
	List_TailInsert(L2);
	listCommon(L1, L2, L3);
	cout << "求公共元素后单链表L3的内容:   ";
	showList(L3);
}

void test06()
{
	LinkList L;
	initList(L);
	List_TailInsert(L);
	incListDelete(L);
	cout << "去除公共元素后单链表L的内容:   ";
	showList(L);
}

void test07()
{
	LinkList L1, L2;
	initList(L1); 	initList(L2);
	List_TailInsert(L1); List_TailInsert(L2);
	ListUnite(L1, L2);
	cout << "合并单链表L1,L2至L1后单链表L1的内容:   ";
	showList(L1);
}
