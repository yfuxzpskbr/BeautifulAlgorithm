#include <iostream>
using namespace std;
int gcd(int a, int b);
int LineEquation(int a, int b, int m);
int inverseSolve(int a, int n);
int x, y;
int main() {
	int T, n, B;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> B;
		inverseSolve(B, 9973);
		cout << x * n % 9973 << endl;
	}
	return 0;
}

//���a��n����Ԫ
int inverseSolve(int a, int n) {
	int d = LineEquation(a, n, 1);
	x = (x % n + n) % n;
	return d;
}

//��a��b���Լ��
int gcd(int a, int b) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int d = gcd(b, a % b);
	int x1 = x;
	x = y;
	y = x1 - a / b * y;
	return d;
}

//�����ʽax+by=m��������
int LineEquation(int a, int b, int m) {
	int d = gcd(a, b);
	if (m % d) {
		cout << "��������" << endl;
		return d;
	}
	int n = m / d;
	x *= n;
	y *= n;
	return d;
}