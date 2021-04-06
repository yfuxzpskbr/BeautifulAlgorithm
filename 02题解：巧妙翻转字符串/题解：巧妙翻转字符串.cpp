#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string reverseStr(string str);
string reverseStr2(string str);
int main() {
	cout << "Hello World��ת��#" << reverseStr("Hello World") << endl;
	cout << "-------------------------------" << endl;
	cout << "Hello World��ת��#" << reverseStr2("Hello World") << endl;
	cout << "-------------------------------" << endl;
	string str("Hello World");
	reverse(str.begin(), str.end());
	cout << "Hello World��ת��#" << str << endl;
	return 0;
}

string reverseStr(string str)
{
	int len = str.size();//��ȡ�ַ�������
	char* copy = new char[len + 1];
	//ɨ�踳ֵ
	for (int i = 0; i < len; i++) {
		copy[i] = str[len - 1 - i];//��Ӧ��ϵ
	}
	//��ӽ�����
	copy[len] = '\0';
	//���ؼ���
	return string(copy);
}

string reverseStr2(string str)
{
	//��ʼ���������
	int left = 0;
	int right = str.size() - 1;
	while (left < right) {//С�ھͽ���
		char ch = str[left];
		str[left] = str[right];
		str[right] = ch;
		//��С��Χ
		left++;
		right--;
	}
	return str;
}