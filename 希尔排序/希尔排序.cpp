#include <iostream>
#include <graphics.h>
using namespace std;
void selectSort(int arr[], int n);
void bobbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void shellSort(int arr[], int n);
int main(int argc, char* argv[]) {
	int arr[] = { 1,4,2,7,6,5,9,0,13 };
	selectSort(arr, 9);
	cout << "ѡ������";
	for (int i = 0; i < 9; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << "-----------------" << endl;
	int arr1[] = { 1,4,2,7,6,5,9,0,13 };
	cout << "ð������";
	bobbleSort(arr1, 9);
	for (int i = 0; i < 9; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl << "-----------------" << endl;
	int arr2[] = { 1,4,2,7,6,5,9,0,13 };
	cout << "��������";
	insertionSort(arr2, 9);
	for (int i = 0; i < 9; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl << "-----------------" << endl;
	int arr3[] = { 1,4,2,7,6,5,9,0,13 };
	cout << "ϣ������";
	shellSort(arr3, 9);
	for (int i = 0; i < 9; i++) {
		cout << arr3[i] << " ";
	}
	cout << endl << "-----------------" << endl;
	return 0;
}

//ѡ������
void selectSort(int arr[], int n) {
	//������n-1������ÿ������ѡ����Сֵ���ŵ�������ĩβ
	for (int i = 0; i < n - 1; i++) {
		int min = i;	//��¼��Сֵλ��
		//�����������飬�ҳ���Сֵ���
		for (int j = i + 1; j < n; j++) {
			if (arr[min] > arr[j])min = j;
		}
		if (min != i) {
			int t = arr[i];
			arr[i] = arr[min];
			arr[min] = t;
		}
	}
}

//ð������
void bobbleSort(int arr[], int n) {
	//������n-1������
	for (int i = 0; i < n - 1; i++) {
		//ÿ�α����������飬���һ������Ϊ���ֵ
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

//��������
void insertionSort(int arr[], int n)
{
	//��n-1������
	for (int i = 1; i < n; i++) {
		int target = arr[i];
		int index = i - 1;
		while (index > -1 && target < arr[index]) {
			arr[index + 1] = arr[index];
			index--;
		}
		arr[index + 1] = target;
	}
}

//ϣ������
void shellSort(int arr[], int n)
{
	//���ѭ��������С����
	for (int interval = n / 2; interval > 0; interval /= 2) {
		//�ڲ�ѭ����ÿһ����в�������
		for (int i = interval; i < n; i++) {
			int target = arr[i];
			int index = i - interval;
			while (index > -1 && target < arr[index]) {
				arr[index + interval] = arr[index];
				index -= interval;
			}
			arr[index + interval] = target;
		}
	}
}