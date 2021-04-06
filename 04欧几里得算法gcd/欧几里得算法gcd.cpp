#include <iostream>
using namespace std;
int gcd(int m, int n);
int main() {
	int x1 = 2, y1 = 19, x2 = 24, y2 = 5;
	cout << gcd(x2 - x1, y1 - y2) - 1 << endl;
	return 0;
}

int gcd(int m, int n)
{
	return (n == 0 ? m : gcd(n, m % n));
}