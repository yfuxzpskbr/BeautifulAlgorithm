#include <iostream>
using namespace std;
int x, y;
int gcd(int a, int b);
int LineEquation(int a, int b, int m);
int LineEquation10(int a, int b, int m);
int main() {
	LineEquation10(12, 5, 1);
	return 0;
}

//计算a、b的最大公约数同时计算ax+by = gcd的一组解
int gcd(int a, int b) {
	if (b == 0) {//递归出口
		x = 1;
		y = 0;
		return a;
	}
	int d = gcd(b, a % b);//此时x，y已经被下一次更新了
	int x1 = x;
	x = y;
	y = x1 - a / b * y;
	return d;
}

//求线性方程ax+by=m的一组整数解
int LineEquation(int a, int b, int m)
{
	int d = gcd(a, b);
	if (m % d) {
		cout << "无整数解" << endl;
		return d;
	}
	int fix = m / d;
	x *= fix;
	y *= fix;
	cout << a << "x" << " + " << b << "y" << " = " << m << "的一组解如下：" << endl;
	cout << "x=" << x << " , y=" << y << endl;
	return d;
}

//求线性方程的10组整数解
int LineEquation10(int a, int b, int m)
{
	int d = gcd(a, b);
	if (m % d) {
		cout << "无整数解" << endl;
		return d;
	}
	int fix = m / d;
	x *= fix;
	y *= fix;
	cout << a << "x" << " + " << b << "y" << " = " << m << " 的10组解如下：" << endl;
	for (int i = 0; i < 10; i++) {
		x += (b / d) * i;
		y -= (a / d) * i;
		cout << "x=" << x << " , y=" << y << endl;
	}
	return d;
}