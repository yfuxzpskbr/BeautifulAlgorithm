#include <iostream>
#include <string>
#include <map>

using namespace std;
bool isInclude(string str, string res);
int main() {
	cout << (isInclude("abcdefabcdefdcbadfe1", "acbdecbdfacbdfebcafd") ? "����ͬ�ַ���" : "������ͬ�ַ���") << endl;
	return 0;
}

bool isInclude(string str, string res)
{
	map<char, int> m;

	//�����һ���ַ���
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (m.find(str[i]) == m.end()) {//�����ھ���ӣ����ھͲ��ù�
			m.insert(pair<char, int>(str[i], 1));
		}
	}

	//����ڶ����ַ���
	len = res.size();
	for (int i = 0; i < len; i++) {
		map<char, int>::iterator it = m.find(res[i]);
		if (it == m.end()) {//û�ҵ���˵����1�в����ڴ�2���ַ�
			return false;
		}
		else {
			if (it->second == 1) {//�ҵ��ˣ�������1���Ǿ���0
				it->second = 0;
			}
		}
	}
	//�ٴ�ɨ�踨����map����ֹ��2�в����ڴ�1���ַ�
	map<char, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second == 1)//�������δ������
			return false;
	}
	return true;
}