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
		hash = hash * 31 + (int)(str[i]);//���Ƽ���
	}
	return hash;
}

void match(string s, string p)
{
	int s_len = s.size();
	int p_len = p.size();
	int start = 0;//ĸ��ƥ�����
	bool is = false;	//��ʾ�Ƿ��Ѿ�ƥ����
	while (start + p_len <= s_len) {//��ֹԽ��
		bool iscontinue = false;
		//����ƥ��
		for (int i = 0; i < p_len; i++) {
			if (s[start + i] != p[i]) {//�����ƥ�䣬�ʹ�ĸ����һ��ƥ��
				start++;
				iscontinue = true;
				break;
			}
		}
		//ûƥ�䵽����һ��ƥ��
		if (iscontinue)continue;

		//ƥ�����˾����
		cout << "match:" << start << endl;
		is = true;
		//�����ƥ����һ��
		start++;
	}
	//ûƥ����Ҳ���
	if (!is) {
		cout << "match:" << -1 << endl;
	}
}

void PabinKarp(string s, string p)
{
	long long p_hash = Hash(p);//ģʽ����hashֵ
	int s_len = s.size();
	int p_len = p.size();
	bool ismatch = false;
	for (int i = 0; i + p_len <= s_len; i++) {
		//��ȡ�Ӵ��Ĳ�����һ������ʼλ�ã��ڶ�������ȡ���ٸ�
		string sub = s.substr(i, p_len);//������Ⱥ�ģʽ����ͬ���Ӵ�
		long long s_hash = Hash(sub);//����ĸ�����Ӵ���hashֵ
		if (s_hash == p_hash) {//��Ⱦ�˵���ҵ���
			ismatch = true;
			cout << "match:" << i << endl;//��ӡ
		}
	}
	//���û�ҵ�Ҳ��ӡ
	if (!ismatch)
		cout << "match:" << -1 << endl;
}

void PabinKarp2(string s, string p)
{
	int p_hash = Hash(p);//ģʽ����hashֵ
	int s_len = s.size();
	int p_len = p.size();
	bool ismatch = false;
	int div = pow(31, p_len - 1);	//���Ƶ���ô��η�
	long long s_hash;//hashֵ
	for (int i = 0; i + p_len <= s_len; i++) {
		if (i == 0) {//�����һ��Ԫ�ص�hashֵ
			s_hash = Hash(s.substr(0, p_len));
		}
		else {//����ǵ�һ��Ԫ�ص�hashֵ
			//�µ�hashֵ����ԭ��hashֵ��ǰһ���ַ�*���Ƶ���ô��η����Խ��Ƽ��µ�ֵ
			s_hash = (s_hash - (int)s[i - 1] * div) * 31 + (int)s[i + p_len - 1];
		}
		if (s_hash == p_hash) {//���ƥ����
			ismatch = true;
			cout << "match:" << i << endl;//��ӡ
		}
	}
	if (ismatch == false) {
		cout << "match:" << -1 << endl;
	}
}