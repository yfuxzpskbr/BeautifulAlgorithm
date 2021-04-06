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
	char last;//记录上一次出现的字符
	int cnt = 0;//记录上一个字符出现次数
	//扫描压缩
	int len = str.size();
	string ans("");
	for (int i = 0; i < len; i++) {
		if (i == 0) {//处理第一个字符
			ans += str[i];
			cnt++;
		}
		else {//处理后面的字符
			if (str[i] == last) {//与前一个字符相等
				cnt++;
			}
			else {//不相等
				if (cnt > 1) {//出现次数大于1说明重复
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
	//处理最后一个字符
	if (cnt > 1) {
		ans += to_string(cnt);
	}
	return ans;
}