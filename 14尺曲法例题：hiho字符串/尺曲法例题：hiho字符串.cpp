#include <iostream>
#include <string>
using namespace std;
inline bool check(char ch);
inline bool contance(string s, int i, int j);
inline bool contance_(string s, int i, int j);
int minHiho(string s);
int main() {
	string s;
	cin >> s;
	cout << minHiho(s) << endl;
	return 0;
}

//判断字符ch是否是i o h中的某一个
inline bool check(char ch)
{
	if (ch == 'h' || ch == 'i' || ch == 'o')
		return true;
	return false;
}

//判断字符串从i到j是否囊括了hiho
inline bool contance(string s, int i, int j)
{
	int cnt_i = 0, cnt_h = 0, cnt_o = 0;
	for (int k = i; k <= j; k++) {
		if (s[k] == 'i')cnt_i++;
		if (s[k] == 'h')cnt_h++;
		if (s[k] == 'o')cnt_o++;
	}
	if (cnt_i >= 1 && cnt_h >= 2 && cnt_o >= 1)
		return true;
	return false;
}

//判断是否恰好
inline bool contance_(string s, int i, int j)
{
	int cnt_i = 0, cnt_h = 0, cnt_o = 0;
	for (int k = i; k <= j; k++) {
		if (s[k] == 'i')cnt_i++;
		if (s[k] == 'h')cnt_h++;
		if (s[k] == 'o')cnt_o++;
	}
	if (cnt_i == 1 && cnt_h == 2 && cnt_o == 1)
		return true;
	return false;
}

//求最小hiho串
int minHiho(string s)
{
	int min = 100000;
	int len = s.size();
	//先i去扫
	int j = -1;
	for (int i = 0; i < len; i++) {
		if (check(s[i])) {//i找到了第一个
			if (j == -1) {//第一次i找到
				j = i + 1;
			}
			//接下来j扫描
			while (j < len) {
				if (check(s[j]) && contance(s, i, j)) {//i到j包括了两个h一个i一个o
					if (contance_(s, i, j) && j - i + 1 < min) {//满足条件更新min
						min = j - i + 1;
					}
					break;
				}
				j++;//否则j继续扫描
			}
		}
	}
	return (min == 100000 ? -1 : min);
}