#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

void maxminOfArr(int* a, int n, int& min, int& max);
void countSort(int* a, int n);
int main() {
	int arr[] = { 8,3,7,1,2,4,6,5,0,-1,-4,-2,-3 };
	countSort(arr, 13);
	cout << "�����" << endl;
	for (int i = 0; i < 13; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}

//������ֵ����Сֵ
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
	//������ֵ����Сֵ
	int max, min;
	maxminOfArr(a, n, min, max);
	//���ٸ����ռ�
	int* temp = new int[max - min + 1]{ 0 };//��ʼֵΪ0

	//ɨ�����������
	for (int i = 0; i < n; i++) {
		temp[a[i] - min]++;	//�˴���������ȥ��Сֵ������������������С
	}

	//ɨ����ʱ����
	int index = 0; //�����±꣬���ڻ���
	for (int i = 0; i < max - min + 1; i++) {
		while (temp[i]) {
			a[index++] = i + min;//�˴�������Сֵ
			temp[i]--;
		}
	}
}