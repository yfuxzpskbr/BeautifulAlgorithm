#include <iostream>
using namespace std;
unsigned long long fastPow1(int base, int pow);
unsigned long long fastPow2(unsigned long long base, int pow);
int main() {
	cout << "2^63 = " << fastPow1(2, 63) << endl;
	cout << "2^63 = " << fastPow2(2, 63) << endl;
	return 0;
}

//递归实现快速幂
unsigned long long fastPow1(int base, int pow) {
	if (pow == 0)return 1;
	unsigned long long ans = base;	//此时已经计算了一次方
	int ex = 1;//这是现在计算了的指数，每次指数翻一番
	while ((ex << 1) <= pow) {//翻翻后指数还没达到要求
		ans *= ans;	//翻翻
		ex <<= 1;	//记录当前已经计算的指数
	}
	//返回当前已经计算了的指数幂与未计算的指数幂
	return ans * fastPow1(base, pow - ex);
}

//运用位运算来进行快速幂
unsigned long long fastPow2(unsigned long long base, int pow) {
	/*
	* 例如计算2^20
	* 由于位运算是操作的补码，正数的补码就是本身
	* 就相当于计算2^0b10100
	* 就等于2^0b10000 * 2^0b00100(2^16 * 2^4)
	* ①ans=1			base = base^2(还未使用，下次循环使用)   pow=0b1010;
	* ②ans=1			base = base^4(还未使用，下次循环使用)   pow=0b101;
	* ③ans=base^4		base = base^8(还未使用，下次循环使用)	pow=0b10;
	* ④ans=base^4		base = base^16(还未使用，下次循环使用)	pow=0b1;
	* ⑤ans=base^20		base = base^32(还未使用，下次循环使用)	pow=0;	结束
	*/
	unsigned long long ans = 1;
	while (pow > 0) {//知道pow等于0才结束
		if (pow & 1)//相当于pow的二进制的最后一位是1，也相当于pow是奇数
		{
			ans *= base;	//乘以底数
		}
		base *= base;	//底数翻倍
		pow >>= 1;	//每次左移一位
	}
	return ans;
}