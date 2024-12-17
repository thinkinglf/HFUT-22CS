#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
const int MaxLen = 20; //初始化栈的长度
const int Length = 20;//初始化数组长度

char N1[5] = { 'E','G','T','S','F' };//非终结符数组
char N2[8] = { 'i','(',')','+','-','*','/','#' };//终结符数组

char ch, X;//ch读当前字符，X获取栈顶元素
char str1[Length];//存储规约表达式

struct LL//ll(1)分析表的构造字初始化
{
	char*c;
};
LL E[8] = { "TG","TG","error","error","error","error","error","error" };
LL G[8] = { "error","error","null","+TG","-TG","error","error","null" };
LL T[8] = { "FS","FS","error","error","error","error","error","error" };
LL S[8] = { "error","error","null","null","null","*FS","/FS","null" };
LL F[8] = { "i","(E)","error","error","error","error","error","error" };

class stack//栈的构造及初始化
{
public:
	stack();//初始化
	bool empty() const;//是否为空
	bool full() const;//是否已满
	bool get_top(char &c)const;//取栈顶元素
	bool push(const char c);//入栈
	bool pop();//删除栈顶元素
	void out();//输出栈中元素
	~stack() {}//析构
private:
	int count;//栈长度
	char data[MaxLen];//栈中元素
};
/************栈的构造-开始************/
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
/************栈的构造-结束************/

int length(char *c)
{
	int l = 0;
	for (int i = 0; c[i] != '\0'; i++)
		l++;
	return l;
}

void print(int i, char*c)//剩余输入串的输出
{
	for (int j = i; j<Length; j++)
		cout << c[j];
	cout << '\t';
}

void run()
{
	bool flag = true;//循环条件
	int step = 0, point = 0;//步骤、指针
	int len;//长度
	cout << "输入规约的字符串：" << endl;
	cin >> str1;
	ch = str1[point++];//读取第一个字符
	stack s;
	s.push('#');//栈中数据初始化
	s.push('E');
	s.get_top(X);//取栈顶元素
	cout << "步骤\t" << "分析栈\t" << "剩余输入串\t\t" << "所用产生式\t" << "动作" << endl;
	cout << step++ << '\t';
	s.out();
	print(point - 1, str1);
	cout << '\t' << '\t' << "初始化" << endl;   //*******
	while (flag)
	{
		if ((X == N2[0]) || (X == N2[1]) || (X == N2[2]) || (X == N2[3]) || (X == N2[4]) || (X == N2[5]) || (X == N2[6]))
		{    //判断是否为终结符（不包括#）
			if (X == ch)   //终结符,识别，进行下一字符规约
			{
				s.pop();
				s.get_top(X);
				ch = str1[point++];
				cout << step++ << '\t';
				s.out();
				print(point - 1, str1);
				cout << '\t' << '\t' << "GETNEXT(I)" << endl;   //*******
			}
			else
			{
				flag = false;
			}
		}
		else if (X == '#')//规约结束
		{
			if (X == ch)
			{
				cout << step++ << '\t';
				s.out();
				print(point - 1, str1);
				cout << '\t' << X << "->" << ch << '\t' << '\t' << "结束" << endl;  //*******
				s.pop();
				flag = false;
			}
			else
			{
				flag = false;
			}
		}
		else if (X == N1[0]) //非终结符E
		{
			for (int i = 0; i<8; i++)//查分析表
				if (ch == N2[i])
				{
					if (strcmp(E[i].c, "error") == 0)//出错
					{
						flag = false;
					}
					else {             //对所用产生式进行入栈操作
						s.pop();       //对E出栈
						len = length(E[i].c) - 1;
						for (int j = len; j >= 0; j--)
							s.push(E[i].c[j]);     //对文法倒着入栈，保证后面的出栈顺序
						cout << step++ << '\t';
						s.out();
						print(point - 1, str1);
						cout << X << "->" << E[i].c << '\t' << '\t' << "POP,PUSH(";    //********
						for (int j = len; j >= 0; j--)
							cout << E[i].c[j];
						cout << ")" << endl;      //以上为格式输出
						s.get_top(X);      //读下一个栈顶元素
					}
				}
		}
		else if (X == N1[1])  //同上，处理 G
		{
			for (int i = 0; i<8; i++)
				if (ch == N2[i])
				{
					if (strcmp(G[i].c, "null") == 0)
					{
						s.pop();
						cout << step++ << '\t';
						s.out();
						print(point - 1, str1);
						cout << '\t' << X << "->" << "ε" << '\t' << '\t' << "POP" << endl;  //*******
						s.get_top(X);
					}
					else if (strcmp(G[i].c, "error") == 0)
					{
						flag = false;
					}
					else {
						s.pop();
						len = length(G[i].c) - 1;
						for (int j = len; j >= 0; j--)
							s.push(G[i].c[j]);
						cout << step++ << '\t';
						s.out();
						print(point - 1, str1);
						cout << X << "->" << G[i].c << '\t' << '\t' << "POP,PUSH(";    //*******
						for (int j = len; j >= 0; j--)
							cout << G[i].c[j];
						cout << ")" << endl;
						s.get_top(X);
					}
				}
		}
		else if (X == N1[2]) //同上 处理 T
		{
			for (int i = 0; i<8; i++)
				if (ch == N2[i])
				{
					if (strcmp(T[i].c, "error") == 0)
					{
						flag = false;
					}
					else {
						s.pop();
						len = length(T[i].c) - 1;
						for (int j = len; j >= 0; j--)
							s.push(T[i].c[j]);
						cout << step++ << '\t';
						s.out();
						print(point - 1, str1);
						cout << X << "->" << T[i].c << '\t' << '\t' << "POP,PUSH(";   //********
						for (int j = len; j >= 0; j--)
							cout << T[i].c[j];
						cout << ")" << endl;
						s.get_top(X);
					}
				}
		}
		else if (X == N1[3])//同上 处理 S
		{
			for (int i = 0; i<8; i++)
				if (ch == N2[i])
				{
					if (strcmp(S[i].c, "null") == 0)
					{
						s.pop();
						cout << step++ << '\t';
						s.out();
						print(point - 1, str1);

						cout << X << "->" << "ε" << '\t' << '\t' << "POP" << endl;   //*******
						s.get_top(X);
					}
					else if (strcmp(S[i].c, "error") == 0)
					{
						flag = false;
					}
					else {
						s.pop();
						len = length(S[i].c) - 1;
						for (int j = len; j >= 0; j--)
							s.push(S[i].c[j]);
						cout << step++ << '\t';
						s.out();
						print(point - 1, str1);
						cout << X << "->" << S[i].c << '\t' << '\t' << "POP,PUSH(";  //*******
						for (int j = len; j >= 0; j--)
							cout << S[i].c[j];
						cout << ")" << endl;
						s.get_top(X);
					}
				}
		}
		else if (X == N1[4])  //同上 处理 F
		{
			for (int i = 0; i<7; i++)
				if (ch == N2[i])
				{
					if (strcmp(F[i].c, "error") == 0)
					{
						flag = false;
					}
					else {
						s.pop();
						len = length(F[i].c) - 1;
						for (int j = len; j >= 0; j--)
							s.push(F[i].c[j]);
						cout << step++ << '\t';
						s.out();
						print(point - 1, str1);
						cout << X << "->" << F[i].c << '\t' << '\t' << "POP,PUSH(";   //*******
						for (int j = len; j >= 0; j--)
							cout << F[i].c[j];
						cout << ")" << endl;
						s.get_top(X);
					}
				}
		}
		else //出错处理
		{
			flag = false;
		}
	}
}
int main()
{
	run();
	system("pause");
	return 0;
}
