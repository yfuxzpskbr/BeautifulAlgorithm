//注意树状数组的起始点是1，不是0，！！！！
#include <iostream>
#include <algorithm>
using namespace std;
class Info {//区间类
public:
	int start;
	int end;
	int need;
	//默认构造函数
	Info() {
		start = 0;
		end = 0;
		need = 0;
	}
	//构造函数
	Info(int start, int end, int need) {
		this->start = start;
		this->end = end;
		this->need = need;
	}
	//setter
	void setInfo(int start, int end, int need) {
		this->start = start;
		this->end = end;
		this->need = need;
	}
};

bool cmp(Info a, Info b);
int lowbit(int x);
void update(int n, int i, int k);
int getSum(int n, int x);
int pickPoint(int n, Info arr[]);
int axis[50001] = { 0 };
int c[50001] = { 0 };
int main() {
	int n;
	cin >> n;
	Info* arr = new Info[n];
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i].setInfo(a, b, c);
	}
	cout << pickPoint(n, arr) << endl;
	delete[]arr;
	return 0;
}

//比较器，用于排序
bool cmp(Info a, Info b) {
	return a.end < b.end;
}

//获取lowbit函数
int lowbit(int x) {
	return x & (-x);
}

//对树状数组进行更新，在原数组第i位置上加上k
void update(int n, int i, int k)
{
	while (i <= n) {
		c[i] += k;
		i += lowbit(i);
	}
}

//用树状数组求和，表示1-x的原数组的和
int getSum(int n, int x) {
	int ans = 0;
	while (x > 0) {
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

//区间选点
int pickPoint(int n, Info arr[]) {
	sort(arr, arr + n, cmp);//根据终点排序
	int c_len = arr[n - 1].end; //树状数组，长度为区间最长，里面存放的内容就是已选点的和'
	for (int i = 0; i < n; i++) {
		//在第i个区间选点
		int cnt = getSum(c_len, arr[i].end) - getSum(c_len, arr[i].start - 1);//求的区间上已选点数
		arr[i].need -= cnt;//所需点数-去已存在点数
		int t = arr[i].end;
		while (arr[i].need > 0) {//只有所需点数大于0才在区间上取点，每次取点从终点开始往前取
			if (axis[t] == 0) {//如果这个位置没有被选取
				axis[t] = 1;//选取
				arr[i].need--;//减去还需点
				update(c_len, t, 1);//更新，在t位置加上1
				t--;//区间往前走
			}
			else {//已选过直接往前选
				t--;
			}
		}
	}
	int ans = getSum(c_len, c_len);//计算选取的点个数
	//删除堆空间数组，防止内存泄漏
	delete[]axis;
	delete[]c;
	//返回值
	return ans;
}