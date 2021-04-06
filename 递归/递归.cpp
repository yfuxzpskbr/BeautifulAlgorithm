#include <iostream>
using namespace std;
int fun(int n);
void print(int i, int j);
int sum(int a[], int begin, int end);
int fib(int n);
string reverse(string str, int end);
int maxNumber(int m, int n);
void insertSort(int a[], int k);
int HanNota(int n, char res, char tool, char dis);
int main() {
	cout << "5�Ľ׳��ǣ�" << fun(5) << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "��ӡ0-10��";
	print(0, 10);
	cout << endl;
	cout << "--------------------------------------------------" << endl;
	int arr[] = { 1,3,8,4,5,2,7,6,9 };
	cout << "������ͣ�" << sum(arr, 0, 8) << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "��תgood��" << reverse("good", 3) << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "쳲��������еڰ����ǣ�" << fib(8) << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "24��18�����Լ����" << maxNumber(18, 24) << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "��������";
	insertSort(arr, 8);
	for (int i = 0; i < 9; i++)cout << arr[i] << " ";
	cout << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "��ŵ����" << endl;
	int cnt = HanNota(3, 'A', 'B', 'C');
	cout << "�����ƶ��ˣ�" << cnt << "��" << endl;
	cout << "--------------------------------------------------" << endl;
	return 0;
}
//��׳�
//�仯�����ǲ��������ݱ仯����ȷ���ݹ����
int fun(int n) {
	if (n == 1)return 1;
	return n * fun(n - 1);
}

//��ӡi��j
void print(int i, int j) {
	if (i > j)return;
	cout << i << " ";
	print(i + 1, j);
}

//�������
int sum(int a[], int begin, int end) {
	if (begin == end) {
		return a[begin];
	}
	return a[begin] + sum(a, begin + 1, end);
}

//��ת�ַ���
string reverse(string str, int end) {
	if (end < 0) {
		return "";
	}
	return str.at(end) + reverse(str, end - 1);
}

//쳲���������
int fib(int n) {
	if (n == 1 || n == 2)return 1;
	return fib(n - 1) + fib(n - 2);
}

//շת�����
int maxNumber(int m, int n) {
	if (m % n == 0)return n;
	return maxNumber(n, m % n);
}

//��������
void insertSort(int a[], int k) {
	//��С��������
	if (k == 0)return;
	insertSort(a, k - 1);
	int index = k - 1;
	int d = a[k];
	while (index > -1 && d < a[index]) {
		a[index + 1] = a[index];
		index--;
	}
	a[index + 1] = d;
}

//��ŵ��
int HanNota(int n, char res, char tool, char dis) {
	int cnt = 0;
	if (n == 1) {
		cout << n << "���̴�" << res << "ͨ��" << tool << "�ƶ�����" << dis << endl;
		return 1;
	}
	cnt += HanNota(n - 1, res, dis, tool);
	cout << n << "���̴�" << res << "ͨ��" << tool << "�ƶ�����" << dis << endl;
	cnt += 1;
	cnt += HanNota(n - 1, tool, res, dis);
	return cnt;
}