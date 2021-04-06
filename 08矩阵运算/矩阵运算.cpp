#include <iostream>
using namespace std;
void plusArr(int* a, int* b, int row, int col, int* result);
void cutArr(int* a, int* b, int row, int col, int* result);
void multiplyArr(int* a, int* b, int row, int same, int col, int* result);
void numberMul(int* a, int num, int row, int col, int* result);
int main() {
	int a[3][3] = {
		{1,0,0},
		{0,2,0},
		{0,0,3}
	};
	int result[3][3];
	numberMul(a[0], 3, 3, 3, result[0]);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

void plusArr(int* a, int* b, int row, int col, int* result)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result[i * col + j] = a[i * col + j] + b[i * col + j];
		}
	}
}

void cutArr(int* a, int* b, int row, int col, int* result)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result[i * col + j] = a[i * col + j] - b[i * col + j];
		}
	}
}

void multiplyArr(int* a, int* b, int row, int same, int col, int* result)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result[i * col + j] = 0;
			for (int k = 0; k < same; k++) {
				result[i * col + j] += a[i * same + k] * b[k * same + j];
			}
		}
	}
}

void numberMul(int* a, int num, int row, int col, int* result)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result[i * col + j] = a[i * col + j] * num;
		}
	}
}