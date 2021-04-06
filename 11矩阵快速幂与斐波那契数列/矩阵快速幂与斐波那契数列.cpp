#include <iostream>
using namespace std;
using ulong = unsigned long long;
//矩阵类设计
class Matrix {
public:
	int data[2][2];
	Matrix();
	Matrix(int a00, int a01, int a10, int a11);
};
Matrix multi(Matrix a, Matrix b);
Matrix myPow(Matrix base, int pow);
ulong Fib(int n);
int main() {
	for (int i = 1; i <= 10; i++) {
		cout << Fib(i) << endl;
	}
	return 0;
}

//无参构造函数
Matrix::Matrix() {
	data[0][0] = 0;
	data[0][1] = 0;
	data[1][0] = 0;
	data[1][1] = 0;
}

//有参构造函数
Matrix::Matrix(int a00, int a01, int a10, int a11) {
	data[0][0] = a00;
	data[0][1] = a01;
	data[1][0] = a10;
	data[1][1] = a11;
}

//矩阵乘法运算
Matrix multi(Matrix a, Matrix b) {
	Matrix temp;
	temp.data[0][0] = a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0];
	temp.data[0][1] = a.data[0][0] * b.data[0][1] + a.data[0][1] * b.data[1][1];
	temp.data[1][0] = a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0];
	temp.data[1][1] = a.data[1][0] * b.data[0][1] + a.data[1][1] * b.data[1][1];
	return temp;
}

//矩阵幂运算
Matrix myPow(Matrix base, int pow) {
	Matrix res(1, 0, 0, 1);
	while (pow) {
		if (pow & 1) {
			res = multi(res, base);
		}
		base = multi(base, base);
		pow >>= 1;
	}
	return res;
}

//计算斐波那契数列第n项
ulong Fib(int n) {
	if (n <= 0)return -1;
	if (n == 1 || n == 2)return 1;
	Matrix a(1, 1, 0, 0);
	Matrix b(0, 1, 1, 1);
	b = myPow(b, n - 2);
	a = multi(a, b);
	return a.data[0][1];
}