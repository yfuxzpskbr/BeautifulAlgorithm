#include <iostream>
#include <string>
using namespace std;
bool isRotate(string a, string b);
int main() {
	string a("abcdef");
	string b("efabcd");
	cout << b << (isRotate(a, b) ? "��" : "����") << a << "����ת��" << endl;
	return 0;
}

//�ж�b�ǲ���a����ת��
bool isRotate(string a, string b)
{
	//���ȳ��Ȳ�ֱͬ�ӷ���false
	if (a.size() != b.size())return false;
	//a�����Լ���ĩβ
	//����abcd���abcdabcd�������е���ת�ʶ���a����
	a += a;
	if (a.find(b) != string::npos) {//�ҵ���
		return true;
	}
	//�Ҳ���return false
	return false;
}