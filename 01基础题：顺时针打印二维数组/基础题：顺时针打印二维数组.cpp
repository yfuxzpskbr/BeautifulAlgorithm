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

//˳ʱ���ӡ����
void printArr(int(*arr)[5], int row, int col) {
	int i, j;
	int leftRow = 0, leftCol = 0;
	int rightRow = row - 1, rightCol = col - 1;

	//���϶��������¶���û�н����һֱѭ��
	while (leftRow <= rightRow && leftCol <= rightCol) {
		//��ʼ���ϱ���ʼλ��
		i = leftRow;
		j = leftCol;
		while (j <= rightCol) {//��ӡ�ϱ�
			cout << *(*(arr + i) + j) << " ";
			j++;
		}

		//��ʼ���ұ���ʼλ��
		i++;
		j--;
		while (i <= rightRow) {//��ӡ�ұ�
			cout << *(*(arr + i) + j) << ' ';
			i++;
		}

		//��ʼ���±���ʼλ��
		i--;
		j--;
		while (j >= leftCol) {//��ӡ�±�
			cout << *(*(arr + i) + j) << ' ';
			j--;
		}

		//��ʼ����߱���ʼλ��
		j++;
		i--;
		while (i > leftRow) {//��ӡ���
			cout << *(*(arr + i) + j) << ' ';
			i--;
		}
		//��С��Χ
		leftCol++;
		leftRow++;
		rightCol--;
		rightRow--;
	}
}