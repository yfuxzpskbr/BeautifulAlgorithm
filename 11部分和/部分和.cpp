#include <iostream>
using namespace std;
bool isOk(int arr[], int n, int k, int cur);
void isOk(int arr[], int n, int k, int cur, int ans[], int index);
int main() {
	int arr[4] = { 1,3,5,7 };
	cout << "ԭ���飺";
	bool first = true;
	for (int i = 0; i < 4; i++) {
		if (first) {
			cout << "[";
			first = false;
		}
		else
		{
			cout << " ";
		}
		cout << arr[i];
	}
	cout << "]" << endl;
	int ans[4];
	isOk(arr, 4, 9, 0, ans, 0);
	return 0;
}

bool isOk(int arr[], int n, int k, int cur)
{
	bool is = false;
	if (k == 0) {//����1
		return true;
	}
	if (k < 0 || cur == n)return false;//����2
	//curѡ���߲�ѡ
	if (isOk(arr, n, k, cur + 1)) {//��ѡcur
		return true;
	}
	if (isOk(arr, n, k - arr[cur], cur + 1)) {//ѡcur
		return true;
	}
	return false;
}

void isOk(int arr[], int n, int k, int cur, int ans[], int index) {
	if (k == 0) {//�ҵ���
		cout << "YES";
		bool first = true;
		for (int i = 0; i < index; i++) {
			if (first) {
				cout << "[";
				first = false;
			}
			else
			{
				cout << " + ";
			}
			cout << ans[i];
		}
		cout << "]" << endl;
		exit(0);
	}
	if (cur == n) {
		return;
	}
	isOk(arr, n, k, cur + 1, ans, index);
	ans[index] = arr[cur];
	isOk(arr, n, k - arr[cur], cur + 1, ans, index + 1);
}