#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;
int arr[100000];
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
int main() {
	int n = 100;
	for (int i = 0; i < n; i++) {
		arr[i] = n - i;
	}
	clock_t start = clock();
	selectionSort(arr, n);
	clock_t end = clock();
	cout << "选择排序用时：" << (end - start) << "ms" << endl;
	cout << "----------------------------------------" << endl;

	for (int i = 0; i < n; i++) {
		arr[i] = n - i;
	}
	start = clock();
	bubbleSort(arr, n);
	end = clock();
	cout << "冒泡排序用时：" << ((double)end - start) / CLOCKS_PER_SEC * 1000.0 << "ms" << endl;
	cout << "----------------------------------------" << endl;

	for (int i = 0; i < n; i++) {
		arr[i] = n - i;
	}
	start = clock();
	insertionSort(arr, n);
	end = clock();
	cout << "插入排序用时：" << ((double)end - start) / CLOCKS_PER_SEC * 1000.0 << "ms" << endl;
	cout << "----------------------------------------" << endl;

	for (int i = 0; i < n; i++) {
		arr[i] = n - i;
	}
	start = clock();
	sort(arr, arr + n);
	end = clock();
	cout << "sort排序用时：" << ((double)end - start) / CLOCKS_PER_SEC * 1000.0 << "ms" << endl;
	return 0;
}

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j])min = j;
		}
		if (min != i) {
			int t = arr[i];
			arr[i] = arr[min];
			arr[min] = t;
		}
	}
}
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

void insertionSort(int arr[], int n) {
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