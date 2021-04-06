#include <iostream>
using namespace std;
int maxOfPartArr(int* arr, int n);
int maxOfPartArr2(int* arr, int n);
int main() {
	int arr[] = { -1,-1,0,-1,-1,-1,-1 };
	cout << maxOfPartArr2(arr, 7) << endl;
	return 0;
}

int maxOfPartArr(int* arr, int n)
{
	//1 2 3 4 5
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] < max)max = arr[i];

	for (int i = 0; i < n; i++) {//起始点
		int t = 0;//临时最大值
		for (int j = i; j < n; j++) {//结束点
			t += arr[j];
			if (t > max)max = t;
		}
	}
	return max;
}

int maxOfPartArr2(int* arr, int n)
{
	//首先统计数组中最小值，防止全部是负数，并将这个最小值设为默认最大值
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < max)max = arr[i];
	}

	//遍历统计最大子数组
	int t = 0;	//临时最大值
	bool tag = false;	//目前是否遇到非负数
	for (int i = 0; i < n; i++) {
		//每次进入都判断当前的t和最大值的关系，取最大值
		if (tag && t > max)max = t;

		//如果当前位置的数大于0
		if (arr[i] >= 0) {
			t += arr[i];//加上
			tag = true;	 //遇到非负数了
		}

		//else if当前的数加上已累加的t大于0
		else if (arr[i] + t > 0) {
			t += arr[i];//加上
		}

		//当前的数加上已累加的t小于等于0
		else if (tag && arr[i] + t <= 0) {
			t = 0;//已累加清零
		}
	}

	//最后再更新最大值，防止全是正数
	if (tag && t > max)max = t;
	return max;
}