//#pragma once
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <stack>
//#include <vector>
//#define MAXSIZE 1000
//using namespace std;
//typedef struct seqStack//˳��ջ
//{
//	char data[MAXSIZE];//��ΪҪ�õ���ĸ������char���洢����
//	int top;
//}seqStack;
//
////��������
//void showMenu1();//��ʾ�˵�(˳��ջ)
//void initStack1(seqStack& S);//˳��ջ��ʼ��
//seqStack ChangeSystem1(int num, int x);//����ת��(num Ϊ10���Ƶ����֣�x��Ŀ��Ľ�����)
//bool bracketMatch1(string str);//�ж�һ����ѧ���ʽ�Ƿ�Ϸ�
//void back_track1(vector<int> ans, stack<int> stk, stack<int> input, vector<vector<int>>& result, int n);//�ж�ջ������Ƿ���� 
//bool showStack1(seqStack S);//��ʾջ�е����� 
//
//void showMenu1()
//{
//	cout << "*********************************************************************************" << endl;
//	cout << "*                ��ӭ����������ҳ�棬���ڿ�ʼ���Ĳ���                           *" << endl;
//	cout << "*                11.����˳��ջʵ�ֽ�10������ת��Ϊx������(��ĸ�ô�д��ĸ��ʾ)   *" << endl;
//	cout << "*                12.�����ַ�����ʽ����ı��ʽS���ж����еĸ������Ƿ���ƥ���   *" << endl;
//	cout << "*                13.����ջ����������Ϊ1��2��3��...��n������㷨������п��ܵ�   *" << endl;
//	cout << "*                   ��ջ����                                                    * " << endl;
//	cout << "*               (n).�˳�����(nΪ����������)                                     *" << endl;
//	cout << "*********************************************************************************" << endl;
//}
//
//void initStack1(seqStack& S)//˳��ջ��ʼ��
//{
//	S.top = -1;
//}
//
//seqStack ChangeSystem1(int num, int x)//num Ϊ10���Ƶ����֣�x��Ŀ��Ľ�����
//{
//	seqStack S;
//	initStack1(S);
//	while (num != 0)
//	{
//		int temp = num % x;
//		if (temp >= 10)
//			S.data[++S.top] = temp - 10 + 'A';
//		else
//			S.data[++S.top] = temp + '0';
//		num /= x;
//	}
//	return S;
//}
//
////�ж�һ����ѧ���ʽ�Ƿ�Ϸ�
//bool bracketMatch1(string str)
//{
//	seqStack S;//����һ��ջ
//	initStack1(S);
//	bool result, temp = true;
//	int i = 0;
//	char x;
//	while (i < str.length() && temp)
//	{
//		switch (str[i])
//		{
//			//������������ջ
//		case '(':
//		case '[':
//		case '{':
//			if (S.top <= 1000)
//				S.data[++S.top] = str[i];
//			else
//			{
//				cout << "ջ����" << endl; 
//				temp = false;
//			}
//			break;
//		case ')':
//			//ɨ�赽������ʱ�������ǰջ�գ������Ŷ���������
//			if (S.top == -1)
//			{
//				temp = false;
//				break;
//			}
//			x = S.data[S.top--];//�õ�ջ��Ԫ�أ�����ջ
//			if (x == '(')
//				break;
//			else
//			{
//				temp = false;
//				break;
//			}
//		case ']':
//			if (S.top == -1)
//			{
//				temp = false;
//				break;
//			}
//			x = S.data[S.top--];//�õ�ջ��Ԫ�أ�����ջ		
//			if (x == '[')
//				break;
//			else
//			{
//				temp = false;
//				break;
//			}
//		case '}':
//			if (S.top == -1)
//			{
//				temp = false;
//				break;
//			}
//			x = S.data[S.top--];//�õ�ջ��Ԫ�أ�����ջ
//			if (x == '{')
//				break;
//			else
//			{
//				temp = false;
//				break;
//			}
//		default:
//			break;
//		}
//		i++;
//	}
//	if (S.top == -1 && temp == true)
//		result = true;
//	else 
//		result = false;
//	return result;
//}
//
//void back_track1(vector<int> ans, stack<int> stk, stack<int> input, vector<vector<int>>& result, int n)//�ж�ջ������Ƿ���� 
//{
//	if (ans.size() == n)
//	{
//		result.push_back(ans);
//		return;
//	}
//	stack<int> stk_tmp = stk;
//	vector<int> ans_tmp = ans;
//	//����ֱ�ӳ�ջ
//	if (!stk.empty())
//	{
//		ans.push_back(stk.top());
//		stk.pop();
//		back_track1(ans, stk, input, result, n);
//	}
//	//����ֱ����ջ
//	if (!input.empty())
//	{
//		stk_tmp.push(input.top());
//		input.pop();
//		back_track1(ans_tmp, stk_tmp, input, result, n);
//	}
//}
//
//bool showStack1(seqStack S)//��ʾջ�е����� 
//{
//	if (S.top == -1)
//	{
//		cout << "ջ�գ�" << endl;
//		return false;
//	}
//	else
//	{
//		while (S.top >= 0)
//		{
//			cout << S.data[S.top];
//			S.top--;
//		}
//		cout << endl;
//		return true;
//	}
//}
//
