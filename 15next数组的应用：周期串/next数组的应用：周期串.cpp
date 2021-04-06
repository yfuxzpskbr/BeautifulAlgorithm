#include <iostream>
#include <string>
using namespace std;
void createNext(string s, int* next);
void cycleStr(string str);
int main() {
	string str;
	cin >> str;
	cycleStr(str);
	return 0;
}

void createNext(string s, int* next)
{
	//初始化及边界检测
	int len = s.size() + 1;
	if (len == 1)return;
	next[0] = -1;
	if (len == 2)return;
	next[1] = 0;

	//初始化j，用j计算j+1
	int j = 1;
	int k = next[j];
	while (j + 1 < len) {//因此最后是j+1<len
		if (k == -1 || s[j] == s[k]) {
			next[++j] = ++k;
		}
		else {
			k = next[k];
		}
	}
}

void cycleStr(string str)
{
	int len = str.size();
	//创建next数组
	int* next = new int[len + 1];
	createNext(str, next);

	int j = len;
	int k = next[j];
	if (j - k < len && j % (j - k) == 0) {
		cout << "周期是:" << j - k << endl;
		cout << "出现次数:" << j / (j - k) << endl;
	}
	else {
		cout << str << "不是周期串" << endl;
	}
}