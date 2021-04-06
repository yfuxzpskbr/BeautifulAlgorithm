#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int arr[1001];
int vis[1001];
int main() {
	for (int i = 0; i < 1000; i++) {
		arr[i] = i + 1;
	}
	srand((unsigned int)time(nullptr));
	arr[1000] = rand() % 999 + 1;
	int r = rand() % 1000;
	int t = arr[1000];
	arr[1000] = arr[r];
	arr[r] = t;
	int k = 0;
	//运用的就是自己和自己的异或为0，自己和0的异或为自己
	//异或满足交换律

	//先异从1异或，一直到1000，此时不存在相同的数字，即1到1000都只出现一次
	for (int i = 1; i <= 1000; i++) {
		k = k ^ i;
	}
	//再异或数组中所有元素，若是非重复元素，则会与先前的数字异或变为0
	//若是重复的数字，则会被异或3次，异或两次为0，再与0异或即是那个重复的数字
	for (int i = 0; i <= 1000; i++) {
		k = k ^ arr[i];
	}
	cout << "位运算：" << k << endl;
	cout << "----------" << endl;

	//再开辟一块数组来完成

	for (int i = 0; i <= 1000; i++) {
		vis[arr[i]]++;
	}
	for (int i = 1; i <= 1000; i++) {
		if (vis[i] == 2) {
			cout << "再辟数组：" << i << endl;
			break;
		}
	}
	return 0;
}