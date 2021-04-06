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
	cout << "��С����id�ǣ�" << minAvailableID3(arr, 0, 6) << endl;
	return 0;
}

//��������Ѱ��
int minAvailableID(int* arr, int n) {
	sort(arr, arr + n);//�������򣬵��ÿ⺯�� O(nlogn)

	//����O(n)
	for (int i = 0; i < n; i++) {
		if (arr[i] != i + 1) {//λ������С��id��ƥ��
			return i + 1;
		}
	}
	//1-n����ʹ���ˣ���˷���n+1
	return n + 1;
	//����ʱ�临�Ӷ�O(n)
}

//�����ռ䷨
int minAvailableID2(int* arr, int n) {
	//�����ռ���±��ʾid������0�������ݱ�ʾ�Ƿ��ù�
	//0��ʾû�ù���1��ʾ�ù�
	int* temp = new int[n + 1]{ 0 };//��ʼֵΪ0

	//ɨ��ԭ����
	for (int i = 0; i < n; i++) {
		if (arr[i] <= n) {//С�ڵ������鳤�ȵ�id�����Ϊ��ʹ�ù�
			temp[arr[i]] = 1;
		}
	}

	//Ѱ��
	for (int i = 1; i <= n; i++) {
		if (!temp[i])return i;
	}
	return n + 1;
}

//partition��
int minAvailableID3(int* arr, int p, int r) {
	if (p > r)return p + 1;//���淵����߽�+1
	int mid = partition(arr, p, r);
	int expect = mid + 1;
	if (arr[mid] == expect) {//ֵ���˵������������ݹ����ұ�
		minAvailableID3(arr, mid + 1, r);
	}
	else {//ֵ�����˵�����û�꣬�����
		minAvailableID3(arr, p, mid - 1);
	}
}

//�����㷨
void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

//�����㷨
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