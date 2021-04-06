#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;//记录答案
int cnt;//记排名，不用回溯
void dfs(int n, int l, int k);
bool check(char ch);
int main() {
	int n, l;
	cin >> n >> l;
	while (n != 0 || l != 0) {
		str = "";
		cnt = 0;
		dfs(n, l, 0);
		cin >> n >> l;
	}

	return 0;
}

//深搜寻找困难串，n是排名，l是允许使用字母个数，k是当前的str长度
void dfs(int n, int l, int k) {
	if (n == cnt) {//递归出口
		//按条件输出
		int len = str.size();
		for (int i = 0; i < len; i++) {
			cout << str[i];
			if (i != len - 1) {
				if ((i + 1) % 64 == 0) {
					cout << endl;
					continue;
				}
				if ((i + 1) % 4 == 0) {
					cout << " ";
					continue;
				}
			}
		}
		cout << endl;
		cout << k << endl;
		//返回
		return;
	}

	//多个方向选择字母
	for (int i = 0; i < l; i++) {
		char ch = static_cast<char>(i + 'A');
		if (check(ch)) {//检查
			str += ch;//检查成功就加到答案中
			cnt++;//排名+1
			dfs(n, l, k + 1);//搜索下一个字母
			str.erase(str.end() - 1);//回溯，擦除最后一个字母
			if (cnt == n)//找到就可以break了
				break;
		}
	}
}

//检测新插入的字符是否符合要求
bool check(char ch) {
	int front = str.size() - 1;
	str += ch;
	int rear = front + 1;
	//一一比较
	for (int i = front, j = rear; i >= 0; i -= 2, j -= 1) {
		int f = i;
		int r = j;
		bool isone = true;
		while (f <= front && r <= rear) {
			if (str[f] != str[r]) {
				isone = false;
			}
			f++;
			r++;
		}
		if (isone) {
			str.erase(str.end() - 1);
			return false;
		}
	}
	str.erase(str.end() - 1);
	return true;
}