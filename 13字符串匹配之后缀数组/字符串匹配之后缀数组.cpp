#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Suffix {
public:
	string str = "";
	int index = 0;//表示开始的位置
	int rk = 0;//表示子串的排名，代替rk数组
	static int k;//用来记录k
	Suffix() {}
	Suffix(string str_, int index_) {
		str = str_;
		index = index_;
	}
};
int Suffix::k;
Suffix* sa;
bool cmp(Suffix a, Suffix b);
bool cmp2(Suffix a, Suffix b);
void makeSuffix(string s, Suffix sa[]);
void makeSuffix2(string s, Suffix sa[]);
void makeHeight(string s, Suffix sa[], int* height);
int suffixMatch(string s, string p);

int main() {
	cout << suffixMatch("232323", "567") << endl;
	return 0;
}

bool cmp(Suffix a, Suffix b)
{
	return a.str < b.str;
}

bool cmp2(Suffix a, Suffix b)
{
	if (a.rk == b.rk) {//如果相等说明前缀比不出结果，继续比较rk[i+k/2]+rk[j+k/2]
		return sa[a.index + a.k / 2].rk < sa[b.index + b.k / 2].rk;
	}
	return a.rk < b.rk;
}

void makeSuffix(string s, Suffix sa[])
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

void makeSuffix2(string s, Suffix sa[])
{
	int len = s.size();
	for (int k = 1; k <= len; k *= 2) {//倍增 logn
		//更新sa数组
		Suffix::k = k;
		for (int i = 0; i < len; i++) {
			string s_ = s.substr(i, (i + k - 1 >= len ? len - i : k));//处理越界
			//不更新rk，rk还是之前的
			sa[i].str = s_;
			sa[i].index = i;
		}

		//如果k=1就使用快速排序
		if (k == 1)
			sort(sa, sa + len, cmp);//nlogn，因为第一次只有一个，字符串内部是常数复杂度
		else {
			sort(sa, sa + len, cmp2);//nlogn，因为运用了rk数组
		}

		//更新rk数组，这里rk数组是全局变量
		int rank = 0;
		for (int i = 0; i < len; i++) {
			if (i - 1 < 0 || sa[i - 1].str != sa[i].str) {//不相等或者越界[第一个]
				sa[i].rk = rank++;
			}
			else {
				sa[i].rk = sa[i - 1].rk;
			}
		}
	}
}

void makeHeight(string s, Suffix sa[], int* height)
{
	int len = s.size();

	//更新rk数组，使其不重复0~n-1
	//rk[i]=k;表示i号后缀排名为k，下标表示后缀序号，其值表示排名
	//sa[i]=k;表示排名为i的是k号后缀，其下标表示排名，其值表示后缀序号
	//rk[sa[i].index] = i;
	for (int i = 0; i < len; i++) {
		sa[sa[i].index].rk = i;
	}

	//生成height数组
	int k = 0;
	for (int i = 0; i < len; i++) {
		int rk = sa[i].rk;//i后缀排名
		if (rk == 0) {//处理第一个
			height[0] = 0;
			continue;
		}
		//找到排名的前一个
		int rk_1 = rk - 1;
		int j = sa[rk_1].index;//找到其后缀序号
		if (k > 0)k--;//恢复回去
		//前k-1个都不用再比较
		for (; j + k < len && i + k < len; k++) {
			if (s[i + k] != s[j + k]) {
				break;
			}
		}
		//更新height数组
		height[rk] = k;
	}
}

int suffixMatch(string s, string p)
{
	//边界控制
	int s_len = s.size();
	int p_len = p.size();
	if (s_len == 0)return -1;
	if (p_len == 0)return -1;
	if (s_len < p_len)return -1;

	//生成后缀数组
	sa = new Suffix[s_len];
	makeSuffix2(s, sa);

	//初始化
	int left = 0;
	int right = s_len - 1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		//处理长度
		string s_;
		if (sa[mid].str.size() > p_len) {
			s_ = sa[mid].str.substr(0, p_len);
		}
		else {
			s_ = sa[mid].str;
		}
		//二分查找
		if (s_ == p)return sa[mid].index;//相等返回
		else if (s_ > p) {//p小了在左边找
			right = mid - 1;
		}
		else {//p大了在右边找
			left = mid + 1;
		}
	}
	delete[]sa;
	//没找到返回
	return -1;
}