#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
const int MaxLen = 20; //��ʼ��ջ�ĳ���
const int Length = 20;//��ʼ�����鳤��

char ch, Y;//ȫ�ֱ�����ch���ڶ���ǰ�ַ���Y���ڻ�ȡջ��Ԫ��
char strToken[Length];//�洢��Լ���ʽ

bool flag = true;//ѭ������
int point = 0, step = 1;//���衢ָ��

class stack//ջ�Ĺ��켰��ʼ��
{
public:
	stack();//��ʼ��
	bool empty() const;//�Ƿ�Ϊ��
	bool full() const;//�Ƿ�����
	bool get_top(char &c)const;//ȡջ��Ԫ��
	bool push(const char c);//��ջ
	bool pop();
	void out();//���ջ��Ԫ��
	void out1();
	~stack() {}//����
private:
	int count;//ջ����
	char data[MaxLen];//ջ��Ԫ��
};
stack l, r;//l�������ջ��r����״̬ջ
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
void print(int i, char*c)//ʣ�����봮�����
{
	for (int j = i; j<Length; j++)
		cout << c[j];
	cout << '\t';
}
void Goto(int i, char c)//״̬ת������ ,��Ӧ�ڱ���GOTO
{
	if (i == 0)
	{
		if (c == 'E')
		{
			r.push(1);
			cout << ",GOTO(0,E)=1��ջ" << endl;
		}
		else if (c == 'T')
		{
			r.push(2);
			cout << ",GOTO(0,T)=2��ջ" << endl;
		}
		else if (c == 'F')
		{
			r.push(3);
			cout << ",GOTO(0,F)=3��ջ" << endl;
		}
		else
			flag = false;
	}
	else if (i == 4)
	{
		if (c == 'E')
		{
			r.push(8);
			cout << ",GOTO(4,E)=8��ջ" << endl;
		}
		else if (c == 'T')
		{
			r.push(2);
			cout << ",GOTO(4,T)=2��ջ" << endl;
		}
		else if (c == 'F')
		{
			r.push(3);
			cout << ",GOTO(4,F)=3��ջ" << endl;
		}
		else
			flag = false;
	}
	else if (i == 6)
	{
		if (c == 'T')
		{
			r.push(9);
			cout << ",GOTO(6,T)=9��ջ" << endl;
		}
		else if (c == 'F')
		{
			r.push(3);
			cout << ",GOTO(6,F)=3��ջ" << endl;
		}
		else
			flag = false;
	}
	else if (i == 7)
	{
		if (c == 'F')
		{
			r.push(10);
			cout << ",GOTO(7,F)=10��ջ" << endl;
		}
		else
			flag = false;
	}
	else
		flag = false;
}
void Action0()//״̬0ʱ
{
	if (ch == 'i')//��һ��������Ϊi ,�ƽ�
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[0,i]=S5,״̬5��ջ" << endl;
		r.push(5);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == '(')//��һ��������Ϊ( ,�ƽ�
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[0,(]=S4,״̬4��ջ" << endl;
		r.push(4);
		l.push(ch);
		ch = strToken[point++];
	}
	else
		flag = false;
}
void Action1()//״̬1
{
	if (ch == '+')//��һ��������Ϊi ,�ƽ�
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[1,+]=S6,״̬6��ջ" << endl;
		r.push(6);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == '#')//�����ɹ�
	{
		flag = false;
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "Acc�������ɹ�" << endl;
	}
	else
		flag = false;
}
void Action2() //״̬2
{
	if (ch == '*')//��һ��������Ϊ* ,�ƽ�
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[2,*]=S7,״̬7��ջ" << endl;
		r.push(7);
		l.push(ch);
		ch = strToken[point++];
	}
	else if ((ch == '+') || (ch == ')') || (ch == '#'))//��һ��������Ϊ+������#��Լ
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.push('E');
		print(point - 1, strToken);
		cout << "r2: E��T��Լ";
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'E');
	}
	else
		flag = false;
}
void Action3()//״̬3
{
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#'))//��һ��������Ϊ+��*,����#��Լ
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.push('T');
		print(point - 1, strToken);
		cout << "r4: T��F��Լ";
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'T');
	}
	else
		flag = false;
}
void Action4_6_7(int x)//״̬4,6,7
{
	if (ch == 'i')//��һ��������Ϊi ,�ƽ�
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[";
		cout << x << ",i]=S5,״̬5��ջ" << endl;
		r.push(5);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == '(')//��һ��������Ϊ�� ,�ƽ�
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[";
		cout << x << ",(]=S4,״̬4��ջ" << endl;
		r.push(4);
		l.push(ch);
		ch = strToken[point++];
	}
	else
		flag = false;
}
void Action5()//״̬5
{
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#'))//��һ��������Ϊ+��*,����#��Լ
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.push('F');
		print(point - 1, strToken);
		cout << "r6: F��i��Լ";
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'F');
	}
	else
		flag = false;
}
void Action8()//״̬8
{
	if (ch == '+')//��һ��������Ϊ+ ,�ƽ�
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[8,+]=S6,״̬6��ջ" << endl;
		r.push(6);
		l.push(ch);
		ch = strToken[point++];
	}
	else if (ch == ')')//��һ��������Ϊ�� ,�ƽ�
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[8,)]=S11,״̬11��ջ" << endl;
		r.push(11);
		l.push(ch);
		ch = strToken[point++];
	}
	else
		flag = false;
}
void Action9()//״̬9
{
	if (ch == '*')//��һ��������Ϊ* ,�ƽ�
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		print(point - 1, strToken);
		cout << "ACTION[9,*]=S7,״̬7��ջ" << endl;
		r.push(7);
		l.push(ch);
		ch = strToken[point++];
	}
	else if ((ch == '+') || (ch == ')') || (ch == '#'))//��һ��������Ϊ+��,����#��Լ
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.pop();
		l.pop();
		l.push('E');
		print(point - 1, strToken);
		cout << "r1: E��E+T��Լ";
		r.pop();
		r.pop();
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'E');
	}
	else
		flag = false;
}
void Action10()//״̬10
{
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#'))//��һ��������Ϊ+��*,����#��Լ
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.pop();
		l.pop();
		l.push('T');
		print(point - 1, strToken);
		cout << "r3: T��T*F��Լ";
		r.pop();
		r.pop();
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'T');
	}
	else
		flag = false;
}
void Action11()//״̬11
{
	if ((ch == '+') || (ch == '*') || (ch == ')') || (ch == '#'))//��һ��������Ϊ+��*,����#��Լ
	{
		cout << step++ << '\t';
		r.out1();
		l.out();
		l.pop();
		l.pop();
		l.pop();
		l.push('F');
		print(point - 1, strToken);
		cout << "r5: F��(E)��Լ";
		r.pop();
		r.pop();
		r.pop();
		r.get_top(Y);
		Goto(int(Y), 'F');
	}
	else
		flag = false;
}
void run()//��Լ
{
	cout << "������Ҫ��Լ���ַ�����" << endl;
	cin >> strToken;
	cout << "����\t" << "״̬ջ\t" << "����ջ\t" << "���봮\t\t" << "����˵��" << endl;
	ch = strToken[point++];//��ȡ��һ���ַ�
	l.push('#');
	r.push(0);
	r.get_top(Y);
	while (flag)//ѭ����Լ
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
