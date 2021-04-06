#include <iostream>
#include <string>
using namespace std;
int da[105];
int base[14];
void init();
int make3(int n);
int make3without3(int len);
void solve(int n);
int main()
{
	int n;
	cin >> n;
	solve(n);
	return 0;
}

//初始化底数
void init()
{
	for (int i = 0; i < 14; i++) {
		if (i == 0) {
			base[i] = 1;
		}
		else {
			base[i] = base[i - 1] * 3;
		}
	}
}

//将整数n转化为3进制数字，倒序的
int make3(int n)
{
	int index = 0;
	do {
		da[index++] = n % 3;
		n /= 3;
	} while (n);
	return index;
}

//处理3进制数中的2，最后也是倒叙的
int make3without3(int len)
{
	for (int i = 0; i < len; i++) {
		if (da[i] == 3) {
			da[i] = 0;
			da[i + 1]++;
		}
		else if (da[i] == 2) {
			da[i] = -1;
			da[i + 1]++;
		}
	}
	return (da[len] == 0 ? len : len + 1);
}

//解决问题算法
void solve(int n)
{
	init();
	int len = make3without3(make3(n));
	for (int i = len - 1; i >= 0; i--) {
		if (da[i] == 1) {
			cout << base[i];
		}
		else if (da[i] == -1) {
			cout << "-" << base[i];
		}
	}
	cout << endl;
}