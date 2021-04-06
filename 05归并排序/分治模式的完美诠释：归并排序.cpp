#include <iostream>
#include <string.h>
using namespace std;
void mergeSort(int arr[], int start, int end, int temp[]);
void merge(int arr[], int start, int mid, int end, int temp[]);
int main() {
	int arr[] = { 1,9,7,6,8,3,5,4,2,10 };
	int temp[10];
	mergeSort(arr, 0, 9, temp);
	cout << "排序后：" << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

//归并排序
void mergeSort(int arr[], int start, int end, int temp[]) {
	if (start < end) {
		int mid = (start + end) >> 1;
		//排序左边
		mergeSort(arr, start, mid, temp);
		//排序右边
		mergeSort(arr, mid + 1, end, temp);
		//归并
		merge(arr, start, mid, end, temp);
	}
}

//归并
void merge(int arr[], int start, int mid, int end, int temp[])
{
	//拷贝
	for (int i = start; i <= end; i++) {
		temp[i] = arr[i];
	}

	int left = start;//左指针
	int right = mid + 1;//右指针
	int current = start;//目的指针
	//归并
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
	//处理未合并完的左边部分
	while (left <= mid) {
		arr[current] = temp[left];
		left++;
		current++;
	}
	//未处理的右边部分不用处理
}