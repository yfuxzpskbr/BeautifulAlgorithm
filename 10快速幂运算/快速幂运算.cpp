#include <iostream>
using namespace std;
using ulong = unsigned long long;
ulong myPow(ulong base, ulong pow);
int main() {
	cout << myPow(2, 1) << endl;
	return 0;
}

ulong myPow(ulong base, ulong pow)
{
	int result = 1;//���ս��
	while (pow != 0) {//ָ����Ϊ0
		if (pow & 1) {//����λ�Ƿ�Ϊ1
			result *= base;//Ϊ1�ͳ��ϸ�λ�ĵ���
		}
		base *= base;//��������
		pow >>= 1;//ָ��һλ
	}
	return result;
}