//#include "seqStack.h"
//#include "linkedStack.h"
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <stack>
//#include <vector>
//using namespace std;
////������Ҫִ�е�2�������һ��6��
//void test011();//˳��ջ
//void test012();
//void test013();
//void test021();//��ջ
//void test022();
//void test023();
//
//
//int main()
//{
//	while (true)
//	{
//		cout << "��ѡ����Ҫִ�е�����(��������Ĭ���˳�����);  " << endl;
//		cout << "1����˳��ջ   2������ջ" << endl;
//		int x; cin >> x;
//		if (x == 1)
//			showMenu1();
//		else if (x == 2)
//			showMenu2();
//		else
//			return 0;
//		cout << "������Ҫѡ��Ĺ������:";
//		int n;  cin >> n;//ѡ�����n
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
//		system("cls");//ͣ��+����
//	}
//	return 0;
//}
//
//
//void test011()
//{
//	cout << "��������Ҫת�������ݺͶ�Ӧ�Ľ���:   ";
//	int num, x; cin >> num >> x;
//	seqStack S = ChangeSystem1(num, x);
//	cout << "�任�������Ϊ:  ";
//	showStack1(S);
//}
//
//void test012()
//{
//	cout << "��������Ҫ�жϵ���ѧ���ʽstr:  ";
//	string S; cin >> S;
//	bool flag = bracketMatch1(S);
//	if (flag)
//		cout << "���ʽ" << S << "��ƥ���" << endl;
//	else
//		cout << "���ʽ" << S << "�ǲ�ƥ���" << endl;
//}
//
//void test013()
//{
//	stack<int> stk;
//	vector<int> ans;
//	stack<int> input;
//	vector<vector<int>> result;
//	cout << "������n��ֵ:  ";
//	int n; cin >> n;
//	int num = n; //��ջԪ������
//	for (int i = num; i > 0; --i)
//		input.push(i);
//	vector<vector<int>> store;
//	back_track1(ans, stk, input, result, num);
//	cout << "���ܵĳ�ջ���Ϊ:  " << endl;
//	for (vector<int>& vec : result)
//	{
//		for (int& i : vec)
//			cout << i << " ";
//		cout << endl;
//	}
//	cout << "һ����" << result.size() << "�����" << endl;
//}
//
//void test021()
//{
//	cout << "��������Ҫת�������ݺͶ�Ӧ�Ľ���:   ";
//	int num, x; cin >> num >> x;
//	LinkNode* top = ChangeSystem2(num, x);
//	cout << "�任�������Ϊ:  ";
//	showStack2(top);
//}
//
//void test022()
//{
//	cout << "��������Ҫ�жϵ���ѧ���ʽstr:  ";
//	string S; cin >> S;
//	bool flag = bracketMatch2(S);
//	if (flag)
//		cout << "���ʽ" << S << "��ƥ���" << endl;
//	else
//		cout << "���ʽ" << S << "�ǲ�ƥ���" << endl;
//}
//
//void test023()
//{
//	stack<int> stk;
//	vector<int> ans;
//	stack<int> input;
//	vector<vector<int>> result;
//	cout << "������n��ֵ:  ";
//	int n; cin >> n;
//	int num = n; //��ջԪ������
//	for (int i = num; i > 0; --i)
//		input.push(i);
//	vector<vector<int>> store;
//	back_track1(ans, stk, input, result, num);
//	cout << "���ܵĳ�ջ���Ϊ:  " << endl;
//	for (vector<int>& vec : result)
//	{
//		for (int& i : vec)
//			cout << i << " ";
//		cout << endl;
//	}
//	cout << "һ����" << result.size() << "�����" << endl;
//}
//
//
//
//
//
//
