//#pragma once
//#include <iostream>
//#include <stdio.h>
//#define MaxSize 100
//using namespace std;
//typedef struct seqList
//{
//	int data[MaxSize];   //�洢����Ԫ�ص����� 
//	int listLen;       //���ȷ��� 
//}seqList;
//
////�������� 
//void showMenu();//��ʾ�˵�
//bool initialList(seqList& L);//��ʼ��
//bool listCreate(seqList& L);//����˳���	
//bool listOutput(seqList L);//�����ǰ��������
//bool listInsert1(seqList& L, int i, int x);//�ڵ�iλ�ò���ֵΪx�Ľ��	
//bool listDelete(seqList& L, int i);//ɾ����i����
//bool listInsert2(seqList& L, int x);//��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ��������������������
//bool listSeperate(seqList L, seqList& L1, seqList& L2);//˳������������ż����ֿ�
//bool listBoth(seqList L1, seqList L2, seqList& L3);//��������������˳���L1��L2�еĹ���Ԫ��
//bool listCancle(seqList& L);//ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���
//
//
////��ʾ�˵�
//void showMenu()
//{
//	cout << "*********************************************************************************" << endl;
//	cout << "*                 ��ӭ����������ҳ�棬���ڿ�ʼ���Ĳ���                          *" << endl;
//	cout << "*                 1.�ڵ�i�����λ�ò���ֵΪx�Ľ��                              *" << endl;
//	cout << "*                 2.ɾ��˳����е�i��Ԫ�ؽ��                                   *" << endl;
//	cout << "*                 3.�ڵ��������в���xԪ�أ������ֵ�����                         *" << endl;
//	cout << "*                 4.˳������������ż����ֿ����ֱ����                        *" << endl;
//	cout << "*                 5.��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3��  *" << endl;
//	cout << "*                 6.ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���          *" << endl;
//	cout << "*                (n).�˳�����(nΪ����������)                                    *" << endl;
//	cout << "*********************************************************************************" << endl;
//}
//
//
////��ʼ��˳���
//bool initialList(seqList& L)
//{
//	L.listLen = 0;
//	return true;
//}
//
////˳����е����ݳ�ʼ��
//bool listCreate(seqList& L)
//{
//	int len;
//	cout << "������˳�����:  ";
//	cin >> len;
//	if (len == 0)
//	{
//		cout << "�����ձ�" << endl;
//		return true;
//	}
//	else if (len > MaxSize)
//	{
//		cout << "�������洢�ռ�" << endl;
//		return false;
//	}
//	else
//	{
//		cout << "������˳��������:  ";
//		for (int j = 0; j < len; j++)
//		{
//			cin >> L.data[j];
//			L.listLen++;
//		}
//		return true;
//	}
//}
//
////��˳����е�Ԫ�����
//bool listOutput(seqList L)
//{
//	for (int i = 0; i < L.listLen; i++)
//		cout << L.data[i] << ' ';
//	cout << endl;
//	return true;
//}
//
////�ڵ�i��λ�ò���ֵΪx�Ľ�� 
//bool listInsert1(seqList& L, int i, int x)
//{
//	if (L.listLen == MaxSize)
//	{
//		cout << "˳����������޷�����" << endl;
//		return false;
//	}
//	else if (i<1 || i>L.listLen + 1)
//	{
//		cout << "�����λ�ò�����" << endl;
//		return  false;
//	}
//	else if (i >= 1 && i <= L.listLen + 1)//�Ӻ���ǰ��
//	{
//		for (int j = L.listLen - 1; j >= i - 1; j--)
//		{
//			L.data[j + 1] = L.data[j];
//		}
//		L.data[i - 1] = x;
//		L.listLen++;
//		return true;
//	}
//	else
//	{
//		cout << "�������" << endl;
//		return false;
//	}
//}
//
////ɾ��˳����е�i����� 
//bool listDelete(seqList& L, int i)
//{
//	if (L.listLen == 0)
//		return cout << "��Ϊ�ձ��޷�ɾ��Ԫ��" << endl, false;//�ձ���ɾ��Ԫ��	
//	else if (i<1 || i>L.listLen)
//		return cout << "ɾ��λ�ô���" << endl, false;//��Ŵ���ɾ��Ԫ�ز����� 
//	else
//	{
//		for (int j = i; j <= L.listLen - 1; j++)//��ǰ�����ƶ�Ԫ�� 
//		{
//			L.data[j - 1] = L.data[j];
//		}
//		L.listLen--;                  //���ȼ�1 
//		return true;
//	}
//}
//
////��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ��������������������
//bool listInsert2(seqList& L, int x)
//{
//	if (L.listLen + 1 > MaxSize)
//	{
//		cout << "������������ʧ��" << endl;
//		return  false;
//	}
//	L.listLen++;
//	L.data[L.listLen - 1] = x;  //�Ѳ����������˳����ĩβ
//	for (int i = L.listLen - 1; i > 0; i--)
//	{
//		if (L.data[i] < L.data[i - 1]) //�������������֮ǰ����С���򻥻�λ��
//		{
//			int temp = L.data[i];
//			L.data[i] = L.data[i - 1];
//			L.data[i - 1] = temp;
//		}
//		else //������������֮ǰ�Ķ������������Ҫ���˳�
//			return true;
//	}
//	return true;
//}
//
////˳������������ż����ֿ�
//bool listSeperate(seqList L, seqList& L1, seqList& L2)
//{
//	int a = 0;  //��¼L1��ĳ���  L1Ϊż����
//	int b = 0;  //��¼L2��ĳ���  L2Ϊ������
//	for (int i = 0; i < L.listLen; i++)
//	{
//		if (L.data[i] % 2 == 0)
//			L1.data[a++] = L.data[i];
//		else 
//			L2.data[b++] = L.data[i];
//	}
//	L1.listLen = a - 1;//��Ҫ���˱�-1
//	L2.listLen = b - 1;
//	return true;
//}
//
////��������������˳���L1��L2�еĹ���Ԫ��
//bool listBoth(seqList L1, seqList L2, seqList& L3)
//{
//	int i = 0, j = 0, k = 0;
//	while (i < L1.listLen && j < L2.listLen)  //���ٱ���������ֻҪ��һ����������������
//	{
//		if (L1.data[i] == L2.data[j])
//		{
//			L3.data[k] = L1.data[i];
//			i++;	j++;	k++;
//		}
//		else if (L1.data[i] > L2.data[j])
//			j++;
//		else
//			i++;
//	}
//	L3.listLen = k;
//	return true;
//}
//
////ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���
//bool listCancle(seqList& L)
//{
//	int count = 0; //ͳ���ƶ�Ԫ�ش���
//	int p = L.listLen - 1;
//	int size = L.listLen;   //����ɾ��������L->listLen��ֵ�ᷢ���ı䣬�����Ȱ�˳���ĳ�ʼ���ȼ�¼����
//	for (int i = 1; i < size; i++)
//	{
//		if (L.data[p] == L.data[p - 1])
//		{
//			listDelete(L, p + 1);
//			count += L.listLen - p;
//		}
//		p--; //����ǰһ��Ԫ��
//	}
//	cout << "ɾ���ظ�Ԫ���Ժ���±�Ϊ��";
//	listOutput(L);
//	cout << "�ƶ�Ԫ�صĴ���Ϊ��" << count << endl;
//	return true;
//}