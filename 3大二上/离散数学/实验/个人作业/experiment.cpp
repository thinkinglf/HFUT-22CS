#include <iostream>
#include <vector>

using namespace std;

void method(vector<int> vi, int start, int end) {
	// 只有一个数全排列，就是它本身，说明已经到达了递归的基本情况
	if (start == end) {
		// 结束，输出当前排列
		for (int i = 0; i <= end; i++) {
			cout << vi[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = start; i <= end; i++) {
			// 确保每一个数字都可以
			swap(vi[start], vi[i]);
			// 递归，更换起始位置
			method(vi, start + 1, end);
			// 回溯，将起始位置和当前位置的元素交换回来,防止出现重复
			swap(vi[start], vi[i]);
		} 
	}
}

int main() {
	//请使用高版本的IDE运行程序
	vector<int> vi = { 1, 2, 3, 4, 5, 6 };
	cout << "1,2,3,4,5,6这六个元素的所有全排列为：" << endl;
	// 调用method函数，生成数组的所有排列
	method(vi, 0, vi.size() - 1);
	return 0;
}