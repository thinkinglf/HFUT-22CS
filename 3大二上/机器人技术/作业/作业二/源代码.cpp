#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

//点类  表示点的坐标
class Position {
public:
	float x, y;
public:
	void setit(float x1, float y1) {
		x = x1;
		y = y1;
	}
};

//直线类  表示直线的信息
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

//圆类  表示圆的信息
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

//矩形类  表示矩形的信息
class Rectangle {
public:
	Position bottom_left, top_right;//左下  右上两点的坐标
public:
	void setit4(Position bl, Position th) {
		bottom_left = bl;
		top_right = th;
	}
};

//求直线和直线的交点
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

//求直线和圆的交点
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

	if (e < 0) {  //无交点
		arr[0] = 0;        //存储交点情况
		arr[1] = '\0';
		cout << "直线与圆相离，无交点！" << endl;
	}
	else {
		float t = sqrt(e);
		x1 = (d + t) / (2 * a);
		y1 = k * x1 + b;
		x2 = (d - t) / (2 * a);
		y2 = k * x2 + b;
		if (t == 0) {       //一个交点
			arr[0] = 1;         //存储交点坐标
			arr[1] = x1;
			arr[2] = y1;
			arr[3] = '\0';
			cout << "（" << x1 << "，" << y1 << "）" << endl;
		}
		else {
			arr[0] = 2;        //存储交点坐标
			arr[1] = x1;
			arr[2] = y1;
			arr[3] = x2;
			arr[4] = y2;
			arr[5] = '\0';
			cout << "直线与圆相交，有两个交点：" << endl;
			cout << "（" << x1 << "，" << y1 << "）" << endl;
			cout << "（" << x2 << "，" << y2 << "）" << endl;
		}
	}
}

//通过两点坐标转化为直线方程
Line trans(Position p, Position p0) {
	Line l;
	float k, b;
	k = (p.x - p0.x) / (p.y - p0.y);
	b = p.y - k * p.x;
	l.setit2(-k, 1, -b);
	return l;
}

//求直线和矩形的交点
void LineToRectangle(Line l0, Rectangle r1, float* arr) {
	float x1, y1, x2, y2;
	Line l1, l2, l3, l4;
	Position p1, p2, p3, p4, h1, h2;
	int sum = 0;
	h1.x = r1.bottom_left.y;
	h1.y = r1.bottom_left.x; //左上坐标
	h2.x = r1.top_right.y;
	h2.y = r1.top_right.x;   //右下坐标
	l1 = trans(r1.bottom_left, h1);
	l2 = trans(r1.bottom_left, h2);
	l3 = trans(r1.top_right, h2);
	l4 = trans(r1.top_right, h1);   //转化为直线
	p1 = LineToLine(l0, l1);
	p2 = LineToLine(l0, l2);
	p3 = LineToLine(l0, l3);
	p4 = LineToLine(l0, l4);     //求交点
	if (p1.x >= h1.x && p1.x <= r1.bottom_left.x && p1.y >= r1.bottom_left.y && p1.y <= h1.y) {
		sum++;
		cout << "（" << p1.x << "，" << p1.y << "）";
		if (sum == 1) {         //存储交点坐标
			arr[0] = 1;
			arr[1] = p1.x;
			arr[2] = p1.y;
			arr[3] = '\0';
		}
	}
	if (p2.x >= r1.bottom_left.x && p2.x <= h2.x && p2.y >= r1.bottom_left.y && p2.y <= h2.y) {
		sum++;
		cout << "（" << p2.x << "，" << p2.y << "）";
		if (sum == 1) {         //存储交点坐标
			arr[0] = 1;
			arr[1] = p2.x;
			arr[2] = p2.y;
			arr[3] = '\0';
		}
		else if (sum == 2) {         //存储交点坐标
			arr[0] = 2;
			arr[3] = p2.x;
			arr[4] = p2.y;
			arr[5] = '\0';
		}
	}
	if (p3.x >= r1.top_right.x && p3.x <= h2.x && p3.y >= h2.y && p3.y <= r1.top_right.y) {
		sum++;
		cout << "（" << p3.x << "，" << p3.y << "）";
		if (sum == 1) {         //存储交点坐标
			arr[0] = 1;
			arr[1] = p3.x;
			arr[2] = p3.y;
			arr[3] = '\0';
		}
		else if (sum == 2) {         //存储交点坐标
			arr[0] = 2;
			arr[3] = p3.x;
			arr[4] = p3.y;
			arr[5] = '\0';
		}
	}
	if (p4.x >= h1.x && p4.x <= r1.top_right.x && p4.y >= h1.y && p4.y <= r1.top_right.y) {
		sum++;
		cout << "（" << p4.x << "，" << p4.y << "）";
		if (sum == 1) {         //存储交点坐标
			arr[0] = 1;
			arr[1] = p4.x;
			arr[2] = p4.y;
			arr[3] = '\0';
		}
		else if (sum == 2) {         //存储交点坐标
			arr[0] = 2;
			arr[3] = p4.x;
			arr[4] = p4.y;
			arr[5] = '\0';
		}
	}
	if (sum == 0) {        //存储交点情况
		arr[0] = 0;
		arr[1] = '\0';
		cout << "直线与矩形无交点！" << endl;
	}
	else {
		cout << "为直线与矩形的交点。" << endl;
	}
}

int main() {
	float a, b, c;
	Line L0;
	Position p1, p2;
	float arr[6];
	cout << "请输入原始直线的数据 a b c的值（ax+by+c=0）：" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	L0.setit2(a, b, c);
	int n;
	cout << "*********菜单*********" << endl;
	cout << "1.求直线与直线的交点情况" << endl;
	cout << "2.求直线与圆的交点情况" << endl;
	cout << "3.求直线与矩形的交点情况" << endl;
	cout << "0.退出程序" << endl;
	cout << "请输入你的选择：" << endl;
	cin >> n;
	switch (n) {
	case 0:
		break;
	case 1: {
		Line L;
		float e, f, g;
		cout << "请输入直线的数据 a b c的值（ax+by+c=0）：" << endl;
		cin >> e;
		cin >> f;
		cin >> g;
		L.setit2(e, f, g);
		p1 = LineToLine(L0, L);
		if (p1.x != -9999) {
			cout << "两直线的交点是：（" << p1.x << "，" << p1.y << "）" << endl;
		}
		else {
			cout << "两直线平行，无交点！" << endl;
		}
		break;
	}
	case 2: {
		Circle C1;
		float i, j, k;
		Position p;
		cout << "请输入圆的数据（圆心坐标、半径）：" << endl;
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
		cout << "请输入矩形的数据（左下、右上两点坐标）：" << endl;
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
		cout << "输入有误！" << endl;
		break;
	}
	return 0;
}
