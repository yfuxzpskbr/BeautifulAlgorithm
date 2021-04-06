#include <iostream>
#include <algorithm>
using namespace std;
class Info {
public:
	int start = 0;
	int end = 0;
	Info() {
		start = 0;
		end = 0;
	}
	Info(int start, int end) :start{ start }, end{ end }{
	}
};
bool cmp(Info time1, Info time2);
int pickMuch(Info time[], int n);
int main() {
	Info time[5] = { {1,3},{3,5},{1,2},{6,9},{8,10} };
	cout << pickMuch(time, 5) << endl;
	return 0;
}

//选工作
int pickMuch(Info time[], int n)
{
	int picked = 0;//已选个数
	int timecur = 0;//当前时间线
	for (int i = 0; i < n; i++) {//遍历每个工作
		if (timecur <= time[i].start) {//当前时间线小于工作开始时间就可以选
			timecur = time[i].end;//时间线移到工作结束
			picked++;//选++
		}
	}
	return picked;
}

//自定义排序比较函数
bool cmp(Info time1, Info time2) {
	return time1.end < time2.end;
}