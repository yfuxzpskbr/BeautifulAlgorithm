#include <iostream>
using namespace std;
int BinarySearchRec(int arr[], int start, int end, int key);
int BinarySearch(int arr[], int, int, int);
int main(int argc, char* argv[]) {
	int arr[] = { 0,1,2,3,4,5,6,7,8 ,9 };
	cout << "�ݹ飺" << BinarySearchRec(arr, 0, 9, 2) << endl;
	cout << "������" << BinarySearch(arr, 0, 9, 2) << endl;
	return 0;
}

//���ֲ��ҵݹ�
int BinarySearchRec(int arr[], int start, int end, int key) {
	if (start > end)return -1;
	int mid = (start + end) >> 1;
	int midKey = arr[mid];
	if (key > midKey) {
		return BinarySearchRec(arr, mid + 1, end, key);
	}
	else if (key < midKey) {
		return BinarySearchRec(arr, start, mid - 1, key);
	}
	return mid;
}

//�����Ķ��ֲ���
int BinarySearch(int arr[], int start, int end, int key) {
	while (start <= end) {
		int mid = (start + end) >> 1;
		int midValue = arr[mid];
		if (midValue == key) {
			return mid;
		}
		else if (midValue < key) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}