#include <iostream>
using namespace std;
int max1Arr(int(*arr)[5]);
int main() {
	int arr[5][5] = {
		{0,1,1,1,1},
		{0,1,0,1,1},
		{0,1,1,1,1},
		{0,0,1,1,1},
		{0,0,0,0,0}
	};
	cout << "�߽�Ϊ1������Ӿ���Ϊ: " << max1Arr(arr) << "��" << endl;
	return 0;
}

int max1Arr(int(*arr)[5])
{
	int ans = 5;
	//��������������߽׿�ʼ
	while (ans) {
		//����ÿһ������
		for (int i = 0; i < 5; i++) {
			if (i + ans > 5)break;//���㲻��ans�ף�break
			for (int j = 0; j < 5; j++) {
				if (j + ans > 5)break;//���㲻��ans�ף�break
				//���嶥��
				int pi = i;
				int pj = j;
				bool end = false;
				//��֤������
				while (pj < j + ans) {//��
					if (arr[pi][pj] == 0) {
						end = true;
						break;
					}
					pj++;
				}
				if (end)continue;
				pj--;
				while (pi < i + ans) {//��
					if (arr[pi][pj] == 0) {
						end = true;
						break;
					}
					pi++;
				}
				if (end)continue;
				pi--;
				while (pj >= j) {//��
					if (arr[pi][pj] == 0) {
						end = true;
						break;
					}
					pj--;
				}
				if (end)continue;
				pj++;
				while (pi >= i) {//��
					if (arr[pi][pj] == 0) {
						end = true;
						break;
					}
					pi--;
				}
				if (end)continue;
				return ans;
			}
		}
		ans--;
	}
	return 0;
}