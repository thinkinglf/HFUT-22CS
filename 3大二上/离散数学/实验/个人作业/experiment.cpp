#include <iostream>
#include <vector>

using namespace std;

void method(vector<int> vi, int start, int end) {
	// ֻ��һ����ȫ���У�����������˵���Ѿ������˵ݹ�Ļ������
	if (start == end) {
		// �����������ǰ����
		for (int i = 0; i <= end; i++) {
			cout << vi[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = start; i <= end; i++) {
			// ȷ��ÿһ�����ֶ�����
			swap(vi[start], vi[i]);
			// �ݹ飬������ʼλ��
			method(vi, start + 1, end);
			// ���ݣ�����ʼλ�ú͵�ǰλ�õ�Ԫ�ؽ�������,��ֹ�����ظ�
			swap(vi[start], vi[i]);
		} 
	}
}

int main() {
	//��ʹ�ø߰汾��IDE���г���
	vector<int> vi = { 1, 2, 3, 4, 5, 6 };
	cout << "1,2,3,4,5,6������Ԫ�ص�����ȫ����Ϊ��" << endl;
	// ����method�����������������������
	method(vi, 0, vi.size() - 1);
	return 0;
}