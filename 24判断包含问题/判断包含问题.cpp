#include <iostream>
#include <string>
using namespace std;
bool check(string a, string b);
int main() {
	string a("abchwhnfuoef");
	string b("hwnfuoa");
	cout << (check(a, b) ? "YES" : "NO") << endl;
	return 0;
}

bool check(string a, string b) {
	for (int i = 0; i < b.size(); i++) {//size()是获取string长度的方法
		char ch = b.at(i);//at和[]差不多
		if (a.find(ch) == string::npos) {//find和npos都是系统方法和值
			return false;
		}
	}
	return true;
}