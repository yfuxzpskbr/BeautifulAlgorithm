//ע����״�������ʼ����1������0����������
#include <iostream>
#include <algorithm>
using namespace std;
class Info {//������
public:
	int start;
	int end;
	int need;
	//Ĭ�Ϲ��캯��
	Info() {
		start = 0;
		end = 0;
		need = 0;
	}
	//���캯��
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

//�Ƚ�������������
bool cmp(Info a, Info b) {
	return a.end < b.end;
}

//��ȡlowbit����
int lowbit(int x) {
	return x & (-x);
}

//����״������и��£���ԭ�����iλ���ϼ���k
void update(int n, int i, int k)
{
	while (i <= n) {
		c[i] += k;
		i += lowbit(i);
	}
}

//����״������ͣ���ʾ1-x��ԭ����ĺ�
int getSum(int n, int x) {
	int ans = 0;
	while (x > 0) {
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

//����ѡ��
int pickPoint(int n, Info arr[]) {
	sort(arr, arr + n, cmp);//�����յ�����
	int c_len = arr[n - 1].end; //��״���飬����Ϊ������������ŵ����ݾ�����ѡ��ĺ�'
	for (int i = 0; i < n; i++) {
		//�ڵ�i������ѡ��
		int cnt = getSum(c_len, arr[i].end) - getSum(c_len, arr[i].start - 1);//�����������ѡ����
		arr[i].need -= cnt;//�������-ȥ�Ѵ��ڵ���
		int t = arr[i].end;
		while (arr[i].need > 0) {//ֻ�������������0����������ȡ�㣬ÿ��ȡ����յ㿪ʼ��ǰȡ
			if (axis[t] == 0) {//������λ��û�б�ѡȡ
				axis[t] = 1;//ѡȡ
				arr[i].need--;//��ȥ�����
				update(c_len, t, 1);//���£���tλ�ü���1
				t--;//������ǰ��
			}
			else {//��ѡ��ֱ����ǰѡ
				t--;
			}
		}
	}
	int ans = getSum(c_len, c_len);//����ѡȡ�ĵ����
	//ɾ���ѿռ����飬��ֹ�ڴ�й©
	delete[]axis;
	delete[]c;
	//����ֵ
	return ans;
}