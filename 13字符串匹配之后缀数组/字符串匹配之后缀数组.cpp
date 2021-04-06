#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Suffix {
public:
	string str = "";
	int index = 0;//��ʾ��ʼ��λ��
	int rk = 0;//��ʾ�Ӵ�������������rk����
	static int k;//������¼k
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
	if (a.rk == b.rk) {//������˵��ǰ׺�Ȳ�������������Ƚ�rk[i+k/2]+rk[j+k/2]
		return sa[a.index + a.k / 2].rk < sa[b.index + b.k / 2].rk;
	}
	return a.rk < b.rk;
}

void makeSuffix(string s, Suffix sa[])
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

void makeSuffix2(string s, Suffix sa[])
{
	int len = s.size();
	for (int k = 1; k <= len; k *= 2) {//���� logn
		//����sa����
		Suffix::k = k;
		for (int i = 0; i < len; i++) {
			string s_ = s.substr(i, (i + k - 1 >= len ? len - i : k));//����Խ��
			//������rk��rk����֮ǰ��
			sa[i].str = s_;
			sa[i].index = i;
		}

		//���k=1��ʹ�ÿ�������
		if (k == 1)
			sort(sa, sa + len, cmp);//nlogn����Ϊ��һ��ֻ��һ�����ַ����ڲ��ǳ������Ӷ�
		else {
			sort(sa, sa + len, cmp2);//nlogn����Ϊ������rk����
		}

		//����rk���飬����rk������ȫ�ֱ���
		int rank = 0;
		for (int i = 0; i < len; i++) {
			if (i - 1 < 0 || sa[i - 1].str != sa[i].str) {//����Ȼ���Խ��[��һ��]
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

	//����rk���飬ʹ�䲻�ظ�0~n-1
	//rk[i]=k;��ʾi�ź�׺����Ϊk���±��ʾ��׺��ţ���ֵ��ʾ����
	//sa[i]=k;��ʾ����Ϊi����k�ź�׺�����±��ʾ��������ֵ��ʾ��׺���
	//rk[sa[i].index] = i;
	for (int i = 0; i < len; i++) {
		sa[sa[i].index].rk = i;
	}

	//����height����
	int k = 0;
	for (int i = 0; i < len; i++) {
		int rk = sa[i].rk;//i��׺����
		if (rk == 0) {//�����һ��
			height[0] = 0;
			continue;
		}
		//�ҵ�������ǰһ��
		int rk_1 = rk - 1;
		int j = sa[rk_1].index;//�ҵ����׺���
		if (k > 0)k--;//�ָ���ȥ
		//ǰk-1���������ٱȽ�
		for (; j + k < len && i + k < len; k++) {
			if (s[i + k] != s[j + k]) {
				break;
			}
		}
		//����height����
		height[rk] = k;
	}
}

int suffixMatch(string s, string p)
{
	//�߽����
	int s_len = s.size();
	int p_len = p.size();
	if (s_len == 0)return -1;
	if (p_len == 0)return -1;
	if (s_len < p_len)return -1;

	//���ɺ�׺����
	sa = new Suffix[s_len];
	makeSuffix2(s, sa);

	//��ʼ��
	int left = 0;
	int right = s_len - 1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		//������
		string s_;
		if (sa[mid].str.size() > p_len) {
			s_ = sa[mid].str.substr(0, p_len);
		}
		else {
			s_ = sa[mid].str;
		}
		//���ֲ���
		if (s_ == p)return sa[mid].index;//��ȷ���
		else if (s_ > p) {//pС���������
			right = mid - 1;
		}
		else {//p�������ұ���
			left = mid + 1;
		}
	}
	delete[]sa;
	//û�ҵ�����
	return -1;
}