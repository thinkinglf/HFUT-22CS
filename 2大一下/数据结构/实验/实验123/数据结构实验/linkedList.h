#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode, * LinkList;//ǰ�߲��ر�ʾ���   ���߲��ر�ʾ����

void showMenu();//��ʾ�˵�
bool initList(LinkList& L);//��ʼ��һ����ͷ���ĵ����� 
LinkList List_TailInsert(LinkList& L);//β�巨������������βָ��  Ĭ������9999ʱ����ֹͣ��
LNode* GetElem(LinkList L, int i);//��λ�����
bool InsertNextNode(LNode* p, int e);//ָ�����p���������e
bool ListInsert(LinkList& L, int i, int e);//�ڵ�i��λ�ò���Ԫ��e
void InsertSort(LinkList& L, int x);//����������� 
bool DeleteNode(LNode* p);//ɾ��ָ�����p
bool ListDelete(LinkList& L, int i);//��λ��ɾ�����
void part(LinkList L, LinkList& L1, LinkList& L2);//��Ϊ��ż������ 
void listCommon(LinkList L1, LinkList L2, LinkList& L3);//������L1,L2�Ĺ���Ԫ�ش���L3
void incListDelete(LinkList& L);//ɾ���������������е��ظ�Ԫ��
void ListUnite(LinkList& L1, LinkList& L2);//�ϲ�������L1,L2��L1
void showList(LinkList L);//չʾ�������е�Ԫ�� 


//��ʾ�˵�
void showMenu()
{
	cout << "************************************************************************************" << endl;
	cout << "*           ��ӭ����������ҳ�棬���ڿ�ʼ���Ĳ���                                   *" << endl;
	cout << "*           1.�ڵ�i�����λ�ò���ֵΪx�Ľ��                                       *" << endl;
	cout << "*           2.ɾ���������е�i��Ԫ�ؽ��                                            *" << endl;
	cout << "*           3.�ڵ�������ĵ�����L�в���һ��ֵΪx��Ԫ�أ������ֵ�����               *" << endl;
	cout << "*           4.���������������ż����ֿ����ֱ����ԭ��ͷֿ���ı�                 *" << endl;
	cout << "*           5.������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3��           *" << endl;
	cout << "*           6.ɾ���������������е��ظ�Ԫ��                                       *" << endl;
	cout << "*           7.������������L1��L2���������½�㣬����ԭ�����������кϲ�,ʹ��  *" << endl;
	cout << "*             �ϲ����Ϊһ�����ϣ��ϲ�����L1��ͷ�����Ϊͷ��㣬ɾ������Ľ�㣬   *" << endl;
	cout << "*             ɾ��L2��ͷ��㡣Ҫ��ʱ���������                                     * "<< endl;
	cout << "*          (n).�˳�����(nΪ����������)                                             *" << endl;
	cout << "************************************************************************************" << endl;
}

//��ʼ��һ����ͷ���ĵ����� 
bool initList(LinkList& L) 
{
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	return true;
}

LinkList List_TailInsert(LinkList& L)//β�巨������������βָ�룩
{
	cout << "β�巨����������(��βָ��)" << endl;
	L = (LNode*)malloc(sizeof(LNode));
	LNode* s, * r = L;//rβָ��
	cout << "�����뵥����ĳ���:   ";
	int n, x;	cin >> n;
	if (n > 0)
	{
		cout << "�����뵥���������:";
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
		cout << "�õ�����Ϊ�ձ�" << endl;
	}
	return L;
}

LNode* GetElem(LinkList L, int i)//��λ�����
{
	if (i < 0)
	{
		cout << "����λ�ô���" << endl;
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

bool InsertNextNode(LNode* p, int e)//ָ�����p���������e
{
	if (p == NULL)
		return cout << "����ʧ��" << endl, false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)//�ռ䲻��
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool ListInsert(LinkList& L, int i, int e)//�ڵ�i��λ�ò���Ԫ��e
{
	if (i < 1)
		return cout << "����λ�ô���" << endl, false;
	LNode* p = GetElem(L, i - 1);//���ҵ���i-1�����
	return InsertNextNode(p, e);//�ڵ�i-1����������µĽ��
}

//����������� 
void InsertSort(LinkList& L, int x)
{
	LNode* s, * p = L;
	while (p->next != NULL && p->next->data < x)
		p = p->next;
	InsertNextNode(p, x);
}

bool DeleteNode(LNode* p)//ɾ��ָ�����p
{
	if (p == NULL)//
		return false;
	LNode* q = p->next;
	p->data = q->data;//����bug(ɾ�������������)
	p->next = q->next;
	free(q);
	return true;
}

bool ListDelete(LinkList& L, int i)//��λ��ɾ�����
{
	if (i < 1)
		return cout << "ɾ��λ�ô���" << endl, false;
	LNode* p = GetElem(L, i - 1);
	if (p == NULL)
		return false;
	if (p->next == NULL)//��i-1�����֮�������������(β���)
		return cout << "��" << i << "����㲻����" << endl, false;
	LNode* q = p->next;
	p->next = q->next;
	free(q);
	cout << "ɾ���ɹ�" << endl;
	return true;
}

//��Ϊ��ż������ 
void part(LinkList L, LinkList &L1, LinkList &L2) 
{
	LNode* s, * p = L->next;
	LNode* p1 = L1, * p2 = L2;
	while (p != NULL)
	{
		if (p->data % 2 == 0)//Ϊż��������L1�� 
		{
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p->data;
			s->next = p1->next;
			p1->next = s;
			p1 = s;
			p = p->next;
		}
		else//Ϊ����������L2�� 
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

//������L1,L2�Ĺ���Ԫ�ش���L3
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

//ɾ���������������е��ظ�Ԫ��
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

//�ϲ�������L1,L2��L1
void ListUnite(LinkList& L1, LinkList& L2)
{
	LNode* p = L1, * q = L2;
	while (p->next != NULL)
		p = p->next;
	p->next = q->next;
	free(L2);
}

//չʾ�������е�Ԫ�� 
void showList(LinkList L)
{
	LNode* p = L->next;
	if (p == NULL)
		cout << "��Ϊ�գ�";
	while (p != NULL)//������ӡ��������Ԫ�� 
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}