#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a, int b);
int LineEquation(int a, int b, int m);
int x = 0;
int y = 0;
int main() {
	int x_ = 1, y_ = 2, m = 3, n = 4, L = 5;
	int d = LineEquation(n - m, L, x_ - y_);
	L /= d;
	L = abs(L);
	x = (x % L + L) % L;
	cout << "要跳" << x << "次" << endl;
	return 0;
}

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

int LineEquation(int a, int b, int m) {
	int d = gcd(a, b);
	if (m % d) {
		cout << "无整数解" << endl;
		return d;
	}
	int n = m / d;
	x *= n;
	y *= n;
	return d;
}