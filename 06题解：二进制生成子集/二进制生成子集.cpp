#include <iostream>
#include <set>
using namespace std;
int _2pow(int n);
set<set<int>> PickUseBinary(int* arr, int n);
int main() {
	set<set<int>> v = PickUseBinary(new int[3]{ 1,2,3 }, 3);
	for (auto x : v) {
		cout << "{";
		bool first = true;
		for (auto y : x) {
			if (first)first = !first;
			else cout << ",";
			cout << y;
		}
		cout << "}" << endl;
	}
	return 0;
}

int _2pow(int n)
{
	int res = 1;
	int base = 2;
	while (n) {
		if (n & 1) {
			res *= base;
		}
		base *= base;
		n >>= 1;
	}
	return res;
}

set<set<int>> PickUseBinary(int* arr, int n)
{
	set<set<int>> v;
	int max = _2pow(n);

	//����������
	for (int i = 0; i < max; i++) {
		int t = i;//����i����ֱ��ʹ��i����ֹӰ��ѭ��
		set<int> kl;
		int index = n - 1;
		//����t��ÿһλ
		do {
			if ((t & 1) == 1) {//��ǰλ��Ϊ1˵��ѡ������ѡ
				kl.insert(arr[index]);
			}
			t >>= 1;//��λ
			index--;
		} while (t);

		v.insert(kl);
	}
	return v;
}