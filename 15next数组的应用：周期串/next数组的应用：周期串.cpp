#include <iostream>
#include <string>
using namespace std;
void createNext(string s, int* next);
void cycleStr(string str);
int main() {
	string str;
	cin >> str;
	cycleStr(str);
	return 0;
}

void createNext(string s, int* next)
{
	//��ʼ�����߽���
	int len = s.size() + 1;
	if (len == 1)return;
	next[0] = -1;
	if (len == 2)return;
	next[1] = 0;

	//��ʼ��j����j����j+1
	int j = 1;
	int k = next[j];
	while (j + 1 < len) {//��������j+1<len
		if (k == -1 || s[j] == s[k]) {
			next[++j] = ++k;
		}
		else {
			k = next[k];
		}
	}
}

void cycleStr(string str)
{
	int len = str.size();
	//����next����
	int* next = new int[len + 1];
	createNext(str, next);

	int j = len;
	int k = next[j];
	if (j - k < len && j % (j - k) == 0) {
		cout << "������:" << j - k << endl;
		cout << "���ִ���:" << j / (j - k) << endl;
	}
	else {
		cout << str << "�������ڴ�" << endl;
	}
}