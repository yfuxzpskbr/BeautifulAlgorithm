#include <iostream>
using namespace std;
int minNumberOfArray(int arr[], int start, int end);
int main() {
	int arr[] = { 6,8,10,1,3,5,6 };
	cout << "��������С��Ԫ���ǣ�" << arr[minNumberOfArray(arr, 0, 6)] << endl;
	return 0;
}

int minNumberOfArray(int arr[], int start, int end) {
	if (end - start == 1) {
		return arr[start] < arr[end] ? start : end;
	}
	int mid = (start + end) >> 1;
	if (arr[mid] > arr[start]) {//�������
		return minNumberOfArray(arr, mid, end);
	}
	else {
		return minNumberOfArray(arr, start, mid);
	}
}