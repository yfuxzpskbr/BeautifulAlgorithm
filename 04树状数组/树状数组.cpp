//��״�������±��1��ʼ�ȽϺü���

#include <iostream>
using namespace std;
int lowbit(int x);
void update(int C[], int n, int i, int k);
int getSum(int C[], int n, int i);
int main() {
	int A[11] = { 0, 1,2,3,4,5,6,7,8,9,10 };//ԭ����
	int C[11] = { 0 };//��״����
	for (int i = 1; i <= 10; i++) {
		update(C, 10, i, A[i]);//��ʼ����״����
	}
	//�������2��7�ĺͣ�Ԥ����27
	//2-7�ĺ�Ҳ����1-7�ĺͼ�ȥ1-1�ĺ�
	cout << getSum(C, 10, 4) << endl;
	cout << "2+3+...+7 = " << getSum(C, 10, 7) - getSum(C, 10, 1) << endl;
	return 0;
}

//��ȡlowbit
int lowbit(int x)
{
	return x & (-x);
}

//��״����C��iλ�õ�ֵ����k
void update(int C[], int n, int i, int k)
{
	while (i <= n) {
		C[i] += k;
		i += lowbit(i);
	}
}

//ȡ��C�����iλ�õ�ֵ��Ҳ����ԭ����1��i�ĺ�
int getSum(int C[], int n, int i)
{
	int ans = 0;
	while (i > 0) {
		ans += C[i];
		i -= lowbit(i);
	}
	return ans;
}