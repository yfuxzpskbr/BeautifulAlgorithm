#include <iostream>
using namespace std;
void swap(int& a, int& b);
int partition(int arr[], int p, int r);
int main() {
	int arr[10] = { 4,1,8,0,2,6,7,3,5,9 };
	cout << "��Ԫ����λ�ã�" << partition(arr, 0, 9) << endl;
	cout << "-------------------------" << endl;
	cout << "������ɺ�" << endl;
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

//��������
void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

//����ɨ�軮���㷨
int partition(int arr[], int p, int r) {
	int pivot = arr[p];
	int sp = p + 1;
	int bigger = r;
	while (sp <= bigger) {
		if (arr[sp] <= pivot) {//���sp��ָ����С�ڵ�����Ԫ,sp����
			sp++;
		}
		else {//���򽻻�sp�����ݺ�bigger�����ݣ�bigger����
			if (sp < bigger)
				swap(arr[sp], arr[bigger]);
			bigger--;
			//ע������sp����++����Ϊbiggerԭ��ָ�����ݿ��ܱ����Ǵ�����Ԫ�ģ�
			//��˽�������Ҫ�ж��Ƿ��ٴν���
		}
	}
	swap(arr[bigger], arr[p]);//����Ԫ�����м�
	return bigger;
}