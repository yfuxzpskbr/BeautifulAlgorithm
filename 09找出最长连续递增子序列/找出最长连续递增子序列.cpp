#include <iostream>
using namespace std;
void findMaxArr(int arr[], int n, int& start, int& end);
int main() {
	int arr[] = { 1,2,3,4,5,2,3,1,2,4,5,3,4,5,2,3,4,5,6 ,1,2,3,4,5,6,7 };
	int start, end;
	findMaxArr(arr, 26, start, end);
	cout << "����Ӵ���";
	for (int i = start; i <= end; i++) {
		cout << arr[i] << " ";
	}
	cout << "\t����" << end - start + 1 << "��" << endl;
	return 0;
}

void findMaxArr(int arr[], int n, int& start, int& end) {
	start = end = 0;
	int front = 0;
	int tail;
	//�ӵڶ���Ԫ�ؿ�ʼ�ң���һ����������
	for (tail = 1; tail < n; tail++) {
		if (arr[tail] >= arr[tail - 1])continue;
		if ((tail - front) > (end - start + 1)) {//���Ŀǰͳ�ƵĴ����ȴ�����ʷ�͸���
			end = tail - 1;
			start = front;
		}
		front = tail;
	}
	if ((tail - front) > (end - start + 1)) {//��ֹ������������
		end = tail - 1;
		start = front;
	}
}