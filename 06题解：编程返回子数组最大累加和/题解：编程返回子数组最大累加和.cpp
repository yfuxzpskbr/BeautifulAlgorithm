#include <iostream>
using namespace std;
int maxOfPartArr(int* arr, int n);
int maxOfPartArr2(int* arr, int n);
int main() {
	int arr[] = { -1,-1,0,-1,-1,-1,-1 };
	cout << maxOfPartArr2(arr, 7) << endl;
	return 0;
}

int maxOfPartArr(int* arr, int n)
{
	//1 2 3 4 5
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] < max)max = arr[i];

	for (int i = 0; i < n; i++) {//��ʼ��
		int t = 0;//��ʱ���ֵ
		for (int j = i; j < n; j++) {//������
			t += arr[j];
			if (t > max)max = t;
		}
	}
	return max;
}

int maxOfPartArr2(int* arr, int n)
{
	//����ͳ����������Сֵ����ֹȫ���Ǹ��������������Сֵ��ΪĬ�����ֵ
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < max)max = arr[i];
	}

	//����ͳ�����������
	int t = 0;	//��ʱ���ֵ
	bool tag = false;	//Ŀǰ�Ƿ������Ǹ���
	for (int i = 0; i < n; i++) {
		//ÿ�ν��붼�жϵ�ǰ��t�����ֵ�Ĺ�ϵ��ȡ���ֵ
		if (tag && t > max)max = t;

		//�����ǰλ�õ�������0
		if (arr[i] >= 0) {
			t += arr[i];//����
			tag = true;	 //�����Ǹ�����
		}

		//else if��ǰ�����������ۼӵ�t����0
		else if (arr[i] + t > 0) {
			t += arr[i];//����
		}

		//��ǰ�����������ۼӵ�tС�ڵ���0
		else if (tag && arr[i] + t <= 0) {
			t = 0;//���ۼ�����
		}
	}

	//����ٸ������ֵ����ֹȫ������
	if (tag && t > max)max = t;
	return max;
}