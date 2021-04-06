#include <iostream>
using namespace std;
int ans[20];//��¼��
int vis[20];//�������
int n;//��������
bool isprime(int n);
void dfs(int t);
int main() {
	int cnt = 1;
	//�����һ����
	vis[1] = 1;//vis[i]��ʾi�Ƿ��Ѿ�ѡ�ˣ�0��ʾû�У�1��ʾѡ���ˣ��±��1��ʼ
	ans[0] = 1;//ans���ڼ�¼�𰸣��±��0��ʼ
	while (cin >> n) {//��������
		//��ʼ���������
		for (int i = 0; i <= n; i++) {
			vis[i] = 0;
		}

		cout << "Case " << cnt << ":" << endl;
		dfs(1);
		cnt++;
		cout << endl;
	}
	return 0;
}

//dfs����
void dfs(int t) {
	if (t == n) {//�ݹ����
		if (isprime(ans[0] + ans[n - 1])) {//��λ���������
			bool first = true;//����ո�
			for (int i = 0; i < n; i++) {
				if (first)
					first = false;
				else
					cout << " ";
				cout << ans[i];
			}
			cout << endl;
		}
		return;
	}
	//����ѡ��ÿһ����
	for (int i = 2; i <= n; i++) {
		if (vis[i] == 0 && isprime(i + ans[t - 1])) {
			//��¼
			vis[i] = 1;
			ans[t] = i;
			//����
			dfs(t + 1);
			//����
			vis[i] = 0;
		}
	}
}

//�ж�n�ǲ�������
bool isprime(int n) {
	if (n <= 1)return false;
	int t = 2;
	while (t * t <= n) {
		if (n % t == 0)
			return false;
		t++;
	}
	return true;
}