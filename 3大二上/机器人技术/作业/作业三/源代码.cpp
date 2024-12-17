#define PI 3.14159
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

typedef struct Point {
	string str;
	double x, y;
}iPoint;

typedef struct Data {
	string name;
	double r, theta;
}iData;

class Circle {
public:
	Point p1;
	double r0;
public:
	void setit3(Point p2, double r1) {
		p1 = p2;
		r0 = r1;
	}
};

vector<Point> p(13);
vector<Data> t(2);
Point result;

class Player {
public:
	void Orgi();
	void Dealing(vector<Point>&);
	void DataSet();
	Point Found(Data, vector<Point>&);
	void CircleToCircle(Circle, Circle, double);
	void Calculate(vector<Data>&, vector<Point>&);
};

void Player::Orgi() {
	//开始存储给定的固定点数据
	p[0].str = "C";  p[0].x = 0.0;  p[0].y = 0.0;
	p[1].str = "P1";  p[1].x = -52.5;  p[1].y = -32.0;
	p[2].str = "P2";  p[2].x = -52.5;  p[2].y = 32.0;
	p[3].str = "P3";  p[3].x = 52.5;  p[3].y = 32.0;
	p[4].str = "P4";  p[4].x = 52.5;  p[4].y = -32.0;
	p[5].str = "P5";  p[5].x = 0.0;  p[5].y = -32.0;
	p[6].str = "P6";  p[6].x = 0.0;  p[6].y = 32.0;
	p[7].str = "P7";  p[7].x = -30.0;  p[7].y = -7.0;
	p[8].str = "P8";  p[8].x = -30.0;  p[8].y = 7.0;
	p[9].str = "P9";  p[9].x = 30.0;  p[9].y = 7.0;
	p[10].str = "P10";  p[10].x = 30.0;  p[10].y = -7.0;
	p[11].str = "G1";  p[11].x = -52.5;  p[11].y = 0.0;
	p[12].str = "G2";  p[12].x = 52.5;  p[12].y = 0.0;
}

void Player::DataSet() {
	//开始存储两个定位点的数据
	cout << "请分别输入第一个和第二个点的名称name、"<<endl
		 << "              目标点距离自己的距离r、"<<endl
		 << "              以自己中心的极角theta" << endl;
	char ch;
	cin.get(ch);
	cin >> t[0].name >> t[0].r >> t[0].theta;
	cin.get(ch);

	cin.get(ch);
	cin >> t[1].name >> t[1].r >> t[1].theta;//(P8 22 0)(P7 27.7 30)    (P8 22 0)(P7 10.4 30)
	cin.get(ch);
	cout << "机器人在场上的绝对位置的坐标px,py分别是" << endl;
}

Point Player::Found(Data x, vector<Point>& p) {
	for (int i = 0; i < p.size(); i++) {
		if (x.name == p[i].str)
			return p[i];
	}
}


void Player::CircleToCircle(Circle c1, Circle c2, double theta0) {
	double a, b, c, d;
	a = c1.p1.x * c1.p1.x - 2 * c1.p1.x * c2.p1.x + c2.p1.x * c2.p1.x + c1.p1.y * c1.p1.y - 2 * c1.p1.y * c2.p1.y + c2.p1.y * c2.p1.y;
	b = -c1.r0 * c1.r0 * c1.p1.x + c1.r0 * c1.r0 * c2.p1.x + c2.r0 * c2.r0 * c1.p1.x - c2.r0 * c2.r0 * c2.p1.x + c1.p1.x * c1.p1.x * c1.p1.x - c1.p1.x * c1.p1.x * c2.p1.x - c1.p1.x * c2.p1.x * c2.p1.x + c1.p1.x * c1.p1.y * c1.p1.y - 2 * c1.p1.x * c1.p1.y * c2.p1.y + c1.p1.x * c2.p1.y * c2.p1.y + c2.p1.x * c2.p1.x * c2.p1.x + c2.p1.x * c1.p1.y * c1.p1.y - 2 * c2.p1.x * c1.p1.y * c2.p1.y + c2.p1.x * c2.p1.y * c2.p1.y;
	c = -c1.r0 * c1.r0 * c1.p1.y + c1.r0 * c1.r0 * c2.p1.y + c2.r0 * c2.r0 * c1.p1.y - c2.r0 * c2.r0 * c2.p1.y + c1.p1.x * c1.p1.x * c1.p1.y + c1.p1.x * c1.p1.x * c2.p1.y - 2 * c1.p1.x * c2.p1.x * c1.p1.y - 2 * c1.p1.x * c2.p1.x * c2.p1.y + c2.p1.x * c2.p1.x * c1.p1.y + c2.p1.x * c2.p1.x * c2.p1.y + c1.p1.y * c1.p1.y * c1.p1.y - c1.p1.y * c1.p1.y * c2.p1.y - c1.p1.y * c2.p1.y * c2.p1.y + c2.p1.y * c2.p1.y * c2.p1.y;
	d = sqrt((c1.r0 * c1.r0 + 2 * c1.r0 * c2.r0 + c2.r0 * c2.r0 - c1.p1.x * c1.p1.x + 2 * c1.p1.x * c2.p1.x - c2.p1.x * c2.p1.x - c1.p1.y * c1.p1.y + 2 * c1.p1.y * c2.p1.y - c2.p1.y * c2.p1.y) * (-c1.r0 * c1.r0 + 2 * c1.r0 * c2.r0 - c2.r0 * c2.r0 + a));
	if (fabs(a) > 1e-7) {
		if (theta0 < 0) {
			result.x = (b - d * c1.p1.y + d * c2.p1.y) / (2 * a);
			result.y = (c + d * c1.p1.x - d * c2.p1.x) / (2 * a);
		}
		else {
			result.x = (b + d * c1.p1.y - d * c2.p1.y) / (2 * a);
			result.y = (c - d * c1.p1.x + d * c2.p1.x) / (2 * a);
		}
	}
}

void Player::Calculate(vector<Data>& T, vector<Point>& p) {
	double k1, b1, k2, b2, d;
	Point p1, p2, p0;
	Circle c1, c2;
	p1 = Found(T[0], p);
	p2 = Found(T[1], p);
	c1.setit3(p1, T[0].r);
	c2.setit3(p2, T[1].r);
	CircleToCircle(c1, c2, (T[1].theta - T[0].theta));
}

void Player::Dealing(vector<Point>& p) {
	DataSet();
	Calculate(t, p);
	if (result.x != -999) {
		cout << "px=" << fixed << setprecision(2) << result.x << "，" << "py=" << fixed << setprecision(2) << result.y << endl;
	}
	else
		cout << "信息有误！无法求出同一个点！" << endl;
}

int main() {
	result.str = "p";    //赋初值
	result.x = -999;
	result.y = -999;
	Player s;
	s.Orgi();
	s.Dealing(p);
}
