#include <iostream>
#include <algorithm>
using namespace std;
void whoWillWin(int* a, int n);
int main() {
	int a[] = { 1 ,5 ,6 ,7 ,9, 12 ,14 ,17 };
	whoWillWin(a, 8);
	return 0;
}

void whoWillWin(int* a, int n)
{
	//a�д洢��ߵ�λ��
	int ans = 0;
	sort(a, a + n);//�����򣬱�������
	if ((n & 1) == 1) {//������
		for (int i = 0; i < n; i += 2) {
			//ʯ��������ǰһ���ľ��룬������һ�����ǵ�1�ľ���
			ans ^= (i == 0 ? a[i] - 1 : a[i] - a[i - 1] - 1);
		}
	}
	else {//ż����
		for (int i = 1; i < n; i += 2) {
			ans ^= (a[i] - a[i - 1] - 1);
		}
	}
	if (ans == 0) {//��ΪAlice���У�����������0����
		cout << "Bob will win." << endl;
	}
	else {
		cout << "Alice will win" << endl;
	}
}