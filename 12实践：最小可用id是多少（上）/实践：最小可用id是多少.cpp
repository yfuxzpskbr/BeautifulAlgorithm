#include <iostream>
#include <algorithm>
using namespace std;
void swap(int& a, int& b);
int partition(int arr[], int p, int r);
int minAvailableID(int* arr, int n);
int minAvailableID2(int* arr, int n);
int minAvailableID3(int* arr, int p, int r);
int main() {
	int arr[] = { 1,2,3,5,6,7,8 };
	cout << "最小可用id是：" << minAvailableID3(arr, 0, 6) << endl;
	return 0;
}

//先排序，再寻找
int minAvailableID(int* arr, int n) {
	sort(arr, arr + n);//快速排序，调用库函数 O(nlogn)

	//查找O(n)
	for (int i = 0; i < n; i++) {
		if (arr[i] != i + 1) {//位置与最小的id不匹配
			return i + 1;
		}
	}
	//1-n都被使用了，因此返回n+1
	return n + 1;
	//共计时间复杂度O(n)
}

//辅助空间法
int minAvailableID2(int* arr, int n) {
	//辅助空间的下标表示id，舍弃0，其内容表示是否被用过
	//0表示没用过，1表示用过
	int* temp = new int[n + 1]{ 0 };//初始值为0

	//扫描原数组
	for (int i = 0; i < n; i++) {
		if (arr[i] <= n) {//小于等于数组长度的id被标记为以使用过
			temp[arr[i]] = 1;
		}
	}

	//寻找
	for (int i = 1; i <= n; i++) {
		if (!temp[i])return i;
	}
	return n + 1;
}

//partition法
int minAvailableID3(int* arr, int p, int r) {
	if (p > r)return p + 1;//交叉返回左边界+1
	int mid = partition(arr, p, r);
	int expect = mid + 1;
	if (arr[mid] == expect) {//值相等说明左边已满，递归找右边
		minAvailableID3(arr, mid + 1, r);
	}
	else {//值不相等说明左边没完，找左边
		minAvailableID3(arr, p, mid - 1);
	}
}

//交换算法
void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//分区算法
int partition(int arr[], int p, int r) {
	int mid = (p + r) >> 1;
	int pivotIndex = p;
	if (arr[mid] >= arr[p] && arr[mid] <= arr[r] ||
		arr[mid] <= arr[p] && arr[mid] >= arr[r])
		pivotIndex = mid;
	if (arr[r] >= arr[p] && arr[r] <= arr[mid] ||
		arr[r] <= arr[p] && arr[r] >= arr[mid])
		pivotIndex = r;
	if (p != pivotIndex)
		swap(arr[p], arr[pivotIndex]);

	int pivot = arr[p];
	int left = p + 1;
	int right = r;
	while (left <= right) {
		while (left <= right && arr[left] <= pivot)left++;
		while (left <= right && arr[right] > pivot)right--;
		if (left < right) {
			swap(arr[left], arr[right]);
		}
	}
	if (p != right) {
		swap(arr[p], arr[right]);
	}
	return right;
}