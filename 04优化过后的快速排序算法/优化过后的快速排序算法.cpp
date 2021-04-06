#include <iostream>
#include <ctime>
using namespace std;
void insertSort(int arr[], int p, int r);
int partition(int arr[], int p, int r);
void quickSort(int arr[], int p, int r);
void swap(int& a, int& b);
int arr[1000];
int main() {
	for (int i = 0; i < 1000; i++) {
		arr[i] = 1000 - i;
	}
	clock_t start = clock();
	quickSort(arr, 0, 999);
	clock_t end = clock();
	cout << "快速排序用时：" << end - start << "ms" << endl;
	cout << "------------------------" << endl;

	for (int i = 0; i < 1000; i++) {
		arr[i] = 1000 - i;
	}
	start = clock();
	insertSort(arr, 0, 999);
	end = clock();
	cout << "插入排序用时：" << end - start << "ms" << endl;
	return 0;
}

//插入排序
void insertSort(int arr[], int p, int r) {
	//n-1趟
	for (int i = p + 1; i <= r; i++) {
		int target = arr[i];
		int index = i - 1;
		//插入
		while (index > p - 1 && target < arr[index]) {
			arr[index + 1] = arr[index];
			index--;
		}
		arr[index + 1] = target;
	}
}

//交换算法
void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//分区算法
int partition(int arr[], int p, int r) {
	int mid = (p + r) >> 1;  //中间索引
	int pivotIndex = p;  //主元索引默认是第一个
	if ((arr[mid] >= arr[p] && arr[mid] <= arr[r]) ||
		(arr[mid] <= arr[p] && arr[mid] >= arr[r])) {
		//主元更改
		pivotIndex = mid;
	}
	if ((arr[r] >= arr[p] && arr[r] <= arr[mid]) ||
		(arr[r] <= arr[p] && arr[r] >= arr[mid])) {
		//主元更改
		pivotIndex = r;
	}
	//如果主元不是第一个就交换
	if (pivotIndex != p) {
		swap(arr[p], arr[pivotIndex]);
	}

	int pivot = arr[p];
	int left = p + 1;
	int right = r;
	while (left <= right) {
		while (left <= right && arr[left] <= pivot)left++;
		while (left <= right && arr[right] > pivot)right--;
		if (left < right) {
			swap(arr[left], arr[right]);
		}
	}
	swap(arr[p], arr[right]);
	return right;
}

//快速排序算法
void quickSort(int arr[], int p, int r) {
	if (p < r) {
		if (r - p < 8) {//小规模插入排序
			insertSort(arr, p, r);
		}
		else {
			//分区
			int mid = partition(arr, p, r);
			//递归排序左半部分
			quickSort(arr, p, mid - 1);
			//递归排序右半部分
			quickSort(arr, mid + 1, r);
		}
	}
}