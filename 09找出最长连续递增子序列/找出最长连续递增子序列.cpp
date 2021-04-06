#include <iostream>
using namespace std;
void findMaxArr(int arr[], int n, int& start, int& end);
int main() {
	int arr[] = { 1,2,3,4,5,2,3,1,2,4,5,3,4,5,2,3,4,5,6 ,1,2,3,4,5,6,7 };
	int start, end;
	findMaxArr(arr, 26, start, end);
	cout << "最大子串：";
	for (int i = start; i <= end; i++) {
		cout << arr[i] << " ";
	}
	cout << "\t共计" << end - start + 1 << "个" << endl;
	return 0;
}

void findMaxArr(int arr[], int n, int& start, int& end) {
	start = end = 0;
	int front = 0;
	int tail;
	//从第二个元素开始找，第一个不用找了
	for (tail = 1; tail < n; tail++) {
		if (arr[tail] >= arr[tail - 1])continue;
		if ((tail - front) > (end - start + 1)) {//如果目前统计的串长度大于历史就更新
			end = tail - 1;
			start = front;
		}
		front = tail;
	}
	if ((tail - front) > (end - start + 1)) {//防止最长串出现在最后
		end = tail - 1;
		start = front;
	}
}