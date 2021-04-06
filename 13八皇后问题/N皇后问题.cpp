#include <iostream>
using namespace std;
int n;//�ʺ����
int recorder[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };//��¼�ʺ�λ�ã��±�Ϊ�У���������
int ans;//��
void dfs(int row);
bool check(int i, int j);
int main() {
	int res[10];

	//ͳ��ʮ�����ݣ����
	n = 1;
	while (n <= 10) {
		ans = 0;
		dfs(0);
		res[n - 1] = ans;
		n++;
	}

	//���������
	cin >> n;
	while (n) {
		cout << res[n - 1] << endl;
		cin >> n;
	}
	return 0;
}

//dfs���ʺ�����
void dfs(int row) {
	if (row == n) {//����
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {//ÿ�а˸�����������̽
		if (check(row, i)) {//���԰ڷŻʺ�
			recorder[row] = i;//��¼
			dfs(row + 1);//�ݹ�
			recorder[row] = -1;//����
		}
	}
}

//���i_��j_λ���Ƿ���԰ڷŻʺ�
bool check(int i_, int j_) {
	for (int i = 0; i < 10; i++) {
		if (recorder[i] == -1) //Խ���break
			break;
		if (recorder[i] == j_)//��һ����
			return false;
		if (i + recorder[i] == i_ + j_)//�ڶԽ�����
			return false;
		if (i - recorder[i] == i_ - j_)//�ڶԽ�����
			return false;
	}
	return true;
}