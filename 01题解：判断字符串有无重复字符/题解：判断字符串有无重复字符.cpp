#include <iostream>
#include <string>
using namespace std;
bool isDifferent(string str);
bool isDifferent2(string str);
int main() {
	cout << (isDifferent2("a8bcdes1fg3") ? "这个字符串每个字符都不同" : "这个字符中存在相同字符") << endl;
	return 0;
}

bool isDifferent(string str)
{
	int cnt[128] = { 0 };
	//扫描并计数
	for (int i = 0; i < str.size(); i++) {
		//字符作为下标
		int index = static_cast<int>(str[i]);
		if (cnt[index] >= 1) {//如果cnt>=1，说明已经出现过，直接返回false即可
			return false;
		}
		cnt[index]++;
	}
	//如果没返回false，就说明应该返回true
	return true;
}

bool isDifferent2(string str)
{
	//找每个字符后面的所有字符
	for (int i = 0; i < str.size(); i++) {
		for (int j = i + 1; j < str.size(); j++) {
			if (str[i] == str[j])return false;
		}
	}
	return true;
}