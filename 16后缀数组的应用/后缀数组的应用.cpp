#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Suffix {//��׺������
public:
	string str = "";//��׺����
	int index = 0;//��׺���
	int rk = 0;//��׺����
	static int k;//�������
};
int Suffix::k = 0;
Suffix* sa;//sa�����С��������sa[i].index�Ǻ�׺���
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

//���������׺����
void getSuffixArray(string s, Suffix* sa)
{
	int n = s.size();
	//����δ��������к�׺
	int len = s.size();
	for (int i = 0; i < len; i++) {
		string s_ = s.substr(i, len - i);
		sa[i].str = s_;
		sa[i].index = i;
	}

	//���򼴺�׺����
	sort(sa, sa + n, cmp);
}

void getHeightArray(string s, int height[])
{
	int len = s.size();
	//����rk��ʹ�䲻�ظ�
	//rk[sa[i]] = i;
	for (int i = 0; i < len; i++) {
		sa[sa[i].index].rk = i;
	}

	//����height����
	int k = 0;
	for (int i = 0; i < len; i++) {
		//�ҵ�i������
		int rk = sa[i].rk;
		if (rk == 0) {//�����һ��
			height[0] = 0;
			continue;
		}
		//�ҵ���һ������
		int rk_1 = rk - 1;
		int j = sa[rk_1].index;
		if (k > 0)k--;//�ָ�k
		for (; i + k < len && j + k < len; k++) {
			if (s[i + k] != s[j + k]) {
				break;
			}
		}
		//����height����
		height[rk] = k;
	}
}

int maxSubstr(string s)
{
	int len = s.size();

	sa = new Suffix[len];
	int* height = new int[len];
	//����sa����
	getSuffixArray(s, sa);
	//����height����
	getHeightArray(s, height);

	//�ҵ�height�е����ֵ
	int max = 0;
	int index = 0;
	for (int i = 0; i < len; i++) {
		if (height[i] > max) {
			index = sa[i].index;
			max = height[i];
		}
	}

	//�������Ӵ�
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
	//����sa����
	getSuffixArray(s, sa);
	//����height����
	getHeightArray(s, height);

	//�ҵ�height�е����ֵ
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

	//�������Ӵ�
	cout << s.substr(index, max) << endl;
	delete[]sa;
	delete[]height;
	return max;
}