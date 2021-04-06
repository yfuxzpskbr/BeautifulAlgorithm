#include <iostream>
using namespace std;
void merge(int a[], int b[], int lena, int lenb);
int main() {
	int a[10] = { 1,2,3 };
	int b[5] = { 4,5,7,9,13 };
	merge(a, b, 3, 5);
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

//��ƨ�ɿ�ʼ�ϲ�
void merge(int a[], int b[], int lena, int lenb) {
	//��ʼָ��ƨ��
	int pa = lena - 1;
	int pb = lenb - 1;
	int current = lena + lenb - 1;

	//��a��b��ûɨ����ʱ
	while (pa >= 0 && pb >= 0) {
		//���a��ƨ�ɴ󣬾ͼ���current��������--
		if (a[pa] >= b[pb]) {
			a[current] = a[pa];
			pa--;
			current--;
		}
		//����b��ƨ�ɼ���current��--
		else {
			a[current] = b[pb];
			pb--;
			current--;
		}
	}
	//bû����Ļ�����
	while (pb >= 0) {
		a[current] = b[pb];
		pb--;
		current--;
	}

	//aû����Ĳ��ò���
}