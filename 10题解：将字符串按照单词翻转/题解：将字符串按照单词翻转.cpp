#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string reverseByWord(string str);
int main() {
	cout << reverseByWord("I love You") << endl;
	return 0;
}

string reverseByWord(string str)
{
	//���ַ���ת
	reverse(str.begin(), str.end());

	//�����ʷ�ת
	int left, right, len = str.size();
	for (int i = 0; i < len; i++) {
		if (i == 0 || str[i - 1] == ' ') {//�ҵ����
			left = i;
			continue;
		}
		if (i == len - 1 || str[i + 1] == ' ') {//�ҵ��յ�
			right = i;
			reverse(str.begin() + left, str.begin() + right + 1);
		}
	}
	return str;
}