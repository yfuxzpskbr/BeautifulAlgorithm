#include <iostream>
#include <string>
using namespace std;
bool isDifferent(string str);
bool isDifferent2(string str);
int main() {
	cout << (isDifferent2("a8bcdes1fg3") ? "����ַ���ÿ���ַ�����ͬ" : "����ַ��д�����ͬ�ַ�") << endl;
	return 0;
}

bool isDifferent(string str)
{
	int cnt[128] = { 0 };
	//ɨ�貢����
	for (int i = 0; i < str.size(); i++) {
		//�ַ���Ϊ�±�
		int index = static_cast<int>(str[i]);
		if (cnt[index] >= 1) {//���cnt>=1��˵���Ѿ����ֹ���ֱ�ӷ���false����
			return false;
		}
		cnt[index]++;
	}
	//���û����false����˵��Ӧ�÷���true
	return true;
}

bool isDifferent2(string str)
{
	//��ÿ���ַ�����������ַ�
	for (int i = 0; i < str.size(); i++) {
		for (int j = i + 1; j < str.size(); j++) {
			if (str[i] == str[j])return false;
		}
	}
	return true;
}