#include <iostream>
#include <algorithm>
using namespace std;
int n, t;
//牛类
class Cow {
public:
	int start;
	int end;
	Cow() :start(0), end(0) {}
	Cow(int start, int end) :start(start), end(end) {}
	void setCow(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

bool cmp(Cow a, Cow b);
int main() {
	cin >> n >> t;
	Cow* cows = new Cow[n];
	int index = 0;
	//处理输入
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > t || b < 1) {//不符合要求的不要
			continue;
		}
		cows[index++].setCow(a, b);
	}
	sort(cows, cows + index, cmp);
	int end = cows[0].end;//最长终点
	int i = 0;//循环控制变量
	int cnt = 0;//统计区间数
	int start = 1;//待覆盖起点
	while (end < t) {//循环去覆盖
		if (cows[i].start > t || i >= index) {//起点大于终点或越界
			cout << -1 << endl;
			return 0;
		}
		if (cows[i].start <= start) {//起点比待覆盖区间起点小
			if (cows[i].end > end) {//更新最大值
				end = cows[i].end;
			}
			i++;
		}
		else {
			start = end;
			cnt++;
		}
	}
	cout << cnt + 1 << endl;
	delete[]cows;
	return 0;
}
//比较器，用于排序牛
bool cmp(Cow a, Cow b) {
	return a.start < b.start;
}