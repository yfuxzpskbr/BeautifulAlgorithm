#include <iostream>
#include <string>
using namespace std;

string strarr[] = { "a","b","","ba","","bc","cd","dc","" };
int indexOfStr(string arr[], int start, int end, string key);
int main() {
	cout << indexOfStr(strarr, 0, 8, "bc") << endl;
	return 0;
}

int indexOfStr(string arr[], int start, int end, string key) {
	while (start <= end) {
		int mid = (start + end) >> 1;
		while (arr[mid] == "") {//定中为空就向左走
			mid--;
			if (mid < start) {//左走到边界就尝试恢复退出，再向右走
				mid = (start + end) >> 1;
				break;
			}
		}
		while (arr[mid] == "") {//左走超过边界就向右走
			mid++;
			if (mid > end) {
				return -1;//右边都继续超过边界的话就说明是真没找到
			}
		}
		//二分查找的套路
		if (key == arr[mid])return mid;
		if (key > arr[mid])	start = mid + 1;
		if (key < arr[mid])	end = mid - 1;
	}
	return -1;
}