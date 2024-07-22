//#pragma once
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <stack>
//#include <vector>
//using namespace std;
//typedef struct LinkNode//链栈
//{
//	char data;//因为要用到字母所以用char来存储数据
//	LinkNode* next;
//}LinkNode, * LinkStack;
//
////函数声明
//void showMenu2();//显示菜单(链栈)
//void initStack2(LinkStack& top);//链栈初始化
//LinkNode* ChangeSystem2(int num, int x);//进制转化(num 为10进制的数字，x是目标的进制数)
//bool bracketMatch2(string str);//判断一个数学表达式是否合法
//void back_track2(vector<int> ans, stack<int> stk, stack<int> input, vector<vector<int>>& result, int n);//判断栈的输出是否合适 
//bool showStack2(LinkStack top);//显示栈中的数据 
//
//void showMenu2()
//{
//	cout << "*********************************************************************************" << endl;
//	cout << "*                欢迎您来到测试页面，现在开始您的测试                           *" << endl;
//	cout << "*                21.利用链栈实现将10进制数转换为x进制数(字母用大写字母表示)     *" << endl;
//	cout << "*                22.对以字符串形式读入的表达式S，判断其中的各括号是否是匹配的   *" << endl;
//	cout << "*                23.假设栈的输入序列为1、2、3、...、n，设计算法求出所有可能的   *" << endl;
//	cout << "*                   出栈序列                                                    * " << endl;
//	cout << "*               (n).退出程序(n为其他正整数)                                     *" << endl;
//	cout << "*********************************************************************************" << endl;
//}
//
//void initStack2(LinkStack& top)//顺序栈初始化
//{
//	top = NULL;
//}
//
//LinkNode* ChangeSystem2(int num, int x)//num 为10进制的数字，x是目标的进制数
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
////判断一个数学表达式是否合法
//bool bracketMatch2(string str) 
//{
//	LinkNode* u, * top;//定义一个栈
//	top = NULL;
//	bool temp = true;
//	bool result;
//	int i = 0;
//	char x;
//	while (i < str.length() && temp == true)
//	{
//		switch (str[i])
//		{
//			//所有左括号入栈
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
//			if (top == NULL)//扫描到右括号时，如果当前栈空，右括号多于左括号
//			{
//				temp = false;
//				break;
//			}
//			x = top->data;//得到栈顶元素，并出栈
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
//			x = top->data;//得到栈顶元素，并出栈
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
//			x = top->data;//得到栈顶元素，并出栈
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
//void back_track2(vector<int> ans, stack<int> stk, stack<int> input, vector<vector<int>>& result, int n)//判断栈的输出是否合适 
//{
//	if (ans.size() == n)
//	{
//		result.push_back(ans);
//		return;
//	}
//	stack<int> stk_tmp = stk;
//	vector<int> ans_tmp = ans;
//	//输入直接出栈
//	if (!stk.empty())
//	{
//		ans.push_back(stk.top());
//		stk.pop();
//		back_track1(ans, stk, input, result, n);
//	}
//	//输入直接入栈
//	if (!input.empty())
//	{
//		stk_tmp.push(input.top());
//		input.pop();
//		back_track1(ans_tmp, stk_tmp, input, result, n);
//	}
//}
//
////显示栈中的数据
//bool showStack2(LinkStack top)
//{
//	char x;
//	if (top == NULL)
//	{
//		cout << "栈空！" << endl;
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
