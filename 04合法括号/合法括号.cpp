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

//�ݹ���ʽ
set<string> recersion(int n) {
	set<string> ans;
	if (n == 1) {//�ݹ�߽�
		ans.insert("()");
		return ans;
	}
	set<string> n_1 = recersion(n - 1);
	//��n-1������
	set<string>::iterator it;
	for (it = n_1.begin(); it != n_1.end(); it++) {
		ans.insert("()" + (*it));//���
		ans.insert((*it) + "()");//�ұ�
		ans.insert("(" + (*it) + ")");//���
	}
	return ans;
}

//������ʽ
set<string> withoutrecersion(int n) {
	set<string> n_1;//n-1������
	n_1.insert("()");
	if (n == 1) {//ֻ��һ��ֱ�ӷ���
		return n_1;
	}
	set<string>::iterator it;
	set<string> n_;
	for (int i = 2; i <= n; i++) {//�ӵڶ������ŵ���n��
		//��n-1�����Ž������ҡ�������
		for (it = n_1.begin(); it != n_1.end(); it++) {
			n_.insert("()" + (*it));
			n_.insert((*it) + "()");
			n_.insert("(" + (*it) + ")");
		}
		//����
		n_1 = n_;
		//ע�ⲻ�����һ��Ҫ���
		if (i < n)n_.clear();
	}
	return n_;
}