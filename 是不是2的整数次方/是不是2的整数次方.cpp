#include <iostream>
using namespace std;
int main() {
	int a = 31;
	//�ж�һ�������������Ƿ�ֻ����1һ��1
	//ԭ��һ�������������һ���������������������������λ��1
	if ((a & (a - 1)) == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}