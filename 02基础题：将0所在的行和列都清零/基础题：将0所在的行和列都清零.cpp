#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Point {
	int x;
	int y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
void clear0(int(*arr)[4], int row);
int main() {
	int arr[4][4] = {
		{1,2,3,4},
		{5,6,0,8},
		{9,0,11,12},
		{13,14,15,16}
	};
	clear0(arr, 4);

	//��ӡ
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << left << setw(2) << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

void clear0(int(*arr)[4], int row)
{
	vector<Point> v; //���ڼ�¼0��λ��

	//��һ��ɨ���¼0��λ��
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 4; j++) {
			if (!arr[i][j]) {
				v.push_back(Point(i, j));
			}
		}
	}

	//��¼��������
	for (int i = 0; i < v.size(); i++) {
		int x, y;
		x = v[i].x;
		y = v[i].y;
		//������
		for (int j = 0; j < 4; j++) {
			arr[x][j] = 0;
		}
		//������
		for (int j = 0; j < row; j++) {
			arr[j][y];
		}
	}
}