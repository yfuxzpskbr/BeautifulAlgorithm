#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isRound(string res, string str);
bool isRound2(string res, string str);
int main() {
	cout << (isRound("1234", "3512") ? "是变形词" : "不是变形词") << endl;
	cout << "-----------------------------" << endl;
	cout << (isRound2("1234", "3412") ? "是变形词" : "不是变形词") << endl;

	return 0;
}

bool isRound(string res, string str)
{
	if (res.size() != str.size())return false;
	//排序
	sort(res.begin(), res.end());
	sort(str.begin(), str.end());

	//比较
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (res[i] != str[i])return false;
	}
	return true;
}

bool isRound2(string res, string str)
{
	if (res.size() != str.size())return false;
	int cnt[128] = { 0 };//一定要初始化为0
	int len = str.size();
	//对第一个单词加计数
	for (int i = 0; i < len; i++) {
		int index = static_cast<int>(res[i]);
		cnt[index]++;//计数
	}
	//对第二个单词减计数
	for (int i = 0; i < len; i++) {
		int index = static_cast<int>(str[i]);
		if (cnt[index] <= 0)return false;
		cnt[index]--;
	}
	//扫描临时数组
	for (int i = 0; i < 128; i++) {
		if (cnt[i] != 0)return false;
	}
	return true;
}