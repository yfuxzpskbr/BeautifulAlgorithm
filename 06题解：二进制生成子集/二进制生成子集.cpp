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

	//二进制生成
	for (int i = 0; i < max; i++) {
		int t = i;//复制i，不直接使用i，防止影响循环
		set<int> kl;
		int index = n - 1;
		//处理t的每一位
		do {
			if ((t & 1) == 1) {//当前位上为1说明选，否则不选
				kl.insert(arr[index]);
			}
			t >>= 1;//移位
			index--;
		} while (t);

		v.insert(kl);
	}
	return v;
}