#include <iostream>
using namespace std;
int costTime(int needTime[], int people);
int main() {
	int test, n;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> n;
		int* needTime = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> needTime[i];
		}
		cout << costTime(needTime, n) << endl;
		delete[]needTime;
	}
	return 0;
}

//计算花费的最少时间
int costTime(int needTime[], int people)
{
	int time = 0;
	while (people) {
		if (people == 1) {//最后剩一个人
			time += needTime[0];
			break;
		}
		if (people == 2) {//最后剩两个人
			time += needTime[1];
			break;
		}
		if (people == 3) {
			time += needTime[0] + needTime[1] + needTime[2];
			break;
		}
		//方案一：每次用最快的两个带最慢的两个过河
		int s1 = needTime[1] + needTime[0] + needTime[people - 1] + needTime[1];
		//方案二每次用最快的带最慢的过河
		int s2 = needTime[people - 1] + needTime[0] + needTime[people - 2] + needTime[0];
		time += (s1 < s2 ? s1 : s2);
		people -= 2;
	}
	return time;
}