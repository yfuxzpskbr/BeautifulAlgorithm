#include <iostream>
#include <string>
using namespace std;
bool isRotate(string a, string b);
int main() {
	string a("abcdef");
	string b("efabcd");
	cout << b << (isRotate(a, b) ? "是" : "不是") << a << "的旋转词" << endl;
	return 0;
}

//判断b是不是a的旋转词
bool isRotate(string a, string b)
{
	//首先长度不同直接返回false
	if (a.size() != b.size())return false;
	//a复制自己到末尾
	//例如abcd变成abcdabcd后其所有的旋转词都在a中了
	a += a;
	if (a.find(b) != string::npos) {//找到了
		return true;
	}
	//找不到return false
	return false;
}