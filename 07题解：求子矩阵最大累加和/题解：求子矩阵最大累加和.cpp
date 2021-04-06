#include <iostream>
#include <string.h>
using namespace std;
int maxOfPartArr2(int* arr, int row, int col);
int maxOfPartArr1(int* arr, int n);
int main() {
	int arr[3][3] = {
		{0,-1,-1},
		{-1,3,-1},
		{-1,-1,-1}
	};
	cout << maxOfPartArr2(&arr[0][0], 3, 3) << endl;
	return 0;
}

int maxOfPartArr2(int* arr, int row, int col) {
	int max = -999;
	for (int i = 0; i < row; i++) {//起始行
		int* temp = new int[col];
		memset(temp, 0, sizeof(int) * col);//每次更改起始行都要初始化为0
		for (int j = i; j < row; j++) {//结束行
			//对列求和
			for (int k = 0; k < col; k++) {
				temp[k] += arr[j * col + k];
			}
			//求和完毕
			int t = maxOfPartArr1(temp, col);
			if (t > max)max = t;
		}
	}
	return max;
}

int maxOfPartArr1(int* arr, int n)
{
	//找到数组最小值,防止全是负数
	int max = arr[0];
	bool tag = false;//表示目前是否遇到非负数
	for (int i = 1; i < n; i++) {
		if (arr[i] < max)max = arr[i];
	}

	int t = 0;	//li临时最大值
	//遍历扫描
	for (int i = 0; i < n; i++) {
		//每次更新最大值
		if (tag && t > max)max = t;
		if (arr[i] >= 0) {
			t += arr[i];
			tag = true;
		}
		else if (arr[i] + t >= 0) {
			t += arr[i];
		}
		else if (tag && arr[i] + t < 0) {
			t = 0;
		}
	}
	if (tag && t > max)max = t;
	return max;
}