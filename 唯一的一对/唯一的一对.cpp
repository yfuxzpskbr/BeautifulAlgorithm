#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int arr[1001];
int vis[1001];
int main() {
	for (int i = 0; i < 1000; i++) {
		arr[i] = i + 1;
	}
	srand((unsigned int)time(nullptr));
	arr[1000] = rand() % 999 + 1;
	int r = rand() % 1000;
	int t = arr[1000];
	arr[1000] = arr[r];
	arr[r] = t;
	int k = 0;
	//���õľ����Լ����Լ������Ϊ0���Լ���0�����Ϊ�Լ�
	//������㽻����

	//�����1���һֱ��1000����ʱ��������ͬ�����֣���1��1000��ֻ����һ��
	for (int i = 1; i <= 1000; i++) {
		k = k ^ i;
	}
	//���������������Ԫ�أ����Ƿ��ظ�Ԫ�أ��������ǰ����������Ϊ0
	//�����ظ������֣���ᱻ���3�Σ��������Ϊ0������0������Ǹ��ظ�������
	for (int i = 0; i <= 1000; i++) {
		k = k ^ arr[i];
	}
	cout << "λ���㣺" << k << endl;
	cout << "----------" << endl;

	//�ٿ���һ�����������

	for (int i = 0; i <= 1000; i++) {
		vis[arr[i]]++;
	}
	for (int i = 1; i <= 1000; i++) {
		if (vis[i] == 2) {
			cout << "�ٱ����飺" << i << endl;
			break;
		}
	}
	return 0;
}