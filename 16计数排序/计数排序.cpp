#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

void maxminOfArr(int* a, int n, int& min, int& max);
void countSort(int* a, int n);
int main() {
	int arr[] = { 8,3,7,1,2,4,6,5,0,-1,-4,-2,-3 };
	countSort(arr, 13);
	cout << "排序后：" << endl;
	for (int i = 0; i < 13; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}

//求出最大值和最小值
void maxminOfArr(int* a, int n, int& min, int& max)
{
	min = a[0];
	max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max)max = a[i];
		if (a[i] < min)min = a[i];
	}
}

void countSort(int* a, int n) {
	//求出最大值与最小值
	int max, min;
	maxminOfArr(a, n, min, max);
	//开辟辅助空间
	int* temp = new int[max - min + 1]{ 0 };//初始值为0

	//扫描待排序数组
	for (int i = 0; i < n; i++) {
		temp[a[i] - min]++;	//此处计数，减去最小值，负数变正，大数变小
	}

	//扫描临时数组
	int index = 0; //数组下标，用于回填
	for (int i = 0; i < max - min + 1; i++) {
		while (temp[i]) {
			a[index++] = i + min;//此处加上最小值
			temp[i]--;
		}
	}
}