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

	cout << "����������յ�����Ϣ:" << endl;
	getline(cin, str);
	const char* p = str.c_str();

	cout << "���������ϢΪ:" << endl;
	while (*p != '\0') {   //�Թؼ���Ϊ�ָ�ж���Ϣ���������
		//objtemp��������ʱ����
		string objtemp, time, angle, info, Direction, Distance, DistChng, DirChng, BodyDir, HeadDir;
		if (*p == '(' || *p == ')' || *p == ' ')
			p++;
		if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) {
			while (*p != ' ') {
				objtemp += *p;
				p++;
			}
			if (objtemp.compare(flag1) == 0) { //�ؼ���hear
				p++;    //���ݷֱ���ȡ
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
				cout << "��" << time << "����" << objtemp
					<< "��" << angle << "����������" << info << ")��" << endl;
			}
			if (objtemp.compare(flag2) == 0) { //�ؼ���see
				p++;    //���ݷֱ���ȡ
				while (*p != ' ') {
					time += *p;
					p++;
				}
				cout << "��" << time << "����" << objtemp << " ";
				p += 3;
				string word1;
				while (*p != ')') {
					word1 += *p;
					p++;
				}
				if (word1 == "ball")
					cout << "Ball" << "�����ҵ�";
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
				cout << "Direction��" << Direction << ", Distance��"
					<< Distance << "��DistChng��" << DistChng << "��DirChng��"
					<< DirChng << "��" << endl;
			}
			if (objtemp.compare(flag3) == 0) { //�ؼ���player
				string person;
				p++;    //���ݷֱ���ȡ
				while (*p != ')') {
					person += *p;
					p++;
				}
				cout << objtemp << " " << person << "�����ҵ�";
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
				cout << "Direction��" << Direction << ", Distance��"
					<< Distance << "��DistChng��" << DistChng << "��DirChng��"
					<< DirChng << "������BodyDir��" << BodyDir << "��HeadDir��"
					<< HeadDir << "��" << endl;
			}
			if (objtemp.compare(flag4) == 0) {  //�ؼ���goal
				p++;    //���ݷֱ���ȡ
				string name;
				while (*p != ')') {
					name += *p;
					p++;
				}
				cout << objtemp << " " << name << "�����ҵ�";
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
				cout << "Direction��" << Direction << ", Distance��" << Distance << "��" << endl;
			}
			if (objtemp.compare(flag5) == 0) { //�ؼ���Line
				p++;    //���ݷֱ���ȡ
				string name;
				while (*p != ')') {
					name += *p;
					p++;
				}
				cout << objtemp << " " << name << "���ҵĽǶ���";
				p += 2;
				while (*p != ' ' && *p != ')') {
					angle += *p;
					p++;
				}
				cout << angle << "�ȡ�" << endl;
			}
		}
	}
}

