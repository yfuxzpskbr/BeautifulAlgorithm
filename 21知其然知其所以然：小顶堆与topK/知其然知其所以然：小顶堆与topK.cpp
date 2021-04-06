#include <iostream>
using namespace std;
int minOfArr(int* arr, int k);
void makeMinHeap(int* arr, int n);
void minHeapFixDown(int* arr, int n, int root);
void dealX(int* arr, int& n, int k, int x);
void dealX2(int* arr, int& n, int k, int x);
void printArr(int* arr, int k);
int main() {
	int k;
	int x;
	cin >> k;
	int* arr = new int[k];
	cin >> x;
	int size = 0;
	while (x != -1) {
		dealX2(arr, size, k, x);
		cin >> x;
	}
	printArr(arr, k);

	return 0;
}

int minOfArr(int* arr, int k)
{
	int minIndex = 0;
	for (int i = 1; i < k; i++) {
		if (arr[i] < arr[minIndex])minIndex = i;
	}
	return minIndex;
}

void makeMinHeap(int* arr, int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--) {
		minHeapFixDown(arr, n, i);
	}
}

void minHeapFixDown(int* arr, int n, int root)
{
	//计算左子树，右子树
	int left = root * 2 + 1;
	int right = root * 2 + 2;

	//如果左子树不存在
	if (left >= n)return;

	//只有左子树时，默认是左子树最小
	int min = left;

	//两树都存在就比一下
	if (right < n) {
		if (arr[right] < arr[left])
			min = right;
	}

	//如果根已经是最小的话，说明不需要调整
	if (arr[root] < arr[min])return;

	//否则调整
	int temp = arr[root];
	arr[root] = arr[min];
	arr[min] = temp;

	//递归调整子树
	minHeapFixDown(arr, n, min);
}

void dealX(int* arr, int& n, int k, int x)
{
	if (n < k) {
		arr[n] = x;
		n++;
	}
	else {
		int minIndex = minOfArr(arr, k);
		if (x > arr[minIndex]) {
			arr[minIndex] = x;
		}
	}
}

void dealX2(int* arr, int& n, int k, int x)
{
	if (n < k - 1) {
		arr[n] = x;
		n++;
	}
	else if (n == k - 1) {
		arr[n] = x;
		n++;
		makeMinHeap(arr, k);
	}
	else {
		if (arr[0] < x) {
			arr[0] = x;
			minHeapFixDown(arr, k, 0);
		}
	}
}

void printArr(int* arr, int k)
{
	for (int i = 0; i < k; i++) {
		if (i == 0)cout << '[';
		cout << arr[i];
		cout << (i == k - 1 ? ']' : ' ');
	}
	cout << endl;
}