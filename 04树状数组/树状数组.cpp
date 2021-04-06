//树状数组中下标从1开始比较好计算

#include <iostream>
using namespace std;
int lowbit(int x);
void update(int C[], int n, int i, int k);
int getSum(int C[], int n, int i);
int main() {
	int A[11] = { 0, 1,2,3,4,5,6,7,8,9,10 };//原数组
	int C[11] = { 0 };//树状数组
	for (int i = 1; i <= 10; i++) {
		update(C, 10, i, A[i]);//初始化树状数组
	}
	//例如求个2到7的和，预计是27
	//2-7的和也就是1-7的和减去1-1的和
	cout << getSum(C, 10, 4) << endl;
	cout << "2+3+...+7 = " << getSum(C, 10, 7) - getSum(C, 10, 1) << endl;
	return 0;
}

//获取lowbit
int lowbit(int x)
{
	return x & (-x);
}

//树状数组C中i位置的值加上k
void update(int C[], int n, int i, int k)
{
	while (i <= n) {
		C[i] += k;
		i += lowbit(i);
	}
}

//取得C数组第i位置的值，也就是原数组1到i的和
int getSum(int C[], int n, int i)
{
	int ans = 0;
	while (i > 0) {
		ans += C[i];
		i -= lowbit(i);
	}
	return ans;
}