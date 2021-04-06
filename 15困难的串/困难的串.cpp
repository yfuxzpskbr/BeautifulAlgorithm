#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;//��¼��
int cnt;//�����������û���
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

//����Ѱ�����Ѵ���n��������l������ʹ����ĸ������k�ǵ�ǰ��str����
void dfs(int n, int l, int k) {
	if (n == cnt) {//�ݹ����
		//���������
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
		//����
		return;
	}

	//�������ѡ����ĸ
	for (int i = 0; i < l; i++) {
		char ch = static_cast<char>(i + 'A');
		if (check(ch)) {//���
			str += ch;//���ɹ��ͼӵ�����
			cnt++;//����+1
			dfs(n, l, k + 1);//������һ����ĸ
			str.erase(str.end() - 1);//���ݣ��������һ����ĸ
			if (cnt == n)//�ҵ��Ϳ���break��
				break;
		}
	}
}

//����²�����ַ��Ƿ����Ҫ��
bool check(char ch) {
	int front = str.size() - 1;
	str += ch;
	int rear = front + 1;
	//һһ�Ƚ�
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