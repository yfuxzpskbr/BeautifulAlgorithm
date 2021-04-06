#include <iostream>
using namespace std;
int main() {
	int a = 0b1001;
	//一个数字与1010101010...会将0所在位屏蔽，保留偶数位
	//一个数字与0101010101...会将0所在位屏蔽，保留奇数位
	//再将保留的奇数位左移保留的偶数位右移，最后将两者异或起来即可
	int b = ((a & 0xaaaaaaaa) >> 1);
	int c = ((a & 0x55555555) << 1);
	int ans = (b ^ c);
	cout << ans << endl;
	return 0;
}