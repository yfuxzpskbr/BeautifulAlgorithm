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

//�����ֵm������Ҫ����Ӳ��
int needCoins(int m, int cur)
{
	if (m == 0)return 0;//û������˾Ͳ���Ҫѡ�񣬷���0
	int select = m / coins[cur];//ÿ�ξ����ܶ��ѡ������[̰�Ĳ���]
	select = select < cnt[cur] ? select : cnt[cur];//��֤��ѡ��ֵ��������
	int gn = 0;//��¼Ӳ��
	//ѡ��Ӳ���ۼ�
	gn += select;
	gn += needCoins(m - select * coins[cur], cur - 1);
	//����
	return gn;
}