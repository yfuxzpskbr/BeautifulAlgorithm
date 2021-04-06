#include <iostream>
using namespace std;
bool check(int arr[9][9], int x, int y, int number);
void dfsPick(int arr[9][9], int x, int y);
int main() {
	int arr[9][9] = {
		{0,0,5,3,0,0,0,0,0},
		{8,0,0,0,0,0,0,2,0},
		{0,7,0,0,1,0,5,0,0},
		{4,0,0,0,0,5,3,0,0},
		{0,1,0,0,7,0,0,0,6},
		{0,0,3,2,0,0,0,8,0},
		{0,6,0,5,0,0,0,0,9},
		{0,0,4,0,0,0,0,3,0},
		{0,0,0,0,0,9,7,0,0}
	};
	dfsPick(arr, 0, 0);
	return 0;
}

bool check(int arr[9][9], int x, int y, int number)
{
	//���������
	for (int i = 0; i < 9; i++) {
		if (arr[x][i] == number || arr[i][y] == number)
			return false;
	}
	x = x / 3 * 3;
	y = y / 3 * 3;
	//���Ź���
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (arr[i][j] == number)
				return false;
		}
	}
	return true;
}

void dfsPick(int arr[9][9], int x, int y)
{
	if (x == 9) {//�ݹ����
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << "----------------------------" << endl;
		exit(0);
	}
	//�����ǰ���ǿհ׾�ѡ��
	if (arr[x][y] == 0) {
		//��1��9ѡ��
		for (int i = 1; i <= 9; i++) {
			//�������
			if (check(arr, x, y, i)) {
				arr[x][y] = i;//��¼
				dfsPick(arr, x + (y + 1) / 9, (y + 1) % 9);//����
				//arr[x][y] = 0;//����
			}
		}
		arr[x][y] = 0;//����
	}
	else {
		dfsPick(arr, x + (y + 1) / 9, (y + 1) % 9);
	}
}