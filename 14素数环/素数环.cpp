#include <iostream>
using namespace std;
int ans[20];//记录答案
int vis[20];//标记数组
int n;//待输入数
bool isprime(int n);
void dfs(int t);
int main() {
	int cnt = 1;
	//处理第一个数
	vis[1] = 1;//vis[i]表示i是否已经选了，0表示没有，1表示选择了，下标从1开始
	ans[0] = 1;//ans用于记录答案，下标从0开始
	while (cin >> n) {//处理输入
		//初始化标记数组
		for (int i = 0; i <= n; i++) {
			vis[i] = 0;
		}

		cout << "Case " << cnt << ":" << endl;
		dfs(1);
		cnt++;
		cout << endl;
	}
	return 0;
}

//dfs填数
void dfs(int t) {
	if (t == n) {//递归出口
		if (isprime(ans[0] + ans[n - 1])) {//首位相加是素数
			bool first = true;//处理空格
			for (int i = 0; i < n; i++) {
				if (first)
					first = false;
				else
					cout << " ";
				cout << ans[i];
			}
			cout << endl;
		}
		return;
	}
	//尝试选择每一个数
	for (int i = 2; i <= n; i++) {
		if (vis[i] == 0 && isprime(i + ans[t - 1])) {
			//记录
			vis[i] = 1;
			ans[t] = i;
			//深搜
			dfs(t + 1);
			//回溯
			vis[i] = 0;
		}
	}
}

//判断n是不是素数
bool isprime(int n) {
	if (n <= 1)return false;
	int t = 2;
	while (t * t <= n) {
		if (n % t == 0)
			return false;
		t++;
	}
	return true;
}