//#pragma once
//#include <iostream>
//#include <stdio.h>
//#define MaxSize 100
//using namespace std;
//typedef struct seqList
//{
//	int data[MaxSize];   //存储表中元素的数组 
//	int listLen;       //表长度分量 
//}seqList;
//
////函数声明 
//void showMenu();//显示菜单
//bool initialList(seqList& L);//初始化
//bool listCreate(seqList& L);//创建顺序表	
//bool listOutput(seqList L);//输出当前表中数据
//bool listInsert1(seqList& L, int i, int x);//在第i位置插入值为x的结点	
//bool listDelete(seqList& L, int i);//删除第i个数
//bool listInsert2(seqList& L, int x);//在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性
//bool listSeperate(seqList L, seqList& L1, seqList& L2);//顺序表中奇数项和偶数项分开
//bool listBoth(seqList L1, seqList L2, seqList& L3);//求两个递增有序顺序表L1和L2中的公共元素
//bool listCancle(seqList& L);//删除递增有序顺序表中的重复元素，并统计移动元素次数
//
//
////显示菜单
//void showMenu()
//{
//	cout << "*********************************************************************************" << endl;
//	cout << "*                 欢迎您来到测试页面，现在开始您的测试                          *" << endl;
//	cout << "*                 1.在第i个结点位置插入值为x的结点                              *" << endl;
//	cout << "*                 2.删除顺序表中第i个元素结点                                   *" << endl;
//	cout << "*                 3.在递增序列中插入x元素，并保持递增性                         *" << endl;
//	cout << "*                 4.顺序表中奇数项和偶数项分开，分别输出                        *" << endl;
//	cout << "*                 5.求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中  *" << endl;
//	cout << "*                 6.删除递增有序顺序表中的重复元素，并统计移动元素次数          *" << endl;
//	cout << "*                (n).退出程序(n为其他正整数)                                    *" << endl;
//	cout << "*********************************************************************************" << endl;
//}
//
//
////初始化顺序表
//bool initialList(seqList& L)
//{
//	L.listLen = 0;
//	return true;
//}
//
////顺序表中的数据初始化
//bool listCreate(seqList& L)
//{
//	int len;
//	cout << "请输入顺序表长度:  ";
//	cin >> len;
//	if (len == 0)
//	{
//		cout << "建立空表" << endl;
//		return true;
//	}
//	else if (len > MaxSize)
//	{
//		cout << "超出最大存储空间" << endl;
//		return false;
//	}
//	else
//	{
//		cout << "请输入顺序表的数据:  ";
//		for (int j = 0; j < len; j++)
//		{
//			cin >> L.data[j];
//			L.listLen++;
//		}
//		return true;
//	}
//}
//
////将顺序表中的元素输出
//bool listOutput(seqList L)
//{
//	for (int i = 0; i < L.listLen; i++)
//		cout << L.data[i] << ' ';
//	cout << endl;
//	return true;
//}
//
////在第i个位置插入值为x的结点 
//bool listInsert1(seqList& L, int i, int x)
//{
//	if (L.listLen == MaxSize)
//	{
//		cout << "顺序表已满，无法插入" << endl;
//		return false;
//	}
//	else if (i<1 || i>L.listLen + 1)
//	{
//		cout << "插入的位置不合适" << endl;
//		return  false;
//	}
//	else if (i >= 1 && i <= L.listLen + 1)//从后往前找
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
//		cout << "插入错误" << endl;
//		return false;
//	}
//}
//
////删除顺序表中第i个结点 
//bool listDelete(seqList& L, int i)
//{
//	if (L.listLen == 0)
//		return cout << "表为空表，无法删除元素" << endl, false;//空表不能删除元素	
//	else if (i<1 || i>L.listLen)
//		return cout << "删除位置错误" << endl, false;//序号错误，删除元素不存在 
//	else
//	{
//		for (int j = i; j <= L.listLen - 1; j++)//向前批量移动元素 
//		{
//			L.data[j - 1] = L.data[j];
//		}
//		L.listLen--;                  //表长度减1 
//		return true;
//	}
//}
//
////在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性
//bool listInsert2(seqList& L, int x)
//{
//	if (L.listLen + 1 > MaxSize)
//	{
//		cout << "表已满，插入失败" << endl;
//		return  false;
//	}
//	L.listLen++;
//	L.data[L.listLen - 1] = x;  //把插入的数放在顺序表的末尾
//	for (int i = L.listLen - 1; i > 0; i--)
//	{
//		if (L.data[i] < L.data[i - 1]) //插入的数比相邻之前的数小，则互换位置
//		{
//			int temp = L.data[i];
//			L.data[i] = L.data[i - 1];
//			L.data[i - 1] = temp;
//		}
//		else //如果插入的数比之前的都大，则满足递增要求退出
//			return true;
//	}
//	return true;
//}
//
////顺序表中奇数项和偶数项分开
//bool listSeperate(seqList L, seqList& L1, seqList& L2)
//{
//	int a = 0;  //记录L1表的长度  L1为偶数表
//	int b = 0;  //记录L2表的长度  L2为奇数表
//	for (int i = 0; i < L.listLen; i++)
//	{
//		if (L.data[i] % 2 == 0)
//			L1.data[a++] = L.data[i];
//		else 
//			L2.data[b++] = L.data[i];
//	}
//	L1.listLen = a - 1;//不要忘了表长-1
//	L2.listLen = b - 1;
//	return true;
//}
//
////求两个递增有序顺序表L1和L2中的公共元素
//bool listBoth(seqList L1, seqList L2, seqList& L3)
//{
//	int i = 0, j = 0, k = 0;
//	while (i < L1.listLen && j < L2.listLen)  //减少遍历次数，只要有一个表遍历结束则结束
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
////删除递增有序顺序表中的重复元素，并统计移动元素次数
//bool listCancle(seqList& L)
//{
//	int count = 0; //统计移动元素次数
//	int p = L.listLen - 1;
//	int size = L.listLen;   //由于删除过程中L->listLen的值会发生改变，所以先把顺序表的初始长度记录下来
//	for (int i = 1; i < size; i++)
//	{
//		if (L.data[p] == L.data[p - 1])
//		{
//			listDelete(L, p + 1);
//			count += L.listLen - p;
//		}
//		p--; //跳到前一个元素
//	}
//	cout << "删除重复元素以后的新表为：";
//	listOutput(L);
//	cout << "移动元素的次数为：" << count << endl;
//	return true;
//}