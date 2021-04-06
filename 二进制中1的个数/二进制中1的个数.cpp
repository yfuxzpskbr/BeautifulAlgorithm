#include <iostream>
using namespace std;
int main() {
	int a = 123;
	int cnt = 0;
	//解法一：
	//每次让1从左到右移动一位，因为int是32位，故总共移动32次，即可
	for (int i = 0; i < 32; i++) {
		if ((a & (1 << i)) == (1 << i))cnt++;//注意、关系运算符优先于位运算符
	}
	cout << "解法一：" << cnt << endl;
	//解法二：
	//每次让数字左移一位，总共移动32次
	cnt = 0;
	for (int i = 0; i < 32; i++) {
		if ((1 & (a >> i)) == 1) {
			cnt++;
		}
	}
	cout << "解法二：" << cnt << endl;
	//解法三：
	//一个数字与上该数字减一可以消掉这个数字最后一个1，统计总共执行多少次与
	cnt = 0;
	while (a) {
		a = (a & (a - 1));
		cnt++;
	}
	cout << "解法三：" << cnt << endl;
	return 0;
}