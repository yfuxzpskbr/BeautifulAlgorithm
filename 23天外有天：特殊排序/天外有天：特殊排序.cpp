#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
string int2str(int t);
bool cmp(int a, int b);
string minSplice(int* arr, int n);
int main() {
	int arr[] = { 3,32,321 };
	cout << minSplice(arr, 3) << endl;
	return 0;
}

//����ת�ַ���
string int2str(int t)
{
	stringstream st;
	st << t;
	string str;
	st >> str;
	return str;
}

//�Ƚ���
bool cmp(int a_, int b_)
{
	string a = int2str(a_);
	string b = int2str(b_);
	return (a + b) < (b + a);
}

//������Сƴ��
string minSplice(int* arr, int n) {
	sort(arr, arr + n, cmp);
	string ans("");
	for (int i = 0; i < n; i++) {
		ans += int2str(arr[i]);
	}
	return ans;
}