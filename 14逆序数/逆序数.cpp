#include <iostream>
using namespace std;
void mergesort(int* arr, int p, int r, int* temp);
void merge(int* a, int p, int mid, int r, int* temp);
int lixu = 0;
int main() {
	int a[] = { 6,5,1,3,9,2,4,7,0 };
	//0+1+2+2+4+3+1+8
	int t[9];
	mergesort(a, 0, 8, t);
	cout << "逆序数为：" << lixu << endl;
	return 0;
}

//归并排序
void mergesort(int* arr, int p, int r, int* temp)
{
	if (p < r) {
		int mid = (p + r) >> 1;
		mergesort(arr, p, mid, temp);
		mergesort(arr, mid + 1, r, temp);
		merge(arr, p, mid, r, temp);
	}
}

//归并
void merge(int* a, int p, int mid, int r, int* temp)
{
	//完成拷贝
	for (int i = p; i <= r; i++)temp[i] = a[i];

	//初始化各个指针
	int left = p;
	int right = mid + 1;
	int current = p;

	//当两边都没有扫描完时
	while (left <= mid && right <= r) {
		if (temp[left] <= temp[right]) {//左边加入，不用干什么
			a[current] = temp[left];
			current++;
			left++;
		}
		else {
			a[current] = temp[right];
			lixu += mid - left + 1;//右边加入时，统计逆序数+=左边剩余个数
			right++;
			current++;
		}
	}
	//左边没完左边加入，右边不用
	while (left <= mid) {
		a[current] = temp[left];
		current++;
		left++;
	}
}