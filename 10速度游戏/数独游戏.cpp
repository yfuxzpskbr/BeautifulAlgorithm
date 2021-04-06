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
	//检查行与列
	for (int i = 0; i < 9; i++) {
		if (arr[x][i] == number || arr[i][y] == number)
			return false;
	}
	x = x / 3 * 3;
	y = y / 3 * 3;
	//检查九宫格
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
	if (x == 9) {//递归出口
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << "----------------------------" << endl;
		exit(0);
	}
	//如果当前格不是空白就选择
	if (arr[x][y] == 0) {
		//从1到9选择
		for (int i = 1; i <= 9; i++) {
			//如果符合
			if (check(arr, x, y, i)) {
				arr[x][y] = i;//记录
				dfsPick(arr, x + (y + 1) / 9, (y + 1) % 9);//深搜
				//arr[x][y] = 0;//回溯
			}
		}
		arr[x][y] = 0;//回溯
	}
	else {
		dfsPick(arr, x + (y + 1) / 9, (y + 1) % 9);
	}
}