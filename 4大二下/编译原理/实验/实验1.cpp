#include <iostream>
#include <string.h>
#include <vector>
#include <utility>
using namespace std;
string key[] = { "if", "while", "for", "else","then","do","return" };     //第一类 关键词
char boundary[] = { '[',']',')','(',';' };         //第二类 分节符
char acc[] = { '+','-','*','/' };                   //第三类 算数运算符
string relation[] = { ">=","<=" ,">","<","=","==" }; //第四类 关系运算符
//第五类常数 第六类标识符
vector<string> ident;  //变量保存
//结果保存
vector<string> word;
vector<pair<int, string>> attribute;
vector<string> type;
vector<pair<int, int>> loc;

bool isDigtal(char a) {
	if (a >= '0' && a <= '9')
		return true;
	else return false;
}

bool isLetter(char a) {
	if (a >= 'a' && a <= 'z')
		return true;
	else return false;
}

bool isChe(char a) {
	if (a == '\n')
		return true;
	else return false;
}

bool isKey(string s) {
	for (int i = 0; i < 7; i++) {
		if (strcmp(s.c_str(), key[i].c_str()) == 0) {
			return true;
		}
	}
	return false;
}
bool isBound(char a) {
	for (int i = 0; i < 5; i++) {
		if (a == boundary[i]) {
			return true;
		}
	}
	return false;
}
bool isAcc(char a) {
	for (int i = 0; i < 4; i++) {
		if (a == acc[i]) {
			return true;
		}
	}
	return false;
}
void LexicalAnalysis(string s) {
	int row = 1, col = 1;
	int len = s.length();
	int i = 0;
	while (i < len) {
		if (isLetter(s[i])) {
			string tmp = "";
			while (isDigtal(s[i]) || isLetter(s[i])) {
				tmp += s[i];
				i++;
			}
			if (isKey(tmp)) {
				word.push_back(tmp);
				attribute.push_back(make_pair(1, tmp));
				type.push_back("关键字");
				loc.push_back(make_pair(row, col));
				col++;
			}
			else {
				int flag = 0;
				for (int j = 0; j < ident.size(); j++) {
					if (strcmp(tmp.c_str(), ident[j].c_str()) == 0) {
						flag = 1;
					}
				}
				if (!flag) {
					ident.push_back(tmp);
				}
				word.push_back(tmp);
				attribute.push_back(make_pair(6, tmp));
				type.push_back("标识符");
				loc.push_back(make_pair(row, col));
				col++;
			}
		}
		else if (isChe(s[i])) {
			row++;
			col = 1;
			i++;
		}
		else if (isDigtal(s[i])) {
			string tmp = "";
			while (isDigtal(s[i])) {
				tmp += s[i];
				i++;
			}
			if (isBound(s[i]) || s[i] == ' ') {
				word.push_back(tmp);
				attribute.push_back(make_pair(5, tmp));
				type.push_back("常数");
				loc.push_back(make_pair(row, col));
				col++;
			}
			else {
				while (isLetter(s[i]) || isDigtal(s[i])) {
					tmp += s[i];
					i++;
				}
				word.push_back(tmp);
				attribute.push_back(make_pair(7, tmp));
				type.push_back("ERROR");
				loc.push_back(make_pair(row, col));
				col++;
			}
		}
		else if (isBound(s[i])) {
			string tmp = "";
			tmp += s[i];
			word.push_back(tmp);
			attribute.push_back(make_pair(2, tmp));
			type.push_back("分界符");
			loc.push_back(make_pair(row, col));
			col++;
			i++;
		}
		else if (s[i] == '>' || s[i] == '<' || s[i] == '=') {
			string tmp = "";
			tmp += s[i];
			i++;
			if (s[i] == '=') {
				tmp += s[i];
				i++;
			}
			word.push_back(tmp);
			attribute.push_back(make_pair(4, tmp));
			type.push_back("关系运算符");
			loc.push_back(make_pair(row, col));
			col++;
		}
		else if (isAcc(s[i])) {
			string tmp = "";
			tmp += s[i];
			i++;
			if (isLetter(s[i]) || isDigtal(s[i])) {
				word.push_back(tmp);
				attribute.push_back(make_pair(3, tmp));
				type.push_back("算数运算符");
				loc.push_back(make_pair(row, col));
				col++;
			}
			else {
				while (s[i] != ' ' && !isBound(s[i])) {
					tmp += s[i];
					i++;
				}
				word.push_back(tmp);
				attribute.push_back(make_pair(7, tmp));
				type.push_back("ERROR");
				loc.push_back(make_pair(row, col));
				col++;
			}
		}
		else if (s[i] == ' ' || s[i] == '\n') {
			i++;
		}
		else {
			string tmp = "";
			while (s[i] != ' ' && !isBound(s[i])) {
				tmp += s[i];
				i++;
			}
			word.push_back(tmp);
			attribute.push_back(make_pair(7, tmp));
			type.push_back("ERROR");
			loc.push_back(make_pair(row, col));
			col++;
		}
	}
}
int main() {
	string s = "if i=0 then n++;\na<=b3%);\n";
	cout << s << endl;
	LexicalAnalysis(s);

	for (int i = 0; i < word.size(); i++) {
		cout << word[i] << "  (" << attribute[i].first << "," << attribute[i].second << ")  " << type[i] << "  (" << loc[i].first << "," << loc[i].second << ")" << endl;
	}
	return 0;
}

