#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
const int MaxLen = 20; //初始化栈的长度
const int Length = 20;//初始化数组长度

char ch, Y;//全局变量，ch用于读当前字符，Y用于获取栈顶元素
char strToken[Length];//存储规约表达式

bool flag = true;//循环条件
int point = 0, step = 1;//步骤、指针

class stack//栈的构造及初始化
{
public:
	stack();//初始化
	bool empty() const;//是否为空
	bool full() const;//是否已满
	bool get_top(char &c)const;//取栈顶元素
	bool push(const char c);//入栈
	bool pop();
	void out();//输出栈中元素
	void out1();
	~stack() {}//析构
private:
	int count;//栈长度
	char data[MaxLen];//栈中元素
};
stack l, r;//l代表符号栈，r代表状态栈
stack::stack()
{
	count = 0;
}
bool stack::empty() const
{
	if (count == 0)
		return true;
	return false;
}
bool stack::full() const
{
	if (count == MaxLen)
		return true;
	return false;
}
bool stack::get_top(char &c)const
{
	if (empty())
		return false;
	else
	{
		c = data[count - 1];
		return true;
	}
}
bool stack::push(const char c)
{
	if (full())
		return false;
	data[count++] = c;
	return true;
}
bool stack::pop()
{
	if (empty())
		return false;
	count--;
	return true;
}
void stack::out()
{
	for (int i = 0; i<count; i++)
		cout << data[i];
	cout << '\t';
}
void stack::out1()
{
	for (int i = 0; i<count; i++)
		cout << int(data[i]);
	cout << '\t';
}
void print(int i, char*c)//剩余输入串的输出
{
	for (int j = i; j<Length; j++)
		cout << c[j];
	cout << '\t';
}
void Goto(int i, char c)//状态转换函数 ,对应于表中GOTO
{
	if (i == 0)
	{
		if (c == 'E')
		{
			r.push(1);
			cout << ",GOTO(0,E)=1入栈" << endl;
		}
		else if (c == 'T')
		{
			r.push(2);
			cout << ",GOTO(0,T)=2入栈" << endl;
		}
		else if (c == 'F')
		{
			r.push(3);
			cout << ",GOTO(0,F)=3入栈" << endl;
		}
		else
			flag = false;
	}
	else if (i == 4)
	{
		if (c == 'E')
		{
			r.push(8);
			cout << ",GOTO(4,E)=8入栈" << endl;
		}
		else if (c == 'T')
		{
			r.push(2);
			cout << ",GOTO(4,T)=2入栈" << endl;
		}
		else if (c == 'F')
		{
			r.push(3);
			cout << ",GOTO(4,F)=3入栈" << endl;
		}
		else
			flag = false;
	}
	else if (i == 6)
	{
		if (c == 'T')
		{
			r.push(9);
			cout << ",GOTO(6,T)=9入栈" << endl;
		}
		else if (c == 'F')
		{
			r.push(3);
			cout << ",GOTO(6,F)=3入栈" << endl;
		}
		else
			flag = false;
	}
	else if (i == 7)
	{
		if (c == 'F')
		{
			r.push(10);
			cout << ",GOTO(7,F)=10入栈" << endl;
		}
		else
			flag = false;
	}
	else
		flag = false;
}
void Action0()//状态0时
{
	if (ch == 'i')//下一个操作符为i ,移进
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[0,i]=S5,状态5入栈" << endl;
		r.push(5);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == '(')//下一个操作符为( ,移进
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[0,(]=S4,状态4入栈" << endl;
		r.push(4);
		l.push(ch);
		ch = strToken[point++];
	}
	else
		flag = false;
}
void Action1()//状态1
{
	if (ch == '+')//下一个操作符为i ,移进
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[1,+]=S6,状态6入栈" << endl;
		r.push(6);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == '#')//分析成功
	{
		flag = false;
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "Acc：分析成功" << endl;
	}
	else
		flag = false;
}
void Action2() //状态2
{
	if (ch == '*')//下一个操作符为* ,移进
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[2,*]=S7,状态7入栈" << endl;
		r.push(7);
		l.push(ch);
		ch = strToken[point++];
	}
	else if ((ch == '+') || (ch == ')') || (ch == '#'))//下一个操作符为+，），#规约
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.push('E');
		print(point - 1, strToken);
		cout << "r2: E→T归约";
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'E');
	}
	else
		flag = false;
}
void Action3()//状态3
{
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#'))//下一个操作符为+，*,），#规约
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.push('T');
		print(point - 1, strToken);
		cout << "r4: T→F归约";
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'T');
	}
	else
		flag = false;
}
void Action4_6_7(int x)//状态4,6,7
{
	if (ch == 'i')//下一个操作符为i ,移进
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[";
		cout << x << ",i]=S5,状态5入栈" << endl;
		r.push(5);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == '(')//下一个操作符为（ ,移进
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[";
		cout << x << ",(]=S4,状态4入栈" << endl;
		r.push(4);
		l.push(ch);
		ch = strToken[point++];
	}
	else
		flag = false;
}
void Action5()//状态5
{
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#'))//下一个操作符为+，*,），#规约
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.push('F');
		print(point - 1, strToken);
		cout << "r6: F→i归约";
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'F');
	}
	else
		flag = false;
}
void Action8()//状态8
{
	if (ch == '+')//下一个操作符为+ ,移进
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[8,+]=S6,状态6入栈" << endl;
		r.push(6);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == ')')//下一个操作符为） ,移进
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[8,)]=S11,状态11入栈" << endl;
		r.push(11);
		l.push(ch);
		ch = strToken[point++];
	}
	else
		flag = false;
}
void Action9()//状态9
{
	if (ch == '*')//下一个操作符为* ,移进
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[9,*]=S7,状态7入栈" << endl;
		r.push(7);
		l.push(ch);
		ch = strToken[point++];
	}
	else if ((ch == '+') || (ch == ')') || (ch == '#'))//下一个操作符为+，,），#规约
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.pop();
		l.pop();
		l.push('E');
		print(point - 1, strToken);
		cout << "r1: E→E+T归约";
		r.pop();
		r.pop();
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'E');
	}
	else
		flag = false;
}
void Action10()//状态10
{
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#'))//下一个操作符为+，*,），#规约
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.pop();
		l.pop();
		l.push('T');
		print(point - 1, strToken);
		cout << "r3: T→T*F归约";
		r.pop();
		r.pop();
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'T');
	}
	else
		flag = false;
}
void Action11()//状态11
{
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#'))//下一个操作符为+，*,），#规约
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.pop();
		l.pop();
		l.push('F');
		print(point - 1, strToken);
		cout << "r5: F→(E)归约";
		r.pop();
		r.pop();
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'F');
	}
	else
		flag = false;
}
void run()//规约
{
	cout << "请输入要规约的字符串：" << endl;
	cin >> strToken;
	cout << "步骤\t" << "状态栈\t" << "符号栈\t" << "输入串\t\t" << "动作说明" << endl;
	ch = strToken[point++];//读取第一个字符
	l.push('#');
	r.push(0);
	r.get_top(Y);
	while (flag)//循环规约
	{
		if (int(Y) == 0)
			Action0();
		else if (int(Y) == 1)
			Action1();
		else if (int(Y) == 2)
			Action2();
		else if (int(Y) == 3)
			Action3();
		else if ((int(Y) == 4) || (int(Y) == 6) || (int(Y) == 7))
			Action4_6_7(int(Y));
		else if (int(Y) == 5)
			Action5();
		else if (int(Y) == 8)
			Action8();
		else if (int(Y) == 9)
			Action9();
		else if (int(Y) == 10)
			Action10();
		else if (int(Y) == 11)
			Action11();
		else
			flag = false;
		r.get_top(Y);
	}
}
int main()
{
	run();
	system("pause");
	return 0;
}
