#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Suffix {//后缀类的设计
public:
	string str = "";//后缀内容
	int index = 0;//后缀序号
	int rk = 0;//后缀排名
	static int k;//倍增标记
};
int Suffix::k = 0;
Suffix* sa;//sa数组的小标是排名sa[i].index是后缀序号
bool cmp(Suffix a, Suffix b);
void getSuffixArray(string s, Suffix* sa);
void getHeightArray(string s, int height[]);
int maxSubstr(string s);
int main() {
	cout << maxSubstr("abcd0bcdsjd") << endl;
	return 0;
}

bool cmp(Suffix a, Suffix b) {
	return a.str < b.str;
}

//倍增法求后缀数组
void getSuffixArray(string s, Suffix* sa)
{
	int n = s.size();
	//生成未排序的所有后缀
	int len = s.size();
	for (int i = 0; i < len; i++) {
		string s_ = s.substr(i, len - i);
		sa[i].str = s_;
		sa[i].index = i;
	}

	//排序即后缀数组
	sort(sa, sa + n, cmp);
}

void getHeightArray(string s, int height[])
{
	int len = s.size();
	//更新rk，使其不重复
	//rk[sa[i]] = i;
	for (int i = 0; i < len; i++) {
		sa[sa[i].index].rk = i;
	}

	//更新height数组
	int k = 0;
	for (int i = 0; i < len; i++) {
		//找到i的排名
		int rk = sa[i].rk;
		if (rk == 0) {//处理第一个
			height[0] = 0;
			continue;
		}
		//找到上一个排名
		int rk_1 = rk - 1;
		int j = sa[rk_1].index;
		if (k > 0)k--;//恢复k
		for (; i + k < len && j + k < len; k++) {
			if (s[i + k] != s[j + k]) {
				break;
			}
		}
		//更新height数组
		height[rk] = k;
	}
}

int maxSubstr(string s)
{
	int len = s.size();

	sa = new Suffix[len];
	int* height = new int[len];
	//生成sa数组
	getSuffixArray(s, sa);
	//生成height数组
	getHeightArray(s, height);

	//找到height中的最大值
	int max = 0;
	int index = 0;
	for (int i = 0; i < len; i++) {
		if (height[i] > max) {
			index = sa[i].index;
			max = height[i];
		}
	}

	//输出最长的子串
	cout << s.substr(index, max) << endl;
	delete[]sa;
	delete[]height;
	return max;
}

int maxSubstr2(string s)
{
	int len = s.size();

	sa = new Suffix[len];
	int* height = new int[len];
	//生成sa数组
	getSuffixArray(s, sa);
	//生成height数组
	getHeightArray(s, height);

	//找到height中的最大值
	int max = 0;
	int index = 0;
	int index_ = 0;
	for (int i = 0; i < len; i++) {
		if (height[i] > max) {
			index = sa[i].index;
			index = sa[i - 1].index;
			max = height[i];
		}
	}

	//输出最长的子串
	cout << s.substr(index, max) << endl;
	delete[]sa;
	delete[]height;
	return max;
}