#include <iostream>
using namespace std;
bool isAliceWin(int* a, int n);
int main() {
	int a[] = { 5,10,15 };
	cout << (isAliceWin(a, 3) ? "Alice Win" : "Bob Win") << endl;
	return 0;
}

bool isAliceWin(int* a, int n)
{
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans ^= a[i];
	}
	return ans;
}