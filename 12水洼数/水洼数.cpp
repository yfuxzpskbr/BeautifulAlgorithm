#include <iostream>
#include <string>
using namespace std;
void dfs(string map[], int r, int c, int i, int j);
int main() {
	int n, m;
	//��������
	cin >> n >> m;
	string* map = new string[n];
	for (int i = 0; i < n; i++) {
		map[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//�㷨����
	int cnt = 0;//���ڼ���
	//����������ˮ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'W') {//ֻ����ˮ�ſ�ʼ��
				dfs(map, n, m, i, j);
				cnt++;//ÿ���������+1
			}
		}
	}
	//���
	cout << cnt << endl;
	delete[]map;
	return 0;
}

//��ˮ���㷨
void dfs(string map[], int r, int c, int i, int j) {
	map[i][j] = '.';//ÿ�������ı�Ϊ����

	//��ˮ�ݰ˸�������
	for (int i_ = -1; i_ <= 1; i_++) {
		for (int j_ = -1; j_ <= 1; j_++) {
			if (i_ == 0 && j_ == 0)continue;//����Ҫ
			if (i + i_ >= 0 && i + i_ < r && j + j_ >= 0 && j + j_ < c) {//�߽���
				if (map[i + i_][j + j_] == 'W') {//��ˮ�ݾ�dfs��
					dfs(map, r, c, i + i_, j + j_);
				}
			}
		}
	}
}