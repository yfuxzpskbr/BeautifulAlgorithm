#include <iostream>
#include <string>
using namespace std;
string cutk0(string str, int k);
int main() {
	cout << cutk0("a0b00c000d0000e00000f000000g", 3) << endl;
	return 0;
}

string cutk0(string str, int k)
{
	int cnt = 0;	//用于计数
	int len = str.size();
	string ans("");
	for (int i = 0; i < len; i++) {
		if (str[i] == '0') {//是0计数加一
			cnt++;
		}
		else {
			//处理0
			ans.append(cnt % k, '0');	//%k是避免0的个数大于k
			ans += str[i];	//不是0先加上这个不是0的字符
			//计数清零
			cnt = 0;
		}
	}
	return ans;
}