#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

int main() {
    cout << "��������˳������������ַ�y����֮����n\n";
    string outFlag = "y";

    while (outFlag != "n") {
        cout << "��������Ҫ�жϵ�FORTRAN ʵ�ͳ���\n";
        string digits;
        cin >> digits;

        enum States { Start, One, Two, Three, Four, Five, Six, Err };
        int i = 0, flag = 0;
        char ch;
        int length = digits.length();
        States state = Start;

        while (i < length && (ch = digits[i])) {
            switch (state) {
            case Start:
                if (isdigit(ch))
                    state = One;
                else if (ch == '.')
                    state = Six;
                else {
                    state = Err;
                    break;
                }
                i++;
                break;
            case One:
                if (isdigit(ch))
                    state = One;
                else if (ch == '.')
                    state = Two;
                else if (ch == 'E' || ch == 'D' || ch == 'e' || ch == 'd')
                    state = Three;
                else {
                    state = Err;
                    break;
                }
                i++;
                break;
            case Two:
                if (isdigit(ch))
                    state = Two;
                else if (ch == 'E' || ch == 'D' || ch == 'e' || ch == 'd')
                    state = Three;
                else {
                    state = Err;
                    break;
                }
                i++;
                break;
            case Three:
                if (ch == '+' || ch == '-')
                    state = Four;
                else if (isdigit(ch))
                    state = Five;
                else {
                    state = Err;
                    break;
                }
                i++;
                break;
            case Four:
                if (isdigit(ch))
                    state = Five;
                else {
                    state = Err;
                    break;
                }
                i++;
                break;
            case Five:
                if (isdigit(ch))
                    state = Five;
                else {
                    state = Err;
                    break;
                }
                i++;
                break;
            case Six:
                if (isdigit(ch))
                    state = Two;
                else {
                    state = Err;
                    break;
                }
                i++;
                break;
            case Err:
                if (flag == 0) {
                    cout << "Error at " << i + 1 << endl; // ����λ 
                    flag = 1;
                }
                i++;
                break;
            }
        }

        if (state == One || state == Two || state == Five)
            cout << "�Ϸ�����\n";
        else
            cout << "�Ƿ�����\n";

        while (true) {
            cout << "��Ҫ����������y|n:\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> outFlag;
            if (outFlag == "y" || outFlag == "n") {
                break;
            }
            else {
                cout << "�����������������\n";
            }
        }
    }
    return 0;
}
