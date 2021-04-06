#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> A(string s);
int main() {
	set<string> v = A("123");
	for (auto x : v) {
		cout << x << endl;
	}
	return 0;
}

//插空法求全排列
set<string> A(string s)
{
	int len = s.size();
	if (len <= 0)return set<string>();
	set<string> last, now;
	string t;
	t += s[0];
	last.insert(t);
	for (int i = 1; i < len; i++) {//每个字符拿去插
		set<string>::iterator it;
		for (it = last.begin(); it != last.end(); it++) {
			t = *it;//取上次的一种排列
			int t_len = t.size();
			//插
			for (int j = 0; j <= t_len; j++) {
				t.insert(t.begin() + j, s[i]);
				now.insert(t);
				t = *it;
			}
		}
		last = now;//更新上一次排列
		if (i != len - 1)now.clear();//清空非最后一次的now
	}
	return now;
}