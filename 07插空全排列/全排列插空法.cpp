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

//��շ���ȫ����
set<string> A(string s)
{
	int len = s.size();
	if (len <= 0)return set<string>();
	set<string> last, now;
	string t;
	t += s[0];
	last.insert(t);
	for (int i = 1; i < len; i++) {//ÿ���ַ���ȥ��
		set<string>::iterator it;
		for (it = last.begin(); it != last.end(); it++) {
			t = *it;//ȡ�ϴε�һ������
			int t_len = t.size();
			//��
			for (int j = 0; j <= t_len; j++) {
				t.insert(t.begin() + j, s[i]);
				now.insert(t);
				t = *it;
			}
		}
		last = now;//������һ������
		if (i != len - 1)now.clear();//��շ����һ�ε�now
	}
	return now;
}