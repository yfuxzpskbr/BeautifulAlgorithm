#include <iostream>
using namespace std;
int needCoins(int m, int cur);
int cnt[6] = { 5,5,5,5,5,5 };
int coins[6] = { 1,5,10,50,100,500 };
int main() {
	for (int i = 0; i < 6; i++)
		cin >> cnt[i];
	int m;
	cin >> m;
	cout << needCoins(m, 5) << endl;
	return 0;
}

//组成面值m最少需要多少硬币
int needCoins(int m, int cur)
{
	if (m == 0)return 0;//没有面额了就不需要选择，返回0
	int select = m / coins[cur];//每次尽可能多的选最大面额[贪心策略]
	select = select < cnt[cur] ? select : cnt[cur];//保证所选面值数量够用
	int gn = 0;//记录硬币
	//选择硬币累加
	gn += select;
	gn += needCoins(m - select * coins[cur], cur - 1);
	//返回
	return gn;
}