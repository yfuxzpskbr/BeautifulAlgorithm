#include <iostream>
using namespace std;
using ulong = unsigned long long;
ulong myPow(ulong base, ulong pow);
int main() {
	cout << myPow(2, 1) << endl;
	return 0;
}

ulong myPow(ulong base, ulong pow)
{
	int result = 1;//最终结果
	while (pow != 0) {//指数不为0
		if (pow & 1) {//看该位是否为1
			result *= base;//为1就乘上该位的底数
		}
		base *= base;//底数翻倍
		pow >>= 1;//指数一位
	}
	return result;
}