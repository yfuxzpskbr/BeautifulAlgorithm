#include <iostream>
#include <vector>
using namespace std;
void radixSort(int* arr, int n);
void pushToRadix(vector<int>* radix, int number, int r);
int main() {
	int arr[] = { 1,4,2,6,8,3,23,54,12,90,123,543,654,100,1234,763,912,2341 };
	radixSort(arr, 18);
	for (int i = 0; i < 18; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}

void radixSort(int* arr, int n) {
	//�ȿ���ʮ��Ͱ

	vector<int>* radix = new vector<int>[10];

	//�ҳ����ֵ
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max)max = arr[i];
	}

	//ͳ���������ĳ���
	int k = 0;
	if (max == 0)k = 1;
	while (max) {
		max /= 10;
		k++;
	}

	//����k�λ�������
	for (int i = 1; i <= k; i++) {
		//��Ͱ
		for (int j = 0; j < n; j++) {
			pushToRadix(radix, arr[j], i);
		}

		//ÿ�����궼Ҫ��Ͱ
		int p = 0;
		for (int j = 0; j < 10; j++) {
			int m = 0;
			while (m < radix[j].size()) {
				arr[p++] = radix[j].at(m++);
			}
			radix[j].clear();
		}
	}
}

//����Ӧ���ְ�λ����Ͱ
void pushToRadix(vector<int>* radix, int number, int r)
{
	int copy = number;
	int ca = 0;
	while (r) {
		ca = copy % 10;
		copy /= 10;
		r--;
	}
	radix[ca].push_back(number);
}