#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;//前者侧重表示结点   后者侧重表示链表

void showMenu();//显示菜单
bool initList(LinkList& L);//初始化一个带头结点的单链表 
LinkList List_TailInsert(LinkList& L);//尾插法建立单链表（有尾指针  默认输入9999时插入停止）
LNode* GetElem(LinkList L, int i);//按位序查找
bool InsertNextNode(LNode* p, int e);//指定结点p后插入数据e
bool ListInsert(LinkList& L, int i, int e);//在第i个位置插入元素e
void InsertSort(LinkList& L, int x);//递增有序插入 
bool DeleteNode(LNode* p);//删除指定结点p
bool ListDelete(LinkList& L, int i);//按位序删除结点
void part(LinkList L, LinkList& L1, LinkList& L2);//分为奇偶单链表 
void listCommon(LinkList L1, LinkList L2, LinkList& L3);//求单链表L1,L2的公共元素存入L3
void incListDelete(LinkList& L);//删除递增有序单链表中的重复元素
void ListUnite(LinkList& L1, LinkList& L2);//合并单链表L1,L2至L1
void showList(LinkList L);//展示单链表中的元素 


//显示菜单
void showMenu()
{
	cout << "************************************************************************************" << endl;
	cout << "*           欢迎您来到测试页面，现在开始您的测试                                   *" << endl;
	cout << "*           1.在第i个结点位置插入值为x的结点                                       *" << endl;
	cout << "*           2.删除单链表中第i个元素结点                                            *" << endl;
	cout << "*           3.在递增有序的单链表L中插入一个值为x的元素，并保持递增性               *" << endl;
	cout << "*           4.单链表中奇数项和偶数项分开，分别输出原表和分开后的表                 *" << endl;
	cout << "*           5.求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中           *" << endl;
	cout << "*           6.删除递增有序单链表中的重复元素                                       *" << endl;
	cout << "*           7.递增有序单链表L1、L2，不申请新结点，利用原表结点对两表进行合并,使得  *" << endl;
	cout << "*             合并后成为一个集合，合并后用L1的头结点作为头结点，删除多余的结点，   *" << endl;
	cout << "*             删除L2的头结点。要求时间性能最好                                     * "<< endl;
	cout << "*          (n).退出程序(n为其他正整数)                                             *" << endl;
	cout << "************************************************************************************" << endl;
}

//初始化一个带头结点的单链表 
bool initList(LinkList& L) 
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
}

LinkList List_TailInsert(LinkList& L)//尾插法建立单链表（有尾指针）
{
	cout << "尾插法建立单链表(有尾指针)" << endl;
	L = (LNode*)malloc(sizeof(LNode));
	LNode* s, * r = L;//r尾指针
	cout << "请输入单链表的长度:   ";
	int n, x;	cin >> n;
	if (n > 0)
	{
		cout << "请输入单链表的数据:";
		while (n)
		{
			cin >> x;
			s = (LNode*)malloc(sizeof(LNode));
			s->data = x;
			s->next = NULL;
			r->next = s;
			r = s;
			n--;
		}
	}
	else
	{
		initList(L);
		cout << "该单链表为空表" << endl;
	}
	return L;
}

LNode* GetElem(LinkList L, int i)//按位序查找
{
	if (i < 0)
	{
		cout << "查找位置错误" << endl;
		return  NULL;
	}
	LNode* p;
	p = L;
	int j = 0;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

bool InsertNextNode(LNode* p, int e)//指定结点p后插入数据e
{
	if (p == NULL)
		return cout << "插入失败" << endl, false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)//空间不足
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool ListInsert(LinkList& L, int i, int e)//在第i个位置插入元素e
{
	if (i < 1)
		return cout << "插入位置错误" << endl, false;
	LNode* p = GetElem(L, i - 1);//查找到第i-1个结点
	return InsertNextNode(p, e);//在第i-1个结点后插入新的结点
}

//递增有序插入 
void InsertSort(LinkList& L, int x)
{
	LNode* s, * p = L;
	while (p->next != NULL && p->next->data < x)
		p = p->next;
	InsertNextNode(p, x);
}

bool DeleteNode(LNode* p)//删除指定结点p
{
	if (p == NULL)//
		return false;
	LNode* q = p->next;
	p->data = q->data;//存在bug(删除最后结点有问题)
	p->next = q->next;
	free(q);
	return true;
}

bool ListDelete(LinkList& L, int i)//按位序删除结点
{
	if (i < 1)
		return cout << "删除位置错误" << endl, false;
	LNode* p = GetElem(L, i - 1);
	if (p == NULL)
		return false;
	if (p->next == NULL)//第i-1个结点之后已无其他结点(尾结点)
		return cout << "第" << i << "个结点不存在" << endl, false;
	LNode* q = p->next;
	p->next = q->next;
	free(q);
	cout << "删除成功" << endl;
	return true;
}

//分为奇偶单链表 
void part(LinkList L, LinkList &L1, LinkList &L2) 
{
	LNode* s, * p = L->next;
	LNode* p1 = L1, * p2 = L2;
	while (p != NULL)
	{
		if (p->data % 2 == 0)//为偶数，进入L1中 
		{
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p->data;
			s->next = p1->next;
			p1->next = s;
			p1 = s;
			p = p->next;
		}
		else//为奇数，进入L2中 
		{		
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p->data;
			s->next = p2->next;
			p2->next = s;
			p2 = s;
			p = p->next;
		}
	}
}

//求单链表L1,L2的公共元素存入L3
void listCommon(LinkList L1, LinkList L2, LinkList& L3)
{
	LNode* s, * p1, * p2, * p3 = L3;
	p1 = L1->next;
	p2 = L2->next;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data == p2->data)
		{
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p1->data;
			s->next = NULL;
			p3->next = s;
			p3 = s;

			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->data > p2->data)
			p2 = p2->next;
		else
			p1 = p1->next;
	}
}

//删除递增有序单链表中的重复元素
void incListDelete(LinkList& L)
{
	LNode* p, * q;
	p = L->next;
	q = L->next->next;
	while (q != NULL)
	{
		if (p->data == q->data)
		{
			q = q->next;
			p->next = q;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
}

//合并单链表L1,L2至L1
void ListUnite(LinkList& L1, LinkList& L2)
{
	LNode* p = L1, * q = L2;
	while (p->next != NULL)
		p = p->next;
	p->next = q->next;
	free(L2);
}

//展示单链表中的元素 
void showList(LinkList L)
{
	LNode* p = L->next;
	if (p == NULL)
		cout << "表为空！";
	while (p != NULL)//遍历打印出单链表元素 
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}