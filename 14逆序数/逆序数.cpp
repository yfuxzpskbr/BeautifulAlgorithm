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
	cout << "������Ϊ��" << lixu << endl;
	return 0;
}

//�鲢����
void mergesort(int* arr, int p, int r, int* temp)
{
	if (p < r) {
		int mid = (p + r) >> 1;
		mergesort(arr, p, mid, temp);
		mergesort(arr, mid + 1, r, temp);
		merge(arr, p, mid, r, temp);
	}
}

//�鲢
void merge(int* a, int p, int mid, int r, int* temp)
{
	//��ɿ���
	for (int i = p; i <= r; i++)temp[i] = a[i];

	//��ʼ������ָ��
	int left = p;
	int right = mid + 1;
	int current = p;

	//�����߶�û��ɨ����ʱ
	while (left <= mid && right <= r) {
		if (temp[left] <= temp[right]) {//��߼��룬���ø�ʲô
			a[current] = temp[left];
			current++;
			left++;
		}
		else {
			a[current] = temp[right];
			lixu += mid - left + 1;//�ұ߼���ʱ��ͳ��������+=���ʣ�����
			right++;
			current++;
		}
	}
	//���û����߼��룬�ұ߲���
	while (left <= mid) {
		a[current] = temp[left];
		current++;
		left++;
	}
}