#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isRound(string res, string str);
bool isRound2(string res, string str);
int main() {
	cout << (isRound("1234", "3512") ? "�Ǳ��δ�" : "���Ǳ��δ�") << endl;
	cout << "-----------------------------" << endl;
	cout << (isRound2("1234", "3412") ? "�Ǳ��δ�" : "���Ǳ��δ�") << endl;

	return 0;
}

bool isRound(string res, string str)
{
	if (res.size() != str.size())return false;
	//����
	sort(res.begin(), res.end());
	sort(str.begin(), str.end());

	//�Ƚ�
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (res[i] != str[i])return false;
	}
	return true;
}

bool isRound2(string res, string str)
{
	if (res.size() != str.size())return false;
	int cnt[128] = { 0 };//һ��Ҫ��ʼ��Ϊ0
	int len = str.size();
	//�Ե�һ�����ʼӼ���
	for (int i = 0; i < len; i++) {
		int index = static_cast<int>(res[i]);
		cnt[index]++;//����
	}
	//�Եڶ������ʼ�����
	for (int i = 0; i < len; i++) {
		int index = static_cast<int>(str[i]);
		if (cnt[index] <= 0)return false;
		cnt[index]--;
	}
	//ɨ����ʱ����
	for (int i = 0; i < 128; i++) {
		if (cnt[i] != 0)return false;
	}
	return true;
}