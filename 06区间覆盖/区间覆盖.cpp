#include <iostream>
#include <algorithm>
using namespace std;
int n, t;
//ţ��
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
	//��������
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > t || b < 1) {//������Ҫ��Ĳ�Ҫ
			continue;
		}
		cows[index++].setCow(a, b);
	}
	sort(cows, cows + index, cmp);
	int end = cows[0].end;//��յ�
	int i = 0;//ѭ�����Ʊ���
	int cnt = 0;//ͳ��������
	int start = 1;//���������
	while (end < t) {//ѭ��ȥ����
		if (cows[i].start > t || i >= index) {//�������յ��Խ��
			cout << -1 << endl;
			return 0;
		}
		if (cows[i].start <= start) {//���ȴ������������С
			if (cows[i].end > end) {//�������ֵ
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
//�Ƚ�������������ţ
bool cmp(Cow a, Cow b) {
	return a.start < b.start;
}