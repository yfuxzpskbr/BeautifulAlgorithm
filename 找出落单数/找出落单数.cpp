#include <iostream>
using namespace std;
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1 };
	int k = 0;
	//原理就是相同的异或等于0，故成对的异或起来全部变为0，最后0异或落单的就是落单的
	for (int i = 0; i < 19; i++) {
		k ^= arr[i];
	}
	cout << k << endl;
	return 0;
}