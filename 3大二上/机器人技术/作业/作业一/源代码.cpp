#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <string.h>

using namespace std;

int main() {
	string str;
	string flag1 = "hear", flag2 = "see", flag3 = "player", flag4 = "goal", flag5 = "Line";

	cout << "请输入你接收到的信息:" << endl;
	getline(cin, str);
	const char* p = str.c_str();

	cout << "解析后的信息为:" << endl;
	while (*p != '\0') {   //以关键词为分割，判断信息，分组输出
		//objtemp创建的临时对象
		string objtemp, time, angle, info, Direction, Distance, DistChng, DirChng, BodyDir, HeadDir;
		if (*p == '(' || *p == ')' || *p == ' ')
			p++;
		if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) {
			while (*p != ' ') {
				objtemp += *p;
				p++;
			}
			if (objtemp.compare(flag1) == 0) { //关键词hear
				p++;    //数据分别提取
				while (*p != ' ') {  //time
					time += *p;
					p++;
				}
				p++;
				while (*p != ' ') {  //angle
					angle += *p;
					p++;
				}
				p++;
				while (*p != ')') {  //info
					info += *p;
					p++;
				}
				cout << "在" << time << "周期" << objtemp
					<< "从" << angle << "方向听到了" << info << ")。" << endl;
			}
			if (objtemp.compare(flag2) == 0) { //关键词see
				p++;    //数据分别提取
				while (*p != ' ') {
					time += *p;
					p++;
				}
				cout << "在" << time << "周期" << objtemp << " ";
				p += 3;
				string word1;
				while (*p != ')') {
					word1 += *p;
					p++;
				}
				if (word1 == "ball")
					cout << "Ball" << "距离我的";
				p += 2;
				while (*p != ' ') {
					Direction += *p;
					p++;
				}
				p++;
				while (*p != ' ') {
					Distance += *p;
					p++;
				}
				p++;
				while (*p != ' ') {
					DistChng += *p;
					p++;
				}
				p++;
				while (*p != ')') {
					DirChng += *p;
					p++;
				}
				cout << "Direction是" << Direction << ", Distance是"
					<< Distance << "，DistChng是" << DistChng << "，DirChng是"
					<< DirChng << "。" << endl;
			}
			if (objtemp.compare(flag3) == 0) { //关键词player
				string person;
				p++;    //数据分别提取
				while (*p != ')') {
					person += *p;
					p++;
				}
				cout << objtemp << " " << person << "距离我的";
				p += 2;
				while (*p != ' ') {
					Direction += *p;
					p++;
				}
				p++;
				while (*p != ' ') {
					Distance += *p;
					p++;
				}
				p++;
				while (*p != ' ') {
					DistChng += *p;
					p++;
				}
				p++;
				while (*p != ' ') {
					DirChng += *p;
					p++;
				}
				p++;
				while (*p != ' ') {
					BodyDir += *p;
					p++;
				}
				p++;
				while (*p != ' ' && *p != ')') {
					HeadDir += *p;
					p++;
				}
				cout << "Direction是" << Direction << ", Distance是"
					<< Distance << "，DistChng是" << DistChng << "，DirChng是"
					<< DirChng << "，它的BodyDir是" << BodyDir << "和HeadDir是"
					<< HeadDir << "。" << endl;
			}
			if (objtemp.compare(flag4) == 0) {  //关键词goal
				p++;    //数据分别提取
				string name;
				while (*p != ')') {
					name += *p;
					p++;
				}
				cout << objtemp << " " << name << "距离我的";
				p += 2;
				while (*p != ' ') {
					Direction += *p;
					p++;
				}
				p++;
				while (*p != ' ' && *p != ')') {
					Distance += *p;
					p++;
				}
				cout << "Direction是" << Direction << ", Distance是" << Distance << "。" << endl;
			}
			if (objtemp.compare(flag5) == 0) { //关键词Line
				p++;    //数据分别提取
				string name;
				while (*p != ')') {
					name += *p;
					p++;
				}
				cout << objtemp << " " << name << "和我的角度是";
				p += 2;
				while (*p != ' ' && *p != ')') {
					angle += *p;
					p++;
				}
				cout << angle << "度。" << endl;
			}
		}
	}
}

