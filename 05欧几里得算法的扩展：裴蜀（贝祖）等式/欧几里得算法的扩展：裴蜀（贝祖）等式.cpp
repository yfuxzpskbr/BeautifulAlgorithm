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

//����a��b�����Լ��ͬʱ����ax+by = gcd��һ���
int gcd(int a, int b) {
	if (b == 0) {//�ݹ����
		x = 1;
		y = 0;
		return a;
	}
	int d = gcd(b, a % b);//��ʱx��y�Ѿ�����һ�θ�����
	int x1 = x;
	x = y;
	y = x1 - a / b * y;
	return d;
}

//�����Է���ax+by=m��һ��������
int LineEquation(int a, int b, int m)
{
	int d = gcd(a, b);
	if (m % d) {
		cout << "��������" << endl;
		return d;
	}
	int fix = m / d;
	x *= fix;
	y *= fix;
	cout << a << "x" << " + " << b << "y" << " = " << m << "��һ������£�" << endl;
	cout << "x=" << x << " , y=" << y << endl;
	return d;
}

//�����Է��̵�10��������
int LineEquation10(int a, int b, int m)
{
	int d = gcd(a, b);
	if (m % d) {
		cout << "��������" << endl;
		return d;
	}
	int fix = m / d;
	x *= fix;
	y *= fix;
	cout << a << "x" << " + " << b << "y" << " = " << m << " ��10������£�" << endl;
	for (int i = 0; i < 10; i++) {
		x += (b / d) * i;
		y -= (a / d) * i;
		cout << "x=" << x << " , y=" << y << endl;
	}
	return d;
}