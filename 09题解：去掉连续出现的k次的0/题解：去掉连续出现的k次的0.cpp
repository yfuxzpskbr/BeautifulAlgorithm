#include <iostream>
#include <string>
using namespace std;
string cutk0(string str, int k);
int main() {
	cout << cutk0("a0b00c000d0000e00000f000000g", 3) << endl;
	return 0;
}

string cutk0(string str, int k)
{
	int cnt = 0;	//���ڼ���
	int len = str.size();
	string ans("");
	for (int i = 0; i < len; i++) {
		if (str[i] == '0') {//��0������һ
			cnt++;
		}
		else {
			//����0
			ans.append(cnt % k, '0');	//%k�Ǳ���0�ĸ�������k
			ans += str[i];	//����0�ȼ����������0���ַ�
			//��������
			cnt = 0;
		}
	}
	return ans;
}