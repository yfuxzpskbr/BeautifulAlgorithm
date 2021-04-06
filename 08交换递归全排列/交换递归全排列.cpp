#include <iostream>
using namespace std;
int arr[7] = { 1,2,3,4,5,6,7 };
void A(int n, int k);
void swap(int& i, int& j);
int cnt;
int main() {
	int n = 7;
	A(n, 0);
	cout << n << "! = " << cnt << endl;
	return 0;
}

void A(int n, int k) {
	if (k == n) {//递归出口
		cnt++;
		bool first = true;
		cout << "[";
		for (int i = 0; i < n; i++) {
			if (first)first = false;
			else cout << ",";
			cout << arr[i];
		}
		cout << "]" << endl;
		return;
	}
	//每个元素和当前位置进行交换
	for (int i = k; i < n; i++) {
		swap(arr[i], arr[k]);//交换
		A(n, k + 1);//递归
		swap(arr[i], arr[k]);//回溯
	}
}

void swap(int& i, int& j) {
	int t = i;
	i = j;
	j = t;
}