#include <iostream>
#include <string>
using namespace std;
string replaceSpace(string str);
int main() {
	cout << "Hello World" << endl;
	cout << replaceSpace("Hello World") << endl;
	return 0;
}

string replaceSpace(string str)
{
	int length = str.size();
	int len = length;
	//ͳ�ƿո�
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ')length += 2;
	}
	//�����ַ�������
	str.resize(length);
	//��ʼ������ָ��
	int first = len - 1;
	int second = length - 1;
	//ɨ�账��
	while (first >= 0) {
		if (str[first] != ' ') {//�����ڿո�ֱ�ӿ���ԭ����
			str[second--] = str[first--];
		}
		else {//���ڿո����ο���02%
			str[second--] = '0';
			str[second--] = '2';
			str[second--] = '%';
			first--;
		}
	}
	return str;
}