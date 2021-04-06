#include <iostream>
#include <string>
#include <map>

using namespace std;
bool isInclude(string str, string res);
int main() {
	cout << (isInclude("abcdefabcdefdcbadfe1", "acbdecbdfacbdfebcafd") ? "是相同字符集" : "不是相同字符集") << endl;
	return 0;
}

bool isInclude(string str, string res)
{
	map<char, int> m;

	//处理第一个字符串
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (m.find(str[i]) == m.end()) {//不存在就添加，存在就不用管
			m.insert(pair<char, int>(str[i], 1));
		}
	}

	//处理第二个字符串
	len = res.size();
	for (int i = 0; i < len; i++) {
		map<char, int>::iterator it = m.find(res[i]);
		if (it == m.end()) {//没找到，说明串1中不存在串2的字符
			return false;
		}
		else {
			if (it->second == 1) {//找到了，并且是1，那就置0
				it->second = 0;
			}
		}
	}
	//再次扫描辅助的map，防止串2中不存在串1的字符
	map<char, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second == 1)//如果存在未消除的
			return false;
	}
	return true;
}