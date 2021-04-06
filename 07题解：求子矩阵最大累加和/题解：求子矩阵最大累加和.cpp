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
	for (int i = 0; i < row; i++) {//��ʼ��
		int* temp = new int[col];
		memset(temp, 0, sizeof(int) * col);//ÿ�θ�����ʼ�ж�Ҫ��ʼ��Ϊ0
		for (int j = i; j < row; j++) {//������
			//�������
			for (int k = 0; k < col; k++) {
				temp[k] += arr[j * col + k];
			}
			//������
			int t = maxOfPartArr1(temp, col);
			if (t > max)max = t;
		}
	}
	return max;
}

int maxOfPartArr1(int* arr, int n)
{
	//�ҵ�������Сֵ,��ֹȫ�Ǹ���
	int max = arr[0];
	bool tag = false;//��ʾĿǰ�Ƿ������Ǹ���
	for (int i = 1; i < n; i++) {
		if (arr[i] < max)max = arr[i];
	}

	int t = 0;	//li��ʱ���ֵ
	//����ɨ��
	for (int i = 0; i < n; i++) {
		//ÿ�θ������ֵ
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