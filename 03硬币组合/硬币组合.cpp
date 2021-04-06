#include <iostream>
using namespace std;
int coins[4] = { 1,5,10,25 };
int CoinComb[4][100];
int CoinCombination(int n, int rear);
int CoinCombination(int n);

int main() {
	for (int i = 1; i <= 25; i++) {
		cout << i << "-->" << CoinCombination(i, 3) << endl;
		cout << i << "-->" << CoinCombination(i) << endl;
		cout << "-------------------" << endl;
	}
	//cout << CoinCombination(10);
	return 0;
}

//�ݹ�
int CoinCombination(int n, int rear)
{
	if (rear == 0)return 1;//���ڣ���ֻ��ѡ�����Ϊ1��Ӳ��ʱֻ��һ��ѡ��������1
	int cnt = 0;//����
	for (int i = 0; i * coins[rear] <= n; i++) {//������úܶ�Σ�0�Ρ�1�Ρ�2�Ρ�....
		cnt += CoinCombination(n - i * coins[rear], rear - 1);//�ۼӼ���
	}
	return cnt;//���ؼ���
}

//��̬�滮
int CoinCombination(int n)
{
	//��ʼ����һ��
	//CoinComb[i][j]=k ��ʾ�����coins[i]����ǰ��������j��ֵ�ķ�������k
	//��ʼ����һ�У���CoinComb[0][j],�������1��ʾ0��99����ֵ�ķ���������1
	for (int i = 0; i < 100; i++) {
		CoinComb[0][i] = 1;
	}
	//��ʼ����һ�У���CoinComb[i][0]���������coins[i]����ǰ�ı�ʾ0��ֵ�ķ���������1
	for (int i = 0; i < 4; i++) {
		CoinComb[i][0] = 1;
	}

	//��̬�滮,��1,1��ʼ
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 100; j++) {
			CoinComb[i][j] = 0;//��ʼֵ��0
			//ÿ����ֵ��ѡ��
			for (int k = 0; k * coins[i] <= n; k++) {
				CoinComb[i][j] += CoinComb[i - 1][j - k * coins[i]];
			}
		}
	}
	return CoinComb[3][n];
}