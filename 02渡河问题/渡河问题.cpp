#include <iostream>
using namespace std;
int costTime(int needTime[], int people);
int main() {
	int test, n;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n;
		int* needTime = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> needTime[i];
		}
		cout << costTime(needTime, n) << endl;
		delete[]needTime;
	}
	return 0;
}

//���㻨�ѵ�����ʱ��
int costTime(int needTime[], int people)
{
	int time = 0;
	while (people) {
		if (people == 1) {//���ʣһ����
			time += needTime[0];
			break;
		}
		if (people == 2) {//���ʣ������
			time += needTime[1];
			break;
		}
		if (people == 3) {
			time += needTime[0] + needTime[1] + needTime[2];
			break;
		}
		//����һ��ÿ����������������������������
		int s1 = needTime[1] + needTime[0] + needTime[people - 1] + needTime[1];
		//������ÿ�������Ĵ������Ĺ���
		int s2 = needTime[people - 1] + needTime[0] + needTime[people - 2] + needTime[0];
		time += (s1 < s2 ? s1 : s2);
		people -= 2;
	}
	return time;
}