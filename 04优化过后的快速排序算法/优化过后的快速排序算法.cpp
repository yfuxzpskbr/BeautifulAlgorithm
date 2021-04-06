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
	cout << "����������ʱ��" << end - start << "ms" << endl;
	cout << "------------------------" << endl;

	for (int i = 0; i < 1000; i++) {
		arr[i] = 1000 - i;
	}
	start = clock();
	insertSort(arr, 0, 999);
	end = clock();
	cout << "����������ʱ��" << end - start << "ms" << endl;
	return 0;
}

//��������
void insertSort(int arr[], int p, int r) {
	//n-1��
	for (int i = p + 1; i <= r; i++) {
		int target = arr[i];
		int index = i - 1;
		//����
		while (index > p - 1 && target < arr[index]) {
			arr[index + 1] = arr[index];
			index--;
		}
		arr[index + 1] = target;
	}
}

//�����㷨
void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//�����㷨
int partition(int arr[], int p, int r) {
	int mid = (p + r) >> 1;  //�м�����
	int pivotIndex = p;  //��Ԫ����Ĭ���ǵ�һ��
	if ((arr[mid] >= arr[p] && arr[mid] <= arr[r]) ||
		(arr[mid] <= arr[p] && arr[mid] >= arr[r])) {
		//��Ԫ����
		pivotIndex = mid;
	}
	if ((arr[r] >= arr[p] && arr[r] <= arr[mid]) ||
		(arr[r] <= arr[p] && arr[r] >= arr[mid])) {
		//��Ԫ����
		pivotIndex = r;
	}
	//�����Ԫ���ǵ�һ���ͽ���
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

//���������㷨
void quickSort(int arr[], int p, int r) {
	if (p < r) {
		if (r - p < 8) {//С��ģ��������
			insertSort(arr, p, r);
		}
		else {
			//����
			int mid = partition(arr, p, r);
			//�ݹ�������벿��
			quickSort(arr, p, mid - 1);
			//�ݹ������Ұ벿��
			quickSort(arr, mid + 1, r);
		}
	}
}