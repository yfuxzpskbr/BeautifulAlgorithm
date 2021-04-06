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

//ѡ����
int pickMuch(Info time[], int n)
{
	int picked = 0;//��ѡ����
	int timecur = 0;//��ǰʱ����
	for (int i = 0; i < n; i++) {//����ÿ������
		if (timecur <= time[i].start) {//��ǰʱ����С�ڹ�����ʼʱ��Ϳ���ѡ
			timecur = time[i].end;//ʱ�����Ƶ���������
			picked++;//ѡ++
		}
	}
	return picked;
}

//�Զ�������ȽϺ���
bool cmp(Info time1, Info time2) {
	return time1.end < time2.end;
}