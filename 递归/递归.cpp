#include <iostream>
using namespace std;
int fun(int n);
void print(int i, int j);
int sum(int a[], int begin, int end);
int fib(int n);
string reverse(string str, int end);
int maxNumber(int m, int n);
void insertSort(int a[], int k);
int HanNota(int n, char res, char tool, char dis);
int main() {
	cout << "5的阶乘是：" << fun(5) << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "打印0-10：";
	print(0, 10);
	cout << endl;
	cout << "--------------------------------------------------" << endl;
	int arr[] = { 1,3,8,4,5,2,7,6,9 };
	cout << "数组求和：" << sum(arr, 0, 8) << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "翻转good：" << reverse("good", 3) << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "斐波那契数列第八项是：" << fib(8) << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "24和18的最大公约数：" << maxNumber(18, 24) << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "插入排序：";
	insertSort(arr, 8);
	for (int i = 0; i < 9; i++)cout << arr[i] << " ";
	cout << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "汉诺塔：" << endl;
	int cnt = HanNota(3, 'A', 'B', 'C');
	cout << "共计移动了：" << cnt << "次" << endl;
	cout << "--------------------------------------------------" << endl;
	return 0;
}
//求阶乘
//变化的量是参数，根据变化趋势确定递归出口
int fun(int n) {
	if (n == 1)return 1;
	return n * fun(n - 1);
}

//打印i到j
void print(int i, int j) {
	if (i > j)return;
	cout << i << " ";
	print(i + 1, j);
}

//数组求和
int sum(int a[], int begin, int end) {
	if (begin == end) {
		return a[begin];
	}
	return a[begin] + sum(a, begin + 1, end);
}

//翻转字符串
string reverse(string str, int end) {
	if (end < 0) {
		return "";
	}
	return str.at(end) + reverse(str, end - 1);
}

//斐波那契数列
int fib(int n) {
	if (n == 1 || n == 2)return 1;
	return fib(n - 1) + fib(n - 2);
}

//辗转相除法
int maxNumber(int m, int n) {
	if (m % n == 0)return n;
	return maxNumber(n, m % n);
}

//插入排序
void insertSort(int a[], int k) {
	//从小到大排序
	if (k == 0)return;
	insertSort(a, k - 1);
	int index = k - 1;
	int d = a[k];
	while (index > -1 && d < a[index]) {
		a[index + 1] = a[index];
		index--;
	}
	a[index + 1] = d;
}

//汉诺塔
int HanNota(int n, char res, char tool, char dis) {
	int cnt = 0;
	if (n == 1) {
		cout << n << "号盘从" << res << "通过" << tool << "移动到了" << dis << endl;
		return 1;
	}
	cnt += HanNota(n - 1, res, dis, tool);
	cout << n << "号盘从" << res << "通过" << tool << "移动到了" << dis << endl;
	cnt += 1;
	cnt += HanNota(n - 1, tool, res, dis);
	return cnt;
}