#include <iostream>
#include <string>
using namespace std;
string zip(string str);
int main() {
	cout << zip("ucbduuuuuuuuuuuuert") << endl;
	return 0;
}

string zip(string str)
{
	char last;//��¼��һ�γ��ֵ��ַ�
	int cnt = 0;//��¼��һ���ַ����ִ���
	//ɨ��ѹ��
	int len = str.size();
	string ans("");
	for (int i = 0; i < len; i++) {
		if (i == 0) {//�����һ���ַ�
			ans += str[i];
			cnt++;
		}
		else {//���������ַ�
			if (str[i] == last) {//��ǰһ���ַ����
				cnt++;
			}
			else {//�����
				if (cnt > 1) {//���ִ�������1˵���ظ�
					ans += to_string(cnt);
					ans += str[i];
					cnt = 1;
				}
				else {
					ans += str[i];
					cnt = 1;
				}
			}
		}
		last = str[i];
	}
	//�������һ���ַ�
	if (cnt > 1) {
		ans += to_string(cnt);
	}
	return ans;
}