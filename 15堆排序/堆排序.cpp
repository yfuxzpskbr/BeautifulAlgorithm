#include <iostream>
using namespace std;
void maxHeap(int* arr, int root);
void maxHeapFixDown(int* arr, int n, int root);
void heapSort(int* arr, int n);
int main() {
	int arr[] = { 2,3,1,6,7,4,8,9,0 };
	heapSort(arr, 9);
	for (int i = 0; i < 9; i++)cout << arr[i] << " ";

	return 0;
}

//新建最大堆
void maxHeap(int* arr, int n) {
	//从最后一颗子树最大化
	for (int i = (n - 1) / 2 - 1; i >= 0; i--) {
		maxHeapFixDown(arr, n, i);
	}
}

//调整根和子树为最大堆
void maxHeapFixDown(int* arr, int n, int root) {
	//计算左右子树序号
	int left = root * 2 + 1;
	int right = root * 2 + 2;

	//如果没有左右子树
	if (left > n - 1)return;

	int max = left;//默认左边最大

	//存在右子树，且右子树比左子树大，就等于右子树
	if (right <= n - 1) {
		if (arr[right] > arr[left])max = right;
	}

	//如果根大于等于最大子树，说明根已经是最大堆，直接返回
	if (arr[root] >= arr[max])return;

	//交换值
	int temp = arr[root];
	arr[root] = arr[max];
	arr[max] = temp;

	//递归调用
	maxHeapFixDown(arr, n, max);
}

//堆排序
void heapSort(int* arr, int n) {
	//建堆
	maxHeap(arr, n);
	for (int i = n - 1; i >= 1; i--) {
		int t = arr[0];
		arr[0] = arr[i];
		arr[i] = t;
		maxHeapFixDown(arr, i, 0);
	}
}