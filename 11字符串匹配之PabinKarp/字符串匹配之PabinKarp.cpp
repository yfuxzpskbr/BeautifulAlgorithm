#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long long Hash(string str);
void match(string s, string p);
void PabinKarp(string s, string p);
void PabinKarp2(string s, string p);
int main() {
	PabinKarp2("ABCABCABCABC", "CAB");
	return 0;
}

long long Hash(string str)
{
	int hash = 0;
	for (int i = 0; i < str.size(); i++) {
		hash = hash * 31 + (int)(str[i]);//进制计算
	}
	return hash;
}

void match(string s, string p)
{
	int s_len = s.size();
	int p_len = p.size();
	int start = 0;//母串匹配起点
	bool is = false;	//表示是否已经匹配上
	while (start + p_len <= s_len) {//防止越界
		bool iscontinue = false;
		//进行匹配
		for (int i = 0; i < p_len; i++) {
			if (s[start + i] != p[i]) {//如果不匹配，就从母串下一个匹配
				start++;
				iscontinue = true;
				break;
			}
		}
		//没匹配到就下一个匹配
		if (iscontinue)continue;

		//匹配上了就输出
		cout << "match:" << start << endl;
		is = true;
		//输出后匹配下一个
		start++;
	}
	//没匹配上也输出
	if (!is) {
		cout << "match:" << -1 << endl;
	}
}

void PabinKarp(string s, string p)
{
	long long p_hash = Hash(p);//模式串的hash值
	int s_len = s.size();
	int p_len = p.size();
	bool ismatch = false;
	for (int i = 0; i + p_len <= s_len; i++) {
		//提取子串的参数第一个是起始位置，第二个是提取多少个
		string sub = s.substr(i, p_len);//抽出长度和模式串相同的子串
		long long s_hash = Hash(sub);//计算母串的子串的hash值
		if (s_hash == p_hash) {//相等就说明找到了
			ismatch = true;
			cout << "match:" << i << endl;//打印
		}
	}
	//如果没找到也打印
	if (!ismatch)
		cout << "match:" << -1 << endl;
}

void PabinKarp2(string s, string p)
{
	int p_hash = Hash(p);//模式串的hash值
	int s_len = s.size();
	int p_len = p.size();
	bool ismatch = false;
	int div = pow(31, p_len - 1);	//进制的那么多次方
	long long s_hash;//hash值
	for (int i = 0; i + p_len <= s_len; i++) {
		if (i == 0) {//计算第一个元素的hash值
			s_hash = Hash(s.substr(0, p_len));
		}
		else {//计算非第一个元素的hash值
			//新的hash值等于原的hash值减前一个字符*进制的那么多次方乘以进制加新的值
			s_hash = (s_hash - (int)s[i - 1] * div) * 31 + (int)s[i + p_len - 1];
		}
		if (s_hash == p_hash) {//如果匹配了
			ismatch = true;
			cout << "match:" << i << endl;//打印
		}
	}
	if (ismatch == false) {
		cout << "match:" << -1 << endl;
	}
}