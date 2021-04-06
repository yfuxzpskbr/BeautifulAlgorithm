#include <iostream>
#include <set>
using namespace std;
set<string> withoutrecersion(int n);
set<string> recersion(int n);
int main() {
	set<string> v;
	v = withoutrecersion(8);
	set<string>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << (*it) << endl;
	}
	return 0;
}

//递归形式
set<string> recersion(int n) {
	set<string> ans;
	if (n == 1) {//递归边界
		ans.insert("()");
		return ans;
	}
	set<string> n_1 = recersion(n - 1);
	//对n-1添括号
	set<string>::iterator it;
	for (it = n_1.begin(); it != n_1.end(); it++) {
		ans.insert("()" + (*it));//左边
		ans.insert((*it) + "()");//右边
		ans.insert("(" + (*it) + ")");//外边
	}
	return ans;
}

//迭代形式
set<string> withoutrecersion(int n) {
	set<string> n_1;//n-1对括号
	n_1.insert("()");
	if (n == 1) {//只有一对直接返回
		return n_1;
	}
	set<string>::iterator it;
	set<string> n_;
	for (int i = 2; i <= n; i++) {//从第二对括号到第n对
		//对n-1对括号进行左、右、外的添加
		for (it = n_1.begin(); it != n_1.end(); it++) {
			n_.insert("()" + (*it));
			n_.insert((*it) + "()");
			n_.insert("(" + (*it) + ")");
		}
		//迭代
		n_1 = n_;
		//注意不是最后一次要清空
		if (i < n)n_.clear();
	}
	return n_;
}