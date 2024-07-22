//#include "seqStack.h"
//#include "linkedStack.h"
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <stack>
//#include <vector>
//using namespace std;
////声明所要执行的2类操作，一共6个
//void test011();//顺序栈
//void test012();
//void test013();
//void test021();//链栈
//void test022();
//void test023();
//
//
//int main()
//{
//	while (true)
//	{
//		cout << "请选择你要执行的类型(其他数据默认退出程序);  " << endl;
//		cout << "1代表顺序栈   2代表链栈" << endl;
//		int x; cin >> x;
//		if (x == 1)
//			showMenu1();
//		else if (x == 2)
//			showMenu2();
//		else
//			return 0;
//		cout << "输入你要选择的功能序号:";
//		int n;  cin >> n;//选择序号n
//		switch (n)
//		{
//		case 11:
//			test011();
//			break;
//		case 12:
//			test012();
//			break;
//		case 13:
//			test013();
//			break;
//		case 21:
//			test021();
//			break;
//		case 22:
//			test022();
//			break;
//		case 23:
//			test023();
//			break;
//		default:
//			return 0;
//		}
//		system("pause");
//		system("cls");//停顿+清屏
//	}
//	return 0;
//}
//
//
//void test011()
//{
//	cout << "请输入想要转化的数据和对应的进制:   ";
//	int num, x; cin >> num >> x;
//	seqStack S = ChangeSystem1(num, x);
//	cout << "变换后的数据为:  ";
//	showStack1(S);
//}
//
//void test012()
//{
//	cout << "请输入所要判断的数学表达式str:  ";
//	string S; cin >> S;
//	bool flag = bracketMatch1(S);
//	if (flag)
//		cout << "表达式" << S << "是匹配的" << endl;
//	else
//		cout << "表达式" << S << "是不匹配的" << endl;
//}
//
//void test013()
//{
//	stack<int> stk;
//	vector<int> ans;
//	stack<int> input;
//	vector<vector<int>> result;
//	cout << "请输入n的值:  ";
//	int n; cin >> n;
//	int num = n; //入栈元素数量
//	for (int i = num; i > 0; --i)
//		input.push(i);
//	vector<vector<int>> store;
//	back_track1(ans, stk, input, result, num);
//	cout << "可能的出栈情况为:  " << endl;
//	for (vector<int>& vec : result)
//	{
//		for (int& i : vec)
//			cout << i << " ";
//		cout << endl;
//	}
//	cout << "一共有" << result.size() << "种情况" << endl;
//}
//
//void test021()
//{
//	cout << "请输入想要转化的数据和对应的进制:   ";
//	int num, x; cin >> num >> x;
//	LinkNode* top = ChangeSystem2(num, x);
//	cout << "变换后的数据为:  ";
//	showStack2(top);
//}
//
//void test022()
//{
//	cout << "请输入所要判断的数学表达式str:  ";
//	string S; cin >> S;
//	bool flag = bracketMatch2(S);
//	if (flag)
//		cout << "表达式" << S << "是匹配的" << endl;
//	else
//		cout << "表达式" << S << "是不匹配的" << endl;
//}
//
//void test023()
//{
//	stack<int> stk;
//	vector<int> ans;
//	stack<int> input;
//	vector<vector<int>> result;
//	cout << "请输入n的值:  ";
//	int n; cin >> n;
//	int num = n; //入栈元素数量
//	for (int i = num; i > 0; --i)
//		input.push(i);
//	vector<vector<int>> store;
//	back_track1(ans, stk, input, result, num);
//	cout << "可能的出栈情况为:  " << endl;
//	for (vector<int>& vec : result)
//	{
//		for (int& i : vec)
//			cout << i << " ";
//		cout << endl;
//	}
//	cout << "一共有" << result.size() << "种情况" << endl;
//}
//
//
//
//
//
//
