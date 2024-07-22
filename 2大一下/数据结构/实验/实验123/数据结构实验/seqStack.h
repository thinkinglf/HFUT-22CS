//#pragma once
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <stack>
//#include <vector>
//#define MAXSIZE 1000
//using namespace std;
//typedef struct seqStack//顺序栈
//{
//	char data[MAXSIZE];//因为要用到字母所以用char来存储数据
//	int top;
//}seqStack;
//
////函数声明
//void showMenu1();//显示菜单(顺序栈)
//void initStack1(seqStack& S);//顺序栈初始化
//seqStack ChangeSystem1(int num, int x);//进制转化(num 为10进制的数字，x是目标的进制数)
//bool bracketMatch1(string str);//判断一个数学表达式是否合法
//void back_track1(vector<int> ans, stack<int> stk, stack<int> input, vector<vector<int>>& result, int n);//判断栈的输出是否合适 
//bool showStack1(seqStack S);//显示栈中的数据 
//
//void showMenu1()
//{
//	cout << "*********************************************************************************" << endl;
//	cout << "*                欢迎您来到测试页面，现在开始您的测试                           *" << endl;
//	cout << "*                11.利用顺序栈实现将10进制数转换为x进制数(字母用大写字母表示)   *" << endl;
//	cout << "*                12.对以字符串形式读入的表达式S，判断其中的各括号是否是匹配的   *" << endl;
//	cout << "*                13.假设栈的输入序列为1、2、3、...、n，设计算法求出所有可能的   *" << endl;
//	cout << "*                   出栈序列                                                    * " << endl;
//	cout << "*               (n).退出程序(n为其他正整数)                                     *" << endl;
//	cout << "*********************************************************************************" << endl;
//}
//
//void initStack1(seqStack& S)//顺序栈初始化
//{
//	S.top = -1;
//}
//
//seqStack ChangeSystem1(int num, int x)//num 为10进制的数字，x是目标的进制数
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
////判断一个数学表达式是否合法
//bool bracketMatch1(string str)
//{
//	seqStack S;//定义一个栈
//	initStack1(S);
//	bool result, temp = true;
//	int i = 0;
//	char x;
//	while (i < str.length() && temp)
//	{
//		switch (str[i])
//		{
//			//所有左括号入栈
//		case '(':
//		case '[':
//		case '{':
//			if (S.top <= 1000)
//				S.data[++S.top] = str[i];
//			else
//			{
//				cout << "栈满！" << endl; 
//				temp = false;
//			}
//			break;
//		case ')':
//			//扫描到右括号时，如果当前栈空，右括号多于左括号
//			if (S.top == -1)
//			{
//				temp = false;
//				break;
//			}
//			x = S.data[S.top--];//得到栈顶元素，并出栈
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
//			x = S.data[S.top--];//得到栈顶元素，并出栈		
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
//			x = S.data[S.top--];//得到栈顶元素，并出栈
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
//void back_track1(vector<int> ans, stack<int> stk, stack<int> input, vector<vector<int>>& result, int n)//判断栈的输出是否合适 
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
//bool showStack1(seqStack S)//显示栈中的数据 
//{
//	if (S.top == -1)
//	{
//		cout << "栈空！" << endl;
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
