#include<iostream>
using namespace std;
int a[5] = { 1,2,3,4,5 };
int vis[5] = { 1,1,1,1,1 };
int A(int n, int k);
int main() {
	cout << 5 << "! = " << A(5, 0) << endl;
	return 0;
}

int A(int n, int k) {
	int cnt = 0;//计算排列数
	if (n == k) {//递归出口
		bool first = true;
		cout << "[";
		for (int i = 0; i < n; i++) {
			if (first)first = false;
			else cout << ",";
			cout << a[i];
		}
		cout << "]" << endl;
		return 1;
	}
	//深度搜索
	for (int i = 1; i <= n; i++) {//从1到n选数
		if (vis[i - 1]) {//没有被选
			vis[i - 1] = 0;
			a[k] = i;
			cnt += A(n, k + 1);//递归调用
			vis[i - 1] = 1;//回溯
		}
	}
	return cnt;
}