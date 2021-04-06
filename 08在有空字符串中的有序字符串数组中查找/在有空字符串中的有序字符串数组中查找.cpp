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
		while (arr[mid] == "") {//����Ϊ�վ�������
			mid--;
			if (mid < start) {//���ߵ��߽�ͳ��Իָ��˳�����������
				mid = (start + end) >> 1;
				break;
			}
		}
		while (arr[mid] == "") {//���߳����߽��������
			mid++;
			if (mid > end) {
				return -1;//�ұ߶����������߽�Ļ���˵������û�ҵ�
			}
		}
		//���ֲ��ҵ���·
		if (key == arr[mid])return mid;
		if (key > arr[mid])	start = mid + 1;
		if (key < arr[mid])	end = mid - 1;
	}
	return -1;
}