#include <iostream>
using namespace std;
void printArr(int(*arr)[5], int row, int col);
int main() {
	int arr[5][5] = {
		{1,2,3,4,5},
		{16,17,18,19,6},
		{15,24,25,20,7},
		{14,23,22,21,8},
		{13,12,11,10,9}
	};
	printArr(arr, 5, 5);
	return 0;
}

//顺时针打印矩阵
void printArr(int(*arr)[5], int row, int col) {
	int i, j;
	int leftRow = 0, leftCol = 0;
	int rightRow = row - 1, rightCol = col - 1;

	//左上顶点与右下顶点没有交叉便一直循环
	while (leftRow <= rightRow && leftCol <= rightCol) {
		//初始化上边起始位置
		i = leftRow;
		j = leftCol;
		while (j <= rightCol) {//打印上边
			cout << *(*(arr + i) + j) << " ";
			j++;
		}

		//初始化右边起始位置
		i++;
		j--;
		while (i <= rightRow) {//打印右边
			cout << *(*(arr + i) + j) << ' ';
			i++;
		}

		//初始化下边起始位置
		i--;
		j--;
		while (j >= leftCol) {//打印下边
			cout << *(*(arr + i) + j) << ' ';
			j--;
		}

		//初始化左边边起始位置
		j++;
		i--;
		while (i > leftRow) {//打印左边
			cout << *(*(arr + i) + j) << ' ';
			i--;
		}
		//缩小范围
		leftCol++;
		leftRow++;
		rightCol--;
		rightRow--;
	}
}