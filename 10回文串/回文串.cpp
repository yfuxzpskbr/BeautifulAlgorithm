#include <iostream>
#include <algorithm>
using namespace std;
bool isHuiWen(string str);
bool isHuiWen2(string str);
void print4HuiWen();
int main() {
	print4HuiWen();
	return 0;
}

//翻转比较法
bool isHuiWen(string str)
{
	string str_ = str;
	reverse(str_.begin(), str_.end());
	if (str == str_)return true;
	return false;
}

//首尾比较法
bool isHuiWen2(string str)
{
	int left = 0;
	int len = str.size();
	int right = len - 1;
	while (left < right) {
		if (str[left] != str[right])return false;//首尾不相等就说明不是回文串
		left++;
		right--;
	}
	return true;
}

//打印所有四位数的回文数
void print4HuiWen()
{
	for (int i = 1; i < 10; i++) {//首位不为0
		for (int j = 0; j < 10; j++) {
			cout << (i * 1000 + j * 100 + j * 10 + i) << endl;
		}
	}
}