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
	int cnt = 0;//����������
	if (n == k) {//�ݹ����
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
	//�������
	for (int i = 1; i <= n; i++) {//��1��nѡ��
		if (vis[i - 1]) {//û�б�ѡ
			vis[i - 1] = 0;
			a[k] = i;
			cnt += A(n, k + 1);//�ݹ����
			vis[i - 1] = 1;//����
		}
	}
	return cnt;
}