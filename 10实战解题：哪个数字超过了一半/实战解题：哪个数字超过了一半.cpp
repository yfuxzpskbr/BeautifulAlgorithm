#include <iostream>
using namespace std;
void swap(int& a, int& b);
int partition(int* arr, int p, int r);
int selectK(int* arr, int p, int r, int k);
int main() {
	int arr[] = { 1,5,9,7,0,0,0,0,0,0 };
	cout << "超过数组一半的元素是：" << selectK(arr, 0, 9, 5) << endl;
	return 0;
}

//交换函数
void swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

//分区函数
int partition(int* arr, int p, int r) {
	int mid = (p + r) >> 1;
	int pivotIndex = p;
	if (arr[mid] >= arr[p] && arr[mid] <= arr[r] ||
		arr[mid] <= arr[p] && arr[mid] >= arr[r])
		pivotIndex = mid;
	if (arr[r] >= arr[p] && arr[r] <= arr[mid] ||
		arr[r] <= arr[p] && arr[r] >= arr[mid])
		pivotIndex = r;
	if (pivotIndex != p)
		swap(arr[p], arr[pivotIndex]);

	int pivot = arr[p];
	int left = p + 1;
	int right = r;
	while (left <= right) {
		while (left <= right && arr[left] <= pivot)left++;
		while (left <= right && arr[right] > pivot)right--;
		if (left < right)
			swap(arr[left], arr[right]);
	}
	if (right != p)
		swap(arr[p], arr[right]);
	return right;
}

//选择函数
int selectK(int* arr, int p, int r, int k) {
	if (p <= r) {
		int mid = partition(arr, p, r);
		int rank = mid - p + 1;
		if (rank == k)return arr[mid];
		else if (rank > k)return selectK(arr, p, mid - 1, k);
		else return selectK(arr, mid + 1, r, k - rank);
	}
}