#include <iostream>
#include <ctime>
using namespace std;
int arr[100000000];
int binarySearch(int arr[], int start, int end, int key);
int Search(int arr[], int n, int key);
int main() {
	for (int i = 0; i < 100000000; i++) {
		arr[i] = i + 1;
	}
	clock_t start = clock();
	cout << "顺序查找：" << Search(arr, 100000000, 100000000) << endl;
	clock_t end = clock();
	cout << "顺序查找用时：" << ((double)end - start) / CLOCKS_PER_SEC * 1000.0 << "ms" << endl;
	cout << "----------------------------" << endl;

	start = clock();
	cout << "二分查找：" << binarySearch(arr, 0, 99999999, 100000000) << endl;
	end = clock();
	cout << "顺序查找用时：" << ((double)end - start) / CLOCKS_PER_SEC * 1000.0 << "ms" << endl;
	return 0;
}

int binarySearch(int arr[], int start, int end, int key)
{
	while (start <= end) {
		int mid = (start + end) >> 1;
		int midValue = arr[mid];
		if (midValue == key)return mid;
		else if (midValue < key) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}

int Search(int arr[], int n, int key)
{
	for (int i = 0; i < n; i++) {
		if (key == arr[i])return i;
	}
	return -1;
}