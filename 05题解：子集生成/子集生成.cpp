#include <iostream>
#include <set>
using namespace std;
set<set<int>> recersionPick(int* arr, int n, int cur);
set<set<int>> withoutRecersionPick(int* arr, int n);
int main() {
	set<set<int>> v = withoutRecersionPick(new int[3]{ 1,2,3 }, 3);
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

//递归形式
set<set<int>> recersionPick(int* arr, int n, int cur)
{
	if (cur == 0) {//处理第一个,递归出口
		set<set<int>> v;
		set<int>vb;
		//不选
		v.insert(vb);

		//选
		vb.insert(arr[0]);
		v.insert(vb);
		return v;
	}
	set<set<int>> last = recersionPick(arr, n, cur - 1);
	set<set<int>> now;
	set<set<int>>::iterator it;
	for (it = last.begin(); it != last.end(); it++) {
		//当前元素不选
		now.insert(*it);

		//当前元素选
		set<int>temp;
		temp = *it;
		temp.insert(arr[cur]);
		now.insert(temp);
	}
	return now;
}

//迭代形式
set<set<int>> withoutRecersionPick(int* arr, int n)
{
	set<set<int>> now;
	set<set<int>> last;
	set<int> t;

	last.insert(t);	//最开始是空集

	//迭代选择
	for (int i = 0; i < n; i++) {
		set<set<int>>::iterator it;
		for (it = last.begin(); it != last.end(); it++) {
			//不选
			now.insert(*it);
			//选
			t = *it;
			t.insert(arr[i]);
			now.insert(t);
			t.clear();	//清空临时的t
		}
		//迭代
		last = now;
		if (i != n - 1) {
			now.clear();	//清空最新的结果，下次记录
		}
	}
	return now;
}