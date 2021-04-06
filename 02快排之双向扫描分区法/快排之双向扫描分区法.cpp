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
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//双向分区算法
int partition(int arr[], int p, int r) {
	int pivot = arr[p];	//第一个作为主元
	int left = p + 1;	//左指针
	int right = r;	//右指针
	while (left <= right) {
		while ((left <= right) && (arr[left] <= pivot))
			left++;	//此循环结束后，left指的一定大于主元
		while ((left <= right) && (arr[right] > pivot))
			right--;	//此循环结束后，right指的一定小于等于主元
		if (left < right) {
			swap(arr[left], arr[right]);
		}
	}
	swap(arr[p], arr[right]);
	return right;
}