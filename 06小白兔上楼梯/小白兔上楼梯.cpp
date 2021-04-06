#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
	int n;
	int upstair(int n);
	do {
		cout << "请输入楼梯台阶数： ";
		cin >> n;
		cout << "-----------------------------------------------" << endl;
		cout << "上" << n << "阶楼梯共有：" << upstair(n) << "种方式" << endl;
		cout << "-----------------------------------------------" << endl;
	} while (n);

	return 0;
}

int upstair(int n) {
	if (n == 0)return 0;
	else if (n == 1)return 1;
	else if (n == 2)return 2;
	else if (n == 3)return 4;
	else return upstair(n - 1) + upstair(n - 2) + upstair(n - 3);
}