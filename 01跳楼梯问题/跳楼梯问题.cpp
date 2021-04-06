#include <iostream>
using namespace std;
#define MOD 1000000007

int step1(int n);
int step2(int n);
int main() {
	int n;
	cin >> n;
	cout << step2(n) << endl;
	return 0;
}

//递归跳楼梯
int step1(int n)
{
	if (n == 1)return 1;
	if (n == 2)return 2;
	if (n == 3)return 4;
	return (step1(n - 1) % MOD + step1(n - 2) % MOD + step1(n - 3) % MOD) % MOD;
}

//迭代跳楼梯
int step2(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	int fn_1 = 4;
	int fn_2 = 2;
	int fn_3 = 1;
	int fn = 0;
	for (int i = 4; i <= n; i++) {
		//这一行防止越界，可以这样写
		/*fn = (fn_1 % MOD + fn_2 % MOD + fn_3 % MOD) % MOD;*/
		fn = ((fn_1 % MOD + fn_2 % MOD) % MOD + fn_3 % MOD) % MOD;
		fn_3 = fn_2;
		fn_2 = fn_1;
		fn_1 = fn;
	}
	return fn;
}