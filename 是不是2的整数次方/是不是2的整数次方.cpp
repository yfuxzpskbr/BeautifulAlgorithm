#include <iostream>
using namespace std;
int main() {
	int a = 31;
	//判断一个数二进制中是否只含有1一个1
	//原理：一个数与这个数减一的与可以消掉这个数二进制中最低位的1
	if ((a & (a - 1)) == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}