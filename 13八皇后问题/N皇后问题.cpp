#include <iostream>
using namespace std;
int n;//皇后个数
int recorder[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };//记录皇后位置，下标为行，数代表列
int ans;//答案
void dfs(int row);
bool check(int i, int j);
int main() {
	int res[10];

	//统计十个数据：打表
	n = 1;
	while (n <= 10) {
		ans = 0;
		dfs(0);
		res[n - 1] = ans;
		n++;
	}

	//打表解决问题
	cin >> n;
	while (n) {
		cout << res[n - 1] << endl;
		cin >> n;
	}
	return 0;
}

//dfs求解皇后问题
void dfs(int row) {
	if (row == n) {//出口
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {//每行八个格子依次试探
		if (check(row, i)) {//可以摆放皇后
			recorder[row] = i;//记录
			dfs(row + 1);//递归
			recorder[row] = -1;//回溯
		}
	}
}

//检测i_，j_位置是否可以摆放皇后
bool check(int i_, int j_) {
	for (int i = 0; i < 10; i++) {
		if (recorder[i] == -1) //越界就break
			break;
		if (recorder[i] == j_)//在一列上
			return false;
		if (i + recorder[i] == i_ + j_)//在对角线上
			return false;
		if (i - recorder[i] == i_ - j_)//在对角线上
			return false;
	}
	return true;
}