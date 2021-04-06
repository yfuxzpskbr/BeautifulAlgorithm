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
	cout << "选择排序：";
	for (int i = 0; i < 9; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << "-----------------" << endl;
	int arr1[] = { 1,4,2,7,6,5,9,0,13 };
	cout << "冒泡排序：";
	bobbleSort(arr1, 9);
	for (int i = 0; i < 9; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl << "-----------------" << endl;
	int arr2[] = { 1,4,2,7,6,5,9,0,13 };
	cout << "插入排序：";
	insertionSort(arr2, 9);
	for (int i = 0; i < 9; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl << "-----------------" << endl;
	int arr3[] = { 1,4,2,7,6,5,9,0,13 };
	cout << "希尔排序：";
	shellSort(arr3, 9);
	for (int i = 0; i < 9; i++) {
		cout << arr3[i] << " ";
	}
	cout << endl << "-----------------" << endl;
	return 0;
}

//选择排序
void selectSort(int arr[], int n) {
	//共进行n-1趟排序，每趟排序选出最小值，放到有序列末尾
	for (int i = 0; i < n - 1; i++) {
		int min = i;	//记录最小值位置
		//访问无序数组，找出最小值序号
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

//冒泡排序
void bobbleSort(int arr[], int n) {
	//共进行n-1趟排序
	for (int i = 0; i < n - 1; i++) {
		//每次遍历无序数组，最后一个将成为最大值
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

//插入排序
void insertionSort(int arr[], int n)
{
	//共n-1趟排序
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

//希尔排序
void shellSort(int arr[], int n)
{
	//外层循环不断缩小增量
	for (int interval = n / 2; interval > 0; interval /= 2) {
		//内层循环对每一组进行插入排序
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