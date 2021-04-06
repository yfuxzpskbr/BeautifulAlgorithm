#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void adjustArr(int arr[], int n);
int main() {
	int arr[20];
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 100 + 1;
	}
	adjustArr(arr, 20);
	cout << "µ÷Õûºó£º" << endl;
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}

void adjustArr(int arr[], int n)
{
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		while ((left <= right) && ((arr[left] & 1) == 1))left++;
		while ((left <= right) && ((arr[right] & 1) == 0))right--;
		if (left < right) {
			arr[left] = arr[left] ^ arr[right];
			arr[right] = arr[left] ^ arr[right];
			arr[left] = arr[left] ^ arr[right];
		}
	}
}