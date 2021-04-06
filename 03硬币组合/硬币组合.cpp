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

//递归
int CoinCombination(int n, int rear)
{
	if (rear == 0)return 1;//出口，当只能选择面额为1的硬币时只有一种选法，返回1
	int cnt = 0;//计数
	for (int i = 0; i * coins[rear] <= n; i++) {//高面额拿很多次，0次、1次、2次、....
		cnt += CoinCombination(n - i * coins[rear], rear - 1);//累加计数
	}
	return cnt;//返回计数
}

//动态规划
int CoinCombination(int n)
{
	//初始化第一行
	//CoinComb[i][j]=k 表示用面额coins[i]即以前的面额组成j面值的方法数是k
	//初始化第一行，即CoinComb[0][j],即由面额1表示0到99的面值的方法数都是1
	for (int i = 0; i < 100; i++) {
		CoinComb[0][i] = 1;
	}
	//初始化第一列，即CoinComb[i][0]，即用面额coins[i]及以前的表示0面值的方法数都是1
	for (int i = 0; i < 4; i++) {
		CoinComb[i][0] = 1;
	}

	//动态规划,从1,1开始
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 100; j++) {
			CoinComb[i][j] = 0;//初始值是0
			//每种面值的选择
			for (int k = 0; k * coins[i] <= n; k++) {
				CoinComb[i][j] += CoinComb[i - 1][j - k * coins[i]];
			}
		}
	}
	return CoinComb[3][n];
}