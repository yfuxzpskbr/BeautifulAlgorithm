#include <iostream>
#include <algorithm>
using namespace std;
bool isHuiWen(string str);
bool isHuiWen2(string str);
void print4HuiWen();
int main() {
	print4HuiWen();
	return 0;
}

//��ת�ȽϷ�
bool isHuiWen(string str)
{
	string str_ = str;
	reverse(str_.begin(), str_.end());
	if (str == str_)return true;
	return false;
}

//��β�ȽϷ�
bool isHuiWen2(string str)
{
	int left = 0;
	int len = str.size();
	int right = len - 1;
	while (left < right) {
		if (str[left] != str[right])return false;//��β����Ⱦ�˵�����ǻ��Ĵ�
		left++;
		right--;
	}
	return true;
}

//��ӡ������λ���Ļ�����
void print4HuiWen()
{
	for (int i = 1; i < 10; i++) {//��λ��Ϊ0
		for (int j = 0; j < 10; j++) {
			cout << (i * 1000 + j * 100 + j * 10 + i) << endl;
		}
	}
}