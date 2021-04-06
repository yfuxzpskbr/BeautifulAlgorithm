#include <iostream>
using namespace std;
void swap(int& a, int& b);
int partition(int arr[], int p, int r);
int main() {
	int arr[10] = { 4,1,8,0,2,6,7,3,5,9 };
	cout << "��Ԫ����λ�ã�" << partition(arr, 0, 9) << endl;
	cout << "-------------------------" << endl;
	cout << "������ɺ�" << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

//��������
void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//˫������㷨
int partition(int arr[], int p, int r) {
	int pivot = arr[p];	//��һ����Ϊ��Ԫ
	int left = p + 1;	//��ָ��
	int right = r;	//��ָ��
	while (left <= right) {
		while ((left <= right) && (arr[left] <= pivot))
			left++;	//��ѭ��������leftָ��һ��������Ԫ
		while ((left <= right) && (arr[right] > pivot))
			right--;	//��ѭ��������rightָ��һ��С�ڵ�����Ԫ
		if (left < right) {
			swap(arr[left], arr[right]);
		}
	}
	swap(arr[p], arr[right]);
	return right;
}