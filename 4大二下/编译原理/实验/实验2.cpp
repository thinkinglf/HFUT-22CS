#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
const int MaxLen = 20; //��ʼ��ջ�ĳ���
const int Length = 20;//��ʼ�����鳤��

char N1[5] = { 'E','G','T','S','F' };//���ս������
char N2[8] = { 'i','(',')','+','-','*','/','#' };//�ս������

char ch, X;//ch����ǰ�ַ���X��ȡջ��Ԫ��
char str1[Length];//�洢��Լ���ʽ

struct LL//ll(1)������Ĺ����ֳ�ʼ��
{
	char*c;
};
LL E[8] = { "TG","TG","error","error","error","error","error","error" };
LL G[8] = { "error","error","null","+TG","-TG","error","error","null" };
LL T[8] = { "FS","FS","error","error","error","error","error","error" };
LL S[8] = { "error","error","null","null","null","*FS","/FS","null" };
LL F[8] = { "i","(E)","error","error","error","error","error","error" };

class stack//ջ�Ĺ��켰��ʼ��
{
public:
	stack();//��ʼ��
	bool empty() const;//�Ƿ�Ϊ��
	bool full() const;//�Ƿ�����
	bool get_top(char &c)const;//ȡջ��Ԫ��
	bool push(const char c);//��ջ
	bool pop();//ɾ��ջ��Ԫ��
	void out();//���ջ��Ԫ��
	~stack() {}//����
private:
	int count;//ջ����
	char data[MaxLen];//ջ��Ԫ��
};
/************ջ�Ĺ���-��ʼ************/
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
/************ջ�Ĺ���-����************/

int length(char *c)
{
	int l = 0;
	for (int i = 0; c[i] != '\0'; i++)
		l++;
	return l;
}

void print(int i, char*c)//ʣ�����봮�����
{
	for (int j = i; j<Length; j++)
		cout << c[j];
	cout << '\t';
}

void run()
{
	bool flag = true;//ѭ������
	int step = 0, point = 0;//���衢ָ��
	int len;//����
	cout << "�����Լ���ַ�����" << endl;
	cin >> str1;
	ch = str1[point++];//��ȡ��һ���ַ�
	stack s;
	s.push('#');//ջ�����ݳ�ʼ��
	s.push('E');
	s.get_top(X);//ȡջ��Ԫ��
	cout << "����\t" << "����ջ\t" << "ʣ�����봮\t\t" << "���ò���ʽ\t" << "����" << endl;
	cout << step++ << '\t';
	s.out();
	print(point - 1, str1);
	cout << '\t' << '\t' << "��ʼ��" << endl;   //*******
	while (flag)
	{
		if ((X == N2[0]) || (X == N2[1]) || (X == N2[2]) || (X == N2[3]) || (X == N2[4]) || (X == N2[5]) || (X == N2[6]))
		{    //�ж��Ƿ�Ϊ�ս����������#��
			if (X == ch)   //�ս��,ʶ�𣬽�����һ�ַ���Լ
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
		else if (X == '#')//��Լ����
		{
			if (X == ch)
			{
				cout << step++ << '\t';
				s.out();
				print(point - 1, str1);
				cout << '\t' << X << "->" << ch << '\t' << '\t' << "����" << endl;  //*******
				s.pop();
				flag = false;
			}
			else
			{
				flag = false;
			}
		}
		else if (X == N1[0]) //���ս��E
		{
			for (int i = 0; i<8; i++)//�������
				if (ch == N2[i])
				{
					if (strcmp(E[i].c, "error") == 0)//����
					{
						flag = false;
					}
					else {             //�����ò���ʽ������ջ����
						s.pop();       //��E��ջ
						len = length(E[i].c) - 1;
						for (int j = len; j >= 0; j--)
							s.push(E[i].c[j]);     //���ķ�������ջ����֤����ĳ�ջ˳��
						cout << step++ << '\t';
						s.out();
						print(point - 1, str1);
						cout << X << "->" << E[i].c << '\t' << '\t' << "POP,PUSH(";    //********
						for (int j = len; j >= 0; j--)
							cout << E[i].c[j];
						cout << ")" << endl;      //����Ϊ��ʽ���
						s.get_top(X);      //����һ��ջ��Ԫ��
					}
				}
		}
		else if (X == N1[1])  //ͬ�ϣ����� G
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
						cout << '\t' << X << "->" << "��" << '\t' << '\t' << "POP" << endl;  //*******
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
		else if (X == N1[2]) //ͬ�� ���� T
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
		else if (X == N1[3])//ͬ�� ���� S
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

						cout << X << "->" << "��" << '\t' << '\t' << "POP" << endl;   //*******
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
		else if (X == N1[4])  //ͬ�� ���� F
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
		else //������
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
