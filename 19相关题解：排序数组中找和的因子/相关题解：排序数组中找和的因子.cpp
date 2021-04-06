#include <iostream>
#include <ctime>
using namespace std;
void selectAddEqualK(int* arr, int n, int k);
int binarySearch(int* arr, int p, int r, int key);
void selectAddEqualK2(int* arr, int n, int k);
void selectAddEqualK3(int* arr, int n, int k);
int arr[100000];
int main()
{
	clock_t start, end;
	for (int i = 0; i < 100000; i++) {
		arr[i] = i + 1;
	}
	start = clock();
	selectAddEqualK(arr, 100000, 20);
	end = clock();
	cout << "常规法用时：" << end - start << "ms" << endl;
	cout << "---------------------------" << endl;

	start = clock();
	selectAddEqualK2(arr, 100000, 20);
	end = clock();
	cout << "二分法法用时：" << end - start << "ms" << endl;

	cout << "---------------------------" << endl;
	start = clock();
	selectAddEqualK3(arr, 100000, 20);
	end = clock();
	cout << "双向扫描法用时：" << end - start << "ms" << endl;
	return 0;
}

//常规思路O(n²)
void selectAddEqualK(int* arr, int n, int k) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == k) {
				cout << arr[i] << " + " << arr[j] << " = " << k << endl;
			}
		}
	}
}

//二分查找
int binarySearch(int* arr, int p, int r, int key) {
	if (p > r)return -1;//越界都没找到就返回false，说明没找到
	int mid = (p + r) >> 1;//计算中值
	if (arr[mid] == key)return mid;//相等返回下标
	else if (arr[mid] < key)return binarySearch(arr, mid + 1, r, key);//key大在右边找
	return binarySearch(arr, p, mid - 1, key);//否则在左边找
}

//二分查找思想O(nlogn)
void selectAddEqualK2(int* arr, int n, int k)
{
	for (int i = 0; i < n; i++) {
		int find = binarySearch(arr, 0, n - 1, k - arr[i]);
		if (find > i) {
			cout << arr[i] << " + " << k - arr[i] << " = " << k << endl;
		}
	}
}

//双向扫描思想O(n)
void selectAddEqualK3(int* arr, int n, int k) {
	int left = 0;
	int right = n - 1;
	while (left < right) {
		if (arr[left] + arr[right] == k) {
			cout << arr[left] << " + " << arr[right] << " = " << k << endl;
			left++;
			right--;
		}
		else if (arr[left] + arr[right] > k) {
			right--;
		}
		else {
			left++;
		}
	}
}