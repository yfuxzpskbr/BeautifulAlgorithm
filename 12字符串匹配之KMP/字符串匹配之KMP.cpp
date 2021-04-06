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

//��next����
void Next(string p, int* next)
{
	int p_len = p.size();//��¼�ַ�������
	if (p_len == 0)return;//����Ϊ0��ֱ�ӷ���
	next[0] = -1;//��һ����Զ��-1
	if (p_len == 1)return;//���ֻ��һ����Ҳ����return
	next[1] = 0;//�ڶ�����Զ��0

	int j = 1;//��ʼ���ڶ�����j=1����Ϊnext�ĵ�ǰλ�ǿ���ǰһλ��next
	int k = next[j];
	while (j + 1 < p_len) {//���������ԭ�򣬱߽�����г���
		if (k == -1 || p[j] == p[k]) {//��Ȼ���Խ��
			next[++j] = ++k;//��¼������k
		}
		else {//���������ֱ����Ȼ���Խ��
			k = next[k];
		}
	}
}

//KMP����ʵ��
int KMP(string s, string p)
{
	//��¼����
	int s_len = s.size();
	int p_len = p.size();

	//�߽���
	if (s_len == 0)return -1;
	if (p_len == 0)return -1;
	if (s_len < p_len)return -1;

	//��ʼ��
	int i = 0, j = 0;
	//��next����
	int* next = new int[p_len];
	Next(p, next);
	//����ĸ��
	while (i < s_len) {
		if (j == -1 || s[i] == p[j]) {//ƥ�����ˣ�����Խ��++��ƥ����һ��
			i++;
			j++;
		}
		else {//ûƥ���Ͼͻ���
			j = next[j];
		}
		if (j == p_len) {//ȫƥ���ϣ�˵��ƥ��ɹ�
			return i - j;
		}
	}
	//���ûreturn��˵��ƥ��ʧ��
	return -1;
}