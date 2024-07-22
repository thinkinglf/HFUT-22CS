//#pragma once
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <stack>
//#include <vector>
//using namespace std;
//typedef struct LinkNode//��ջ
//{
//	char data;//��ΪҪ�õ���ĸ������char���洢����
//	LinkNode* next;
//}LinkNode, * LinkStack;
//
////��������
//void showMenu2();//��ʾ�˵�(��ջ)
//void initStack2(LinkStack& top);//��ջ��ʼ��
//LinkNode* ChangeSystem2(int num, int x);//����ת��(num Ϊ10���Ƶ����֣�x��Ŀ��Ľ�����)
//bool bracketMatch2(string str);//�ж�һ����ѧ���ʽ�Ƿ�Ϸ�
//void back_track2(vector<int> ans, stack<int> stk, stack<int> input, vector<vector<int>>& result, int n);//�ж�ջ������Ƿ���� 
//bool showStack2(LinkStack top);//��ʾջ�е����� 
//
//void showMenu2()
//{
//	cout << "*********************************************************************************" << endl;
//	cout << "*                ��ӭ����������ҳ�棬���ڿ�ʼ���Ĳ���                           *" << endl;
//	cout << "*                21.������ջʵ�ֽ�10������ת��Ϊx������(��ĸ�ô�д��ĸ��ʾ)     *" << endl;
//	cout << "*                22.�����ַ�����ʽ����ı��ʽS���ж����еĸ������Ƿ���ƥ���   *" << endl;
//	cout << "*                23.����ջ����������Ϊ1��2��3��...��n������㷨������п��ܵ�   *" << endl;
//	cout << "*                   ��ջ����                                                    * " << endl;
//	cout << "*               (n).�˳�����(nΪ����������)                                     *" << endl;
//	cout << "*********************************************************************************" << endl;
//}
//
//void initStack2(LinkStack& top)//˳��ջ��ʼ��
//{
//	top = NULL;
//}
//
//LinkNode* ChangeSystem2(int num, int x)//num Ϊ10���Ƶ����֣�x��Ŀ��Ľ�����
//{
//	LinkNode* top;
//	initStack2(top);
//	while (num != 0)
//	{
//		int temp = num % x;
//		if (temp >= 10)
//		{
//			LinkNode* s;
//			s = (LinkNode*)malloc(sizeof(LinkNode));
//			s->data = temp - 10 + 'A';
//			s->next = top;
//			top = s;
//		}
//		else
//		{
//			LinkNode* s;
//			s = (LinkNode*)malloc(sizeof(LinkNode));
//			s->data = temp + '0';
//			s->next = top;
//			top = s;
//		}
//		num /= x;
//	}
//	return top;
//}
//
////�ж�һ����ѧ���ʽ�Ƿ�Ϸ�
//bool bracketMatch2(string str) 
//{
//	LinkNode* u, * top;//����һ��ջ
//	top = NULL;
//	bool temp = true;
//	bool result;
//	int i = 0;
//	char x;
//	while (i < str.length() && temp == true)
//	{
//		switch (str[i])
//		{
//			//������������ջ
//		case '(':
//		case '[':
//		case '{':
//			LinkNode * s;
//			s = (LinkNode*)malloc(sizeof(LinkNode));
//			s->data = str[i];
//			s->next = top;
//			top = s;
//			break;
//		case ')':
//			if (top == NULL)//ɨ�赽������ʱ�������ǰջ�գ������Ŷ���������
//			{
//				temp = false;
//				break;
//			}
//			x = top->data;//�õ�ջ��Ԫ�أ�����ջ
//			u = top;
//			top = top->next;
//			free(u);
//			if (x == '(')
//				break;
//			else 
//			{
//				temp = false;
//				break;
//			}
//		case ']':
//			if (top == NULL)
//			{
//				temp = false;
//				break;
//			}
//			x = top->data;//�õ�ջ��Ԫ�أ�����ջ
//			u = top;
//			top = top->next;
//			free(u);
//			if (x == '[') 
//				break;
//			else 
//			{
//				temp = false;
//				break;
//			}
//		case '}':
//			if (top == NULL) 
//			{
//				temp = false;
//				break;
//			}
//			x = top->data;//�õ�ջ��Ԫ�أ�����ջ
//			u = top;
//			top = top->next;
//			delete u;
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
//	if (top == NULL && temp == true)
//		result = true;
//	else
//		result = false;
//	return result;
//}
//
//
//void back_track2(vector<int> ans, stack<int> stk, stack<int> input, vector<vector<int>>& result, int n)//�ж�ջ������Ƿ���� 
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
////��ʾջ�е�����
//bool showStack2(LinkStack top)
//{
//	char x;
//	if (top == NULL)
//	{
//		cout << "ջ�գ�" << endl;
//		return false;
//	}
//	else 
//	{
//		while (top != NULL) 
//		{
//			x = top->data;
//			top = top->next;
//			cout << x;
//		}
//		cout << endl;
//		return true;
//	}
//}
