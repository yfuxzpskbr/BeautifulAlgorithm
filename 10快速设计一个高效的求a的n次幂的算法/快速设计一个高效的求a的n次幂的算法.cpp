#include <iostream>
using namespace std;
unsigned long long fastPow1(int base, int pow);
unsigned long long fastPow2(unsigned long long base, int pow);
int main() {
	cout << "2^63 = " << fastPow1(2, 63) << endl;
	cout << "2^63 = " << fastPow2(2, 63) << endl;
	return 0;
}

//�ݹ�ʵ�ֿ�����
unsigned long long fastPow1(int base, int pow) {
	if (pow == 0)return 1;
	unsigned long long ans = base;	//��ʱ�Ѿ�������һ�η�
	int ex = 1;//�������ڼ����˵�ָ����ÿ��ָ����һ��
	while ((ex << 1) <= pow) {//������ָ����û�ﵽҪ��
		ans *= ans;	//����
		ex <<= 1;	//��¼��ǰ�Ѿ������ָ��
	}
	//���ص�ǰ�Ѿ������˵�ָ������δ�����ָ����
	return ans * fastPow1(base, pow - ex);
}

//����λ���������п�����
unsigned long long fastPow2(unsigned long long base, int pow) {
	/*
	* �������2^20
	* ����λ�����ǲ����Ĳ��룬�����Ĳ�����Ǳ���
	* ���൱�ڼ���2^0b10100
	* �͵���2^0b10000 * 2^0b00100(2^16 * 2^4)
	* ��ans=1			base = base^2(��δʹ�ã��´�ѭ��ʹ��)   pow=0b1010;
	* ��ans=1			base = base^4(��δʹ�ã��´�ѭ��ʹ��)   pow=0b101;
	* ��ans=base^4		base = base^8(��δʹ�ã��´�ѭ��ʹ��)	pow=0b10;
	* ��ans=base^4		base = base^16(��δʹ�ã��´�ѭ��ʹ��)	pow=0b1;
	* ��ans=base^20		base = base^32(��δʹ�ã��´�ѭ��ʹ��)	pow=0;	����
	*/
	unsigned long long ans = 1;
	while (pow > 0) {//֪��pow����0�Ž���
		if (pow & 1)//�൱��pow�Ķ����Ƶ����һλ��1��Ҳ�൱��pow������
		{
			ans *= base;	//���Ե���
		}
		base *= base;	//��������
		pow >>= 1;	//ÿ������һλ
	}
	return ans;
}