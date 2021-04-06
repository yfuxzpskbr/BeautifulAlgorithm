#include <iostream>
#include <algorithm>
using namespace std;
void whoWillWin(int* a, int n);
int main() {
	int a[] = { 1 ,5 ,6 ,7 ,9, 12 ,14 ,17 };
	whoWillWin(a, 8);
	return 0;
}

void whoWillWin(int* a, int n)
{
	//a中存储玩具的位置
	int ans = 0;
	sort(a, a + n);//先排序，避免乱序
	if ((n & 1) == 1) {//奇数个
		for (int i = 0; i < n; i += 2) {
			//石子数是与前一个的距离，奇数第一个就是到1的距离
			ans ^= (i == 0 ? a[i] - 1 : a[i] - a[i - 1] - 1);
		}
	}
	else {//偶数个
		for (int i = 1; i < n; i += 2) {
			ans ^= (a[i] - a[i - 1] - 1);
		}
	}
	if (ans == 0) {//因为Alice先行，所以先行是0就输
		cout << "Bob will win." << endl;
	}
	else {
		cout << "Alice will win" << endl;
	}
}