#include <iostream>
using namespace std;
int candidate(int* arr, int n);
int candidate2(int* arr, int n);
int main() {
	int arr[] = { 1,2,1,3,1,4,1,5 };
	cout << "水王ID就是：" << candidate2(arr, 8) << endl;
	return 0;
}

//水王候选人函数
int candidate(int* arr, int n) {
	int candidate_;
	int nTime = 0;//上一个id出现次数初始值为0
	for (int i = 0; i < n; i++) {
		if (nTime == 0) {
			candidate_ = arr[i];
			nTime = 1;
			continue;
		}
		if (candidate_ == arr[i])nTime++;
		else nTime--;
	}
	return candidate_;//返回候选人即可
}

//扩展的水王候选人
int candidate2(int* arr, int n) {
	int candidate = arr[0];
	int nTime = 0;
	int cntOfLast = 0;
	for (int i = 0; i < n; i++) {
		if (arr[n - 1] == arr[i])cntOfLast++;
		if (nTime == 0) {
			candidate = arr[i];
			nTime = 1;
			continue;
		}
		if (arr[i] == candidate)nTime++;
		else nTime--;
	}
	if (cntOfLast >= n / 2)return arr[n - 1];
	else return candidate;
}