#include <iostream>
using namespace std;
void printZ(int(*arr)[4], int row);
int main() {
	int arr[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	printZ(arr, 3);
	return 0;
}

void printZ(int(*arr)[4], int row)
{
	int r = 0, c = 0;
	bool up = true;
	//û��Խ��ʹ�ӡ
	while (r < row && c < 4) {
		if (up) {
			cout << arr[r][c] << ' ';
			if (r == 0 && c + 1 < 4) {//�����ߵ���һ��
				c++;
				up = !up;
				continue;
			}
			else if (c == 3 && r + 1 < row) {//�����ߵ����һ��
				r++;
				up = !up;
				continue;
			}
			r--;
			c++;
		}
		else {
			cout << arr[r][c] << ' ';
			if (c == 0 && r + 1 < row) {//�����ߵ���һ��
				r++;
				up = !up;
				continue;
			}
			else if (r == row - 1 && c + 1 < 4) {//�����ߵ����һ��
				c++;
				up = !up;
				continue;
			}
			r++;
			c--;
		}
	}
}