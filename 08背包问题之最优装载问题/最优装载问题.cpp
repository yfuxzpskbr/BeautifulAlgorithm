#include <iostream>
using namespace std;
int main() {
	int n, c;
	//处理输入
	cin >> n >> c;
	int* w = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	int cnt = 0;//装的个数
	int package = 0;//背包已经装了的
	int i = 0;//从最轻的开始装
	while (true) {
		package += w[i];//装
		if (package <= c) {//能容下
			cnt++;//计数+1
			i++;//准备装下一个
		}
		else {//装不下就break
			break;
		}
	}
	//输出
	cout << cnt << endl;
	delete[]w;
	return 0;
}