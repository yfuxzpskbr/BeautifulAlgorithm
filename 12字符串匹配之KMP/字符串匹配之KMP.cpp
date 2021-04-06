#include <iostream>
using namespace std;
void Next(string p, int* next);
int KMP(string s, string p);
int main() {
	string s("ncdocndbababbdiji");
	string p("baab");
	cout << KMP(s, p) << endl;
	return 0;
}

//求next数组
void Next(string p, int* next)
{
	int p_len = p.size();//记录字符串长度
	if (p_len == 0)return;//长度为0，直接返回
	next[0] = -1;//第一个永远是-1
	if (p_len == 1)return;//如果只有一个，也可以return
	next[1] = 0;//第二个永远是0

	int j = 1;//初始化第二个用j=1，因为next的当前位是看的前一位的next
	int k = next[j];
	while (j + 1 < p_len) {//由于上面的原因，边界这边有出入
		if (k == -1 || p[j] == p[k]) {//相等或者越界
			next[++j] = ++k;//记录并更新k
		}
		else {//否则迭代，直到相等或者越界
			k = next[k];
		}
	}
}

//KMP代码实现
int KMP(string s, string p)
{
	//记录长度
	int s_len = s.size();
	int p_len = p.size();

	//边界检测
	if (s_len == 0)return -1;
	if (p_len == 0)return -1;
	if (s_len < p_len)return -1;

	//初始化
	int i = 0, j = 0;
	//求next数组
	int* next = new int[p_len];
	Next(p, next);
	//遍历母串
	while (i < s_len) {
		if (j == -1 || s[i] == p[j]) {//匹配上了，或者越界++以匹配下一个
			i++;
			j++;
		}
		else {//没匹配上就回溯
			j = next[j];
		}
		if (j == p_len) {//全匹配上，说明匹配成功
			return i - j;
		}
	}
	//最后都没return就说明匹配失败
	return -1;
}