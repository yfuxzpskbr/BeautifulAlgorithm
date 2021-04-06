#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void countSort(int* arr, int n, int* temp);
int arr[5000000] = { 0 };
int temp[101] = { 0 };
int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < 5000000; i++) {
		arr[i] = rand() % 101;
	}
	clock_t start = clock();
	countSort(arr, 5000000, temp);
	clock_t end = clock();
	cout << "������ʱ��" << end - start << "ms" << endl;
	return 0;
}

void countSort(int* arr, int n, int* temp) {
	//����
	for (int i = 0; i < n; i++) {
		temp[arr[i]]++;
	}
	//ͳ��
	int index = 0;
	for (int i = 0; i <= 100; i++) {
		while (temp[i]) {
			arr[index++] = i;
			temp[i]--;
		}
	}
}