#include <iostream>
using namespace std;
int main() {
	int n, c;
	//��������
	cin >> n >> c;
	int* w = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	int cnt = 0;//װ�ĸ���
	int package = 0;//�����Ѿ�װ�˵�
	int i = 0;//������Ŀ�ʼװ
	while (true) {
		package += w[i];//װ
		if (package <= c) {//������
			cnt++;//����+1
			i++;//׼��װ��һ��
		}
		else {//װ���¾�break
			break;
		}
	}
	//���
	cout << cnt << endl;
	delete[]w;
	return 0;
}