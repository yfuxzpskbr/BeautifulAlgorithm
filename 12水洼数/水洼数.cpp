#include <iostream>
#include <string>
using namespace std;
void dfs(string map[], int r, int c, int i, int j);
int main() {
	int n, m;
	//处理输入
	cin >> n >> m;
	string* map = new string[n];
	for (int i = 0; i < n; i++) {
		map[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//算法部分
	int cnt = 0;//用于计数
	//遍历数组数水洼
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'W') {//只有是水才开始数
				dfs(map, n, m, i, j);
				cnt++;//每次数完计数+1
			}
		}
	}
	//输出
	cout << cnt << endl;
	delete[]map;
	return 0;
}

//数水洼算法
void dfs(string map[], int r, int c, int i, int j) {
	map[i][j] = '.';//每次数过的变为旱地

	//朝水洼八个方向数
	for (int i_ = -1; i_ <= 1; i_++) {
		for (int j_ = -1; j_ <= 1; j_++) {
			if (i_ == 0 && j_ == 0)continue;//自身不要
			if (i + i_ >= 0 && i + i_ < r && j + j_ >= 0 && j + j_ < c) {//边界检测
				if (map[i + i_][j + j_] == 'W') {//是水洼就dfs数
					dfs(map, r, c, i + i_, j + j_);
				}
			}
		}
	}
}