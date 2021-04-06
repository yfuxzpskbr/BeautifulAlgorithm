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

//��ʼ������
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

//������nת��Ϊ3�������֣������
int make3(int n)
{
	int index = 0;
	do {
		da[index++] = n % 3;
		n /= 3;
	} while (n);
	return index;
}

//����3�������е�2�����Ҳ�ǵ����
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

//��������㷨
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