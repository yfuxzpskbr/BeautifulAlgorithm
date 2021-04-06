#include <iostream>
using namespace std;
void maxdisorder(int* arr, int n, int& left, int& right);
int main() {
	int arr[] = { 2,8,7,10,9 };
	int left, right;
	maxdisorder(arr, 5, left, right);
	if (left == 0)cout << "原数组有序,无子数组需要排序" << endl;
	else {
		cout << "[";
		for (int i = left; i <= right; i++) {
			cout << arr[i];
			cout << (i == right ? "]" : " ");
		}
		cout << "需要排序" << endl;
	}
	cout << "--------------------------" << endl;

	int arr2[] = { 2,3,7,4,1,5,6 };
	maxdisorder(arr2, 7, left, right);
	if (left == 0 && right == 0)cout << "原数组有序,无子数组需要排序" << endl;
	else {
		cout << "[";
		for (int i = left; i <= right; i++) {
			cout << arr2[i];
			cout << (i == right ? "]" : " ");
		}
		cout << "需要排序" << endl;
	}
	return 0;
}

void maxdisorder(int* arr, int n, int& left, int& right) {
	int max = arr[0];
	int min = arr[n - 1];

	right = 0;
	left = 0;

	//正向遍历
	for (int i = 0; i < n; i++) {
		if (arr[i] < max) {
			right = i;
		}
		if (arr[i] > max)max = arr[i];
	}

	//反向遍历
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] > min)left = i;
		if (arr[i] < min)min = arr[i];
	}
}