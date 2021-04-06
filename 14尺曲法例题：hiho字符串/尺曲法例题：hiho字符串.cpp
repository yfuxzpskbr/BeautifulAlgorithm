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

//�ж��ַ�ch�Ƿ���i o h�е�ĳһ��
inline bool check(char ch)
{
	if (ch == 'h' || ch == 'i' || ch == 'o')
		return true;
	return false;
}

//�ж��ַ�����i��j�Ƿ�������hiho
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

//�ж��Ƿ�ǡ��
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

//����Сhiho��
int minHiho(string s)
{
	int min = 100000;
	int len = s.size();
	//��iȥɨ
	int j = -1;
	for (int i = 0; i < len; i++) {
		if (check(s[i])) {//i�ҵ��˵�һ��
			if (j == -1) {//��һ��i�ҵ�
				j = i + 1;
			}
			//������jɨ��
			while (j < len) {
				if (check(s[j]) && contance(s, i, j)) {//i��j����������hһ��iһ��o
					if (contance_(s, i, j) && j - i + 1 < min) {//������������min
						min = j - i + 1;
					}
					break;
				}
				j++;//����j����ɨ��
			}
		}
	}
	return (min == 100000 ? -1 : min);
}