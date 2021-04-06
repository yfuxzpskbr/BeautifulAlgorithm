#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;

int main() {
	cin >> n;
	string s;
	//处理输入
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		s += ch;
	}
	string s_ = s;
	//翻转
	reverse(s_.begin(), s_.end());
	//s_  翻转过的 BCBDCA
	//s 未翻转过的 ACDBCB
	string t;
	//给t添加字符
	for (int i = 0; i < n; i++) {
		if (s.compare(s_) < 0) {//谁小加谁的首字母
			t += s[0];
			s.erase(s.begin());
		}
		else {
			t += s_[0];
			s_.erase(s_.begin());
		}
	}
	//处理输出
	for (int i = 0; i < n; i++) {
		cout << t[i];
		if ((i + 1) % 80 == 0) {
			cout << endl;
		}
	}
	return 0;
}