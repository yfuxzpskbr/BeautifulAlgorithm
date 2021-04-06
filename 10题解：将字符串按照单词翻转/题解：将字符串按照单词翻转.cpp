#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string reverseByWord(string str);
int main() {
	cout << reverseByWord("I love You") << endl;
	return 0;
}

string reverseByWord(string str)
{
	//按字符翻转
	reverse(str.begin(), str.end());

	//按单词翻转
	int left, right, len = str.size();
	for (int i = 0; i < len; i++) {
		if (i == 0 || str[i - 1] == ' ') {//找到起点
			left = i;
			continue;
		}
		if (i == len - 1 || str[i + 1] == ' ') {//找到终点
			right = i;
			reverse(str.begin() + left, str.begin() + right + 1);
		}
	}
	return str;
}