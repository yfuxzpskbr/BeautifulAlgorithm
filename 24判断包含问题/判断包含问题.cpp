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
	for (int i = 0; i < b.size(); i++) {//size()�ǻ�ȡstring���ȵķ���
		char ch = b.at(i);//at��[]���
		if (a.find(ch) == string::npos) {//find��npos����ϵͳ������ֵ
			return false;
		}
	}
	return true;
}