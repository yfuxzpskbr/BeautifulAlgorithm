#include <iostream>
using namespace std;
void swap(int& a, int& b);
int partition(int arr[], int p, int r, int& eq, int& bigger);
int main() {
	int arr[] = { 6,5,8,1,9,0,3,7,1,6,4,1,9,2,1 };
	int eq, bigger;
	cout << "������" << endl;
	if (partition(arr, 0, 14, eq, bigger) != -1) {
		cout << "��ȵ�Ԫ��û��" << endl;
	}
	else {
		cout << "��ȵ�Ԫ���У�" << bigger - eq + 1 << endl;
		cout << "��" << eq << "��" << bigger << "��������Ԫ" << endl;
	}
	for (int i = 0; i < 15; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

//��������
void swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

//����֮��ָ�������
int partition(int arr[], int p, int r, int& eq, int& bigger) {
	//eqָ���ǵ�����Ԫ�ĵ�һ��Ԫ��
	//biggerָ�������ұߵ�Ԫ��ȫ��������Ԫ����bigger+1�Ǵ�����Ԫ�ĵ�һ��Ԫ��
	//Ҳ����bigger���ָ���ǵ�����Ԫ�����һ��Ԫ��
	int pivot = arr[p];
	int sp = p + 1;	//ɨ��ָ��
	eq = p + 1;
	bigger = r;
	bool tag = false;	//tag��ʾ�Ƿ��Ѿ������˵�����Ԫ��ֵ
	while (sp <= bigger) {
		if (!tag) {//û��������������Ԫ��Ԫ��
			if (arr[sp] < pivot)sp++;	//С�ھ�sp����
			else if (arr[sp] > pivot) {
				if (sp < bigger)//spָ�����ݴ�����Ԫ��sp��bigger����ͬһλ�þͽ�����bigger����
					swap(arr[sp], arr[bigger]);
				bigger--;
			}
			else {//��һ���ҵ�������Ԫ��Ԫ��
				tag = true;	//�����˵�����Ԫ��ֵ
				eq = sp;
			}
		}
		else {//���е�����Ԫ��Ԫ�ش���
			if (arr[sp] == pivot)sp++;//���� ����
			else if (arr[sp] > pivot) {
				if (sp < bigger)//������sp��bigger����ȣ���������
					swap(arr[sp], arr[bigger]);
				bigger--;
			}
			else {//С��
				swap(arr[eq], arr[sp]);
				eq++;
			}
		}
	}
	if (tag) {//��������Ԫ��ͬ��Ԫ��
		swap(arr[--eq], arr[p]);//��Ԫ����
		return -1;//����-1
	}
	else {//û������Ԫ��ͬ��Ԫ��
		swap(arr[p], arr[bigger]);
		return bigger;
	}
}