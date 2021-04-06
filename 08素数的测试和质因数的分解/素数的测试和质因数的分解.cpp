#include <iostream>
#include <map>
using namespace std;
bool isPrime(int n);
void primeFactor(int n);
bool first = true;
int main() {
	/*for (int i = 2; i < 101; i++) {
		if (isPrime(i)) {
			cout << i << endl;
		}
	}*/
	primeFactor(45);
	return 0;
}

//判断n是不是质数
bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}

//质因数分解
void primeFactor(int n)
{
	int copy_n = n;
	cout << n << "=";
	for (int i = 2; i * i <= copy_n; i++) {
		while (n % i == 0) {
			if (first) {
				first = false;
				cout << i;
			}
			else {
				cout << "*" << i;
			}
			n /= i;
		}
	}
	if (n != 1) {
		cout << "*" << n;
	}
}