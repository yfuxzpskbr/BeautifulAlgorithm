#include <iostream>
#include <set>
using namespace std;
set<set<int>> recersionPick(int* arr, int n, int cur);
set<set<int>> withoutRecersionPick(int* arr, int n);
int main() {
	set<set<int>> v = withoutRecersionPick(new int[3]{ 1,2,3 }, 3);
	for (auto x : v) {
		cout << "{";
		bool first = true;
		for (auto y : x) {
			if (first)first = !first;
			else cout << ",";
			cout << y;
		}
		cout << "}" << endl;
	}
	return 0;
}

//�ݹ���ʽ
set<set<int>> recersionPick(int* arr, int n, int cur)
{
	if (cur == 0) {//�����һ��,�ݹ����
		set<set<int>> v;
		set<int>vb;
		//��ѡ
		v.insert(vb);

		//ѡ
		vb.insert(arr[0]);
		v.insert(vb);
		return v;
	}
	set<set<int>> last = recersionPick(arr, n, cur - 1);
	set<set<int>> now;
	set<set<int>>::iterator it;
	for (it = last.begin(); it != last.end(); it++) {
		//��ǰԪ�ز�ѡ
		now.insert(*it);

		//��ǰԪ��ѡ
		set<int>temp;
		temp = *it;
		temp.insert(arr[cur]);
		now.insert(temp);
	}
	return now;
}

//������ʽ
set<set<int>> withoutRecersionPick(int* arr, int n)
{
	set<set<int>> now;
	set<set<int>> last;
	set<int> t;

	last.insert(t);	//�ʼ�ǿռ�

	//����ѡ��
	for (int i = 0; i < n; i++) {
		set<set<int>>::iterator it;
		for (it = last.begin(); it != last.end(); it++) {
			//��ѡ
			now.insert(*it);
			//ѡ
			t = *it;
			t.insert(arr[i]);
			now.insert(t);
			t.clear();	//�����ʱ��t
		}
		//����
		last = now;
		if (i != n - 1) {
			now.clear();	//������µĽ�����´μ�¼
		}
	}
	return now;
}