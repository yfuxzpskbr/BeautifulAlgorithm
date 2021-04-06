#include <iostream>
#include <string>
using namespace std;
string replaceSpace(string str);
int main() {
	cout << "Hello World" << endl;
	cout << replaceSpace("Hello World") << endl;
	return 0;
}

string replaceSpace(string str)
{
	int length = str.size();
	int len = length;
	//统计空格
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ')length += 2;
	}
	//更新字符串长度
	str.resize(length);
	//初始化两个指针
	int first = len - 1;
	int second = length - 1;
	//扫描处理
	while (first >= 0) {
		if (str[first] != ' ') {//不等于空格直接拷贝原内容
			str[second--] = str[first--];
		}
		else {//等于空格依次拷贝02%
			str[second--] = '0';
			str[second--] = '2';
			str[second--] = '%';
			first--;
		}
	}
	return str;
}