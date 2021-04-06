#include <iostream>
using namespace std;
int minNumberOfArray(int arr[], int start, int end);
int main() {
	int arr[] = { 6,8,10,1,3,5,6 };
	cout << "数组中最小的元素是：" << arr[minNumberOfArray(arr, 0, 6)] << endl;
	return 0;
}

int minNumberOfArray(int arr[], int start, int end) {
	if (end - start == 1) {
		return arr[start] < arr[end] ? start : end;
	}
	int mid = (start + end) >> 1;
	if (arr[mid] > arr[start]) {//左边有序
		return minNumberOfArray(arr, mid, end);
	}
	else {
		return minNumberOfArray(arr, start, mid);
	}
}