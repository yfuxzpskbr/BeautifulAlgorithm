#include <iostream>
using namespace std;
void init(int arr[5][5], int help[5][5][2]);
bool check(int help[5][5][2], int lefti, int leftj, int n);
int max1Arr(int arr[5][5], int help[5][5][2]);
int main(int argc, char* argv[]) {
	int arr[5][5] = {
		{0,1,1,1,1},
		{0,1,0,1,1},
		{0,1,1,1,1},
		{0,1,1,1,1},
		{0,0,0,0,0}
	};
	int help[5][5][2];
	cout << "�߽�Ϊ1������Ӿ���Ϊ: " << max1Arr(arr, help) << "��" << endl;
	return 0;
}

//��ʼ���㷨
void init(int arr[5][5], int help[5][5][2])
{
	for (int i = 4; i >= 0; i--) {
		for (int j = 4; j >= 0; j--) {
			help[i][j][0] = 0;
			help[i][j][1] = 0;
			if (arr[i][j] == 1) {
				if (i + 1 >= 5)help[i][j][1] = 1;//1��ʾ����
				else help[i][j][1] = help[i + 1][j][1] + 1;
				if (j + 1 >= 5)help[i][j][0] = 1;//0��ʾ�ұ�
				else help[i][j][0] = help[i][j + 1][0] + 1;
			}
		}
	}
}

//����㷨
bool check(int help[5][5][2], int lefti, int leftj, int n)
{
	int righti = lefti + n - 1;
	int rightj = leftj + n - 1;
	if (righti >= 5 || rightj >= 5)return false;
	if (help[lefti][leftj][0] >= n //�ϱ�
		&& help[lefti][leftj][1] >= n//���
		&& help[righti][leftj][0] >= n//�±�
		&& help[lefti][rightj][1] >= n)//�ұ�
		return true;
	return false;
}

//����Ӿ������
int max1Arr(int arr[5][5], int help[5][5][2])
{
	init(arr, help);
	int ans = 5;
	while (ans) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (check(help, i, j, ans))return ans;
				continue;
			}
		}
		ans--;
	}
	return 0;
}