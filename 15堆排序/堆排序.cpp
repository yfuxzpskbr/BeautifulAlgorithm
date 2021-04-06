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

//�½�����
void maxHeap(int* arr, int n) {
	//�����һ���������
	for (int i = (n - 1) / 2 - 1; i >= 0; i--) {
		maxHeapFixDown(arr, n, i);
	}
}

//������������Ϊ����
void maxHeapFixDown(int* arr, int n, int root) {
	//���������������
	int left = root * 2 + 1;
	int right = root * 2 + 2;

	//���û����������
	if (left > n - 1)return;

	int max = left;//Ĭ��������

	//�����������������������������󣬾͵���������
	if (right <= n - 1) {
		if (arr[right] > arr[left])max = right;
	}

	//��������ڵ������������˵�����Ѿ������ѣ�ֱ�ӷ���
	if (arr[root] >= arr[max])return;

	//����ֵ
	int temp = arr[root];
	arr[root] = arr[max];
	arr[max] = temp;

	//�ݹ����
	maxHeapFixDown(arr, n, max);
}

//������
void heapSort(int* arr, int n) {
	//����
	maxHeap(arr, n);
	for (int i = n - 1; i >= 1; i--) {
		int t = arr[0];
		arr[0] = arr[i];
		arr[i] = t;
		maxHeapFixDown(arr, i, 0);
	}
}