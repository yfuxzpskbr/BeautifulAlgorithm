#include <iostream>
using namespace std;
int main() {
	int a = 0b1001;
	//һ��������1010101010...�Ὣ0����λ���Σ�����ż��λ
	//һ��������0101010101...�Ὣ0����λ���Σ���������λ
	//�ٽ�����������λ���Ʊ�����ż��λ���ƣ�������������������
	int b = ((a & 0xaaaaaaaa) >> 1);
	int c = ((a & 0x55555555) << 1);
	int ans = (b ^ c);
	cout << ans << endl;
	return 0;
}