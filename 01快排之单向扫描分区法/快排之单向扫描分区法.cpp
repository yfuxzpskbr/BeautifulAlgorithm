#include <iostream>
using namespace std;
void swap(int& a, int& b);
int partition(int arr[], int p, int r);
int main() {
	int arr[10] = { 4,1,8,0,2,6,7,3,5,9 };
	cout << "主元所在位置：" << partition(arr, 0, 9) << endl;
	cout << "-------------------------" << endl;
	cout << "分区完成后：" << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

//交换函数
void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

//单向扫描划分算法
int partition(int arr[], int p, int r) {
	int pivot = arr[p];
	int sp = p + 1;
	int bigger = r;
	while (sp <= bigger) {
		if (arr[sp] <= pivot) {//如果sp所指内容小于等于主元,sp右移
			sp++;
		}
		else {//否则交换sp的内容和bigger的内容，bigger左移
			if (sp < bigger)
				swap(arr[sp], arr[bigger]);
			bigger--;
			//注意这里sp不能++，因为bigger原本指的内容可能本就是大于主元的，
			//因此交换后还需要判断是否再次交换
		}
	}
	swap(arr[bigger], arr[p]);//将主元至于中间
	return bigger;
}