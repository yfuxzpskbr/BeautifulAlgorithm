#include <iostream>
#include <string.h>
using namespace std;
void mergeSort(int arr[], int start, int end, int temp[]);
void merge(int arr[], int start, int mid, int end, int temp[]);
int main() {
	int arr[] = { 1,9,7,6,8,3,5,4,2,10 };
	int temp[10];
	mergeSort(arr, 0, 9, temp);
	cout << "�����" << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

//�鲢����
void mergeSort(int arr[], int start, int end, int temp[]) {
	if (start < end) {
		int mid = (start + end) >> 1;
		//�������
		mergeSort(arr, start, mid, temp);
		//�����ұ�
		mergeSort(arr, mid + 1, end, temp);
		//�鲢
		merge(arr, start, mid, end, temp);
	}
}

//�鲢
void merge(int arr[], int start, int mid, int end, int temp[])
{
	//����
	for (int i = start; i <= end; i++) {
		temp[i] = arr[i];
	}

	int left = start;//��ָ��
	int right = mid + 1;//��ָ��
	int current = start;//Ŀ��ָ��
	//�鲢
	while (left <= mid && right <= end) {
		if (temp[left] <= temp[right]) {
			arr[current] = temp[left];
			left++;
			current++;
		}
		else {
			arr[current] = temp[right];
			right++;
			current++;
		}
	}
	//����δ�ϲ������߲���
	while (left <= mid) {
		arr[current] = temp[left];
		left++;
		current++;
	}
	//δ������ұ߲��ֲ��ô���
}