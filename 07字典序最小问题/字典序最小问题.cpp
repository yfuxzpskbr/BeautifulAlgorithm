#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;

int main() {
	cin >> n;
	string s;
	//��������
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		s += ch;
	}
	string s_ = s;
	//��ת
	reverse(s_.begin(), s_.end());
	//s_  ��ת���� BCBDCA
	//s δ��ת���� ACDBCB
	string t;
	//��t����ַ�
	for (int i = 0; i < n; i++) {
		if (s.compare(s_) < 0) {//˭С��˭������ĸ
			t += s[0];
			s.erase(s.begin());
		}
		else {
			t += s_[0];
			s_.erase(s_.begin());
		}
	}
	//�������
	for (int i = 0; i < n; i++) {
		cout << t[i];
		if ((i + 1) % 80 == 0) {
			cout << endl;
		}
	}
	return 0;
}