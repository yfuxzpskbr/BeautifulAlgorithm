#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string reverseStr(string str);
string reverseStr2(string str);
int main() {
	cout << "Hello World翻转后：#" << reverseStr("Hello World") << endl;
	cout << "-------------------------------" << endl;
	cout << "Hello World翻转后：#" << reverseStr2("Hello World") << endl;
	cout << "-------------------------------" << endl;
	string str("Hello World");
	reverse(str.begin(), str.end());
	cout << "Hello World翻转后：#" << str << endl;
	return 0;
}

string reverseStr(string str)
{
	int len = str.size();//获取字符串长度
	char* copy = new char[len + 1];
	//扫描赋值
	for (int i = 0; i < len; i++) {
		copy[i] = str[len - 1 - i];//对应关系
	}
	//添加结束符
	copy[len] = '\0';
	//返回即可
	return string(copy);
}

string reverseStr2(string str)
{
	//初始化两端起点
	int left = 0;
	int right = str.size() - 1;
	while (left < right) {//小于就交换
		char ch = str[left];
		str[left] = str[right];
		str[right] = ch;
		//缩小范围
		left++;
		right--;
	}
	return str;
}