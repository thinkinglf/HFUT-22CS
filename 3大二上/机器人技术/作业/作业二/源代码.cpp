#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

//����  ��ʾ�������
class Position {
public:
	float x, y;
public:
	void setit(float x1, float y1) {
		x = x1;
		y = y1;
	}
};

//ֱ����  ��ʾֱ�ߵ���Ϣ
class Line {
public:
	float A, B, C;
public:
	void setit2(float A1, float B1, float C1) {
		A = A1;
		B = B1;
		C = C1;
	}
};

//Բ��  ��ʾԲ����Ϣ
class Circle {
public:
	Position p1;
	float r;
public:
	void setit3(Position p, float r1) {
		p1 = p;
		r = r1;
	}
};

//������  ��ʾ���ε���Ϣ
class Rectangle {
public:
	Position bottom_left, top_right;//����  �������������
public:
	void setit4(Position bl, Position th) {
		bottom_left = bl;
		top_right = th;
	}
};

//��ֱ�ߺ�ֱ�ߵĽ���
Position LineToLine(Line l1, Line l2) {
	float x1, y1;
	Position n;
	if ((l1.A / l1.B) == (l2.A / l2.B)) {
		n.setit(-9999, -9999);
	}
	else {
		x1 = ((l1.B * l2.C) - (l2.B * l1.C)) / ((l1.A * l2.B) - (l2.A * l1.B));
		y1 = (-1) * (l1.A * x1 + l1.C) / l1.B;
		n.setit(x1, y1);
	}
	return n;
}

//��ֱ�ߺ�Բ�Ľ���
void LineToCircle(Line l1, Circle c1, float* arr) {
	float x1, y1, x2, y2, k, b, a, c, d, e;
	Position m1;
	double f = fabs((double)l1.A * c1.p1.x + l1.B * c1.p1.y + l1.C) / sqrt((double)l1.A * l1.A + l1.B * l1.B);

	if (l1.B != 0) {
		k = (-1) * l1.A / l1.B;
		b = (-1) * l1.C / l1.B;
	}
	else {
		k = 0;
		b = (-1) * l1.C / l1.B;
	}
	c = c1.p1.x * c1.p1.x + (b - c1.p1.y) * (b - c1.p1.y) - c1.r * c1.r;
	a = k * k + 1;
	d = (2 * c1.p1.x - 2 * k * (b - c1.p1.y));
	e = d * d - 4 * a * c;

	if (e < 0) {  //�޽���
		arr[0] = 0;        //�洢�������
		arr[1] = '\0';
		cout << "ֱ����Բ���룬�޽��㣡" << endl;
	}
	else {
		float t = sqrt(e);
		x1 = (d + t) / (2 * a);
		y1 = k * x1 + b;
		x2 = (d - t) / (2 * a);
		y2 = k * x2 + b;
		if (t == 0) {       //һ������
			arr[0] = 1;         //�洢��������
			arr[1] = x1;
			arr[2] = y1;
			arr[3] = '\0';
			cout << "��" << x1 << "��" << y1 << "��" << endl;
		}
		else {
			arr[0] = 2;        //�洢��������
			arr[1] = x1;
			arr[2] = y1;
			arr[3] = x2;
			arr[4] = y2;
			arr[5] = '\0';
			cout << "ֱ����Բ�ཻ�����������㣺" << endl;
			cout << "��" << x1 << "��" << y1 << "��" << endl;
			cout << "��" << x2 << "��" << y2 << "��" << endl;
		}
	}
}

//ͨ����������ת��Ϊֱ�߷���
Line trans(Position p, Position p0) {
	Line l;
	float k, b;
	k = (p.x - p0.x) / (p.y - p0.y);
	b = p.y - k * p.x;
	l.setit2(-k, 1, -b);
	return l;
}

//��ֱ�ߺ;��εĽ���
void LineToRectangle(Line l0, Rectangle r1, float* arr) {
	float x1, y1, x2, y2;
	Line l1, l2, l3, l4;
	Position p1, p2, p3, p4, h1, h2;
	int sum = 0;
	h1.x = r1.bottom_left.y;
	h1.y = r1.bottom_left.x; //��������
	h2.x = r1.top_right.y;
	h2.y = r1.top_right.x;   //��������
	l1 = trans(r1.bottom_left, h1);
	l2 = trans(r1.bottom_left, h2);
	l3 = trans(r1.top_right, h2);
	l4 = trans(r1.top_right, h1);   //ת��Ϊֱ��
	p1 = LineToLine(l0, l1);
	p2 = LineToLine(l0, l2);
	p3 = LineToLine(l0, l3);
	p4 = LineToLine(l0, l4);     //�󽻵�
	if (p1.x >= h1.x && p1.x <= r1.bottom_left.x && p1.y >= r1.bottom_left.y && p1.y <= h1.y) {
		sum++;
		cout << "��" << p1.x << "��" << p1.y << "��";
		if (sum == 1) {         //�洢��������
			arr[0] = 1;
			arr[1] = p1.x;
			arr[2] = p1.y;
			arr[3] = '\0';
		}
	}
	if (p2.x >= r1.bottom_left.x && p2.x <= h2.x && p2.y >= r1.bottom_left.y && p2.y <= h2.y) {
		sum++;
		cout << "��" << p2.x << "��" << p2.y << "��";
		if (sum == 1) {         //�洢��������
			arr[0] = 1;
			arr[1] = p2.x;
			arr[2] = p2.y;
			arr[3] = '\0';
		}
		else if (sum == 2) {         //�洢��������
			arr[0] = 2;
			arr[3] = p2.x;
			arr[4] = p2.y;
			arr[5] = '\0';
		}
	}
	if (p3.x >= r1.top_right.x && p3.x <= h2.x && p3.y >= h2.y && p3.y <= r1.top_right.y) {
		sum++;
		cout << "��" << p3.x << "��" << p3.y << "��";
		if (sum == 1) {         //�洢��������
			arr[0] = 1;
			arr[1] = p3.x;
			arr[2] = p3.y;
			arr[3] = '\0';
		}
		else if (sum == 2) {         //�洢��������
			arr[0] = 2;
			arr[3] = p3.x;
			arr[4] = p3.y;
			arr[5] = '\0';
		}
	}
	if (p4.x >= h1.x && p4.x <= r1.top_right.x && p4.y >= h1.y && p4.y <= r1.top_right.y) {
		sum++;
		cout << "��" << p4.x << "��" << p4.y << "��";
		if (sum == 1) {         //�洢��������
			arr[0] = 1;
			arr[1] = p4.x;
			arr[2] = p4.y;
			arr[3] = '\0';
		}
		else if (sum == 2) {         //�洢��������
			arr[0] = 2;
			arr[3] = p4.x;
			arr[4] = p4.y;
			arr[5] = '\0';
		}
	}
	if (sum == 0) {        //�洢�������
		arr[0] = 0;
		arr[1] = '\0';
		cout << "ֱ��������޽��㣡" << endl;
	}
	else {
		cout << "Ϊֱ������εĽ��㡣" << endl;
	}
}

int main() {
	float a, b, c;
	Line L0;
	Position p1, p2;
	float arr[6];
	cout << "������ԭʼֱ�ߵ����� a b c��ֵ��ax+by+c=0����" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	L0.setit2(a, b, c);
	int n;
	cout << "*********�˵�*********" << endl;
	cout << "1.��ֱ����ֱ�ߵĽ������" << endl;
	cout << "2.��ֱ����Բ�Ľ������" << endl;
	cout << "3.��ֱ������εĽ������" << endl;
	cout << "0.�˳�����" << endl;
	cout << "���������ѡ��" << endl;
	cin >> n;
	switch (n) {
	case 0:
		break;
	case 1: {
		Line L;
		float e, f, g;
		cout << "������ֱ�ߵ����� a b c��ֵ��ax+by+c=0����" << endl;
		cin >> e;
		cin >> f;
		cin >> g;
		L.setit2(e, f, g);
		p1 = LineToLine(L0, L);
		if (p1.x != -9999) {
			cout << "��ֱ�ߵĽ����ǣ���" << p1.x << "��" << p1.y << "��" << endl;
		}
		else {
			cout << "��ֱ��ƽ�У��޽��㣡" << endl;
		}
		break;
	}
	case 2: {
		Circle C1;
		float i, j, k;
		Position p;
		cout << "������Բ�����ݣ�Բ�����ꡢ�뾶����" << endl;
		cin >> i;
		cin >> j;
		cin >> k;
		p.setit(i, j);
		C1.setit3(p, k);
		LineToCircle(L0, C1, arr);
		break;
	}
	case 3: {
		Rectangle R1;
		float x1, y1, x2, y2;
		Position v1, v2;
		cout << "��������ε����ݣ����¡������������꣩��" << endl;
		cin >> x1;
		cin >> y1;
		cin >> x2;
		cin >> y2;
		v1.setit(x1, y1);
		v2.setit(x2, y2);
		R1.setit4(v1, v2);
		LineToRectangle(L0, R1, arr);	
		break;
	}
	default:
		cout << "��������" << endl;
		break;
	}
	return 0;
}
