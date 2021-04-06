#include <iostream>
using namespace std;
int goBlock1(int x, int y);
int goBlock2(int x, int y);
int a[12][12];
int main() {
	cout << goBlock1(5, 5) << endl;
	cout << goBlock2(5, 5) << endl;
	return 0;
}

//递归解法
int goBlock1(int x, int y)
{
	if (x == 1 || y == 1)return 1;
	return goBlock1(x - 1, y) + goBlock1(x, y - 1);
}

//非递归解法
int goBlock2(int x, int y)
{
	//初始化第一行
	for (int i = 0; i < y; i++) {
		a[0][i] = 1;
	}
	//初始化第一列
	for (int i = 0; i < x; i++) {
		a[i][0] = 1;
	}

	//迭代求解，左+上
	for (int i = 1; i < x; i++) {
		for (int j = 1; j < y; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}
	return a[x - 1][y - 1];
}