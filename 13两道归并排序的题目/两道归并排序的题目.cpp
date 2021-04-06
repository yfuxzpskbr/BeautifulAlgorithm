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

//从屁股开始合并
void merge(int a[], int b[], int lena, int lenb) {
	//初始指向屁股
	int pa = lena - 1;
	int pb = lenb - 1;
	int current = lena + lenb - 1;

	//当a和b都没扫描完时
	while (pa >= 0 && pb >= 0) {
		//如果a的屁股大，就加入current，并两者--
		if (a[pa] >= b[pb]) {
			a[current] = a[pa];
			pa--;
			current--;
		}
		//否则b的屁股加入current，--
		else {
			a[current] = b[pb];
			pb--;
			current--;
		}
	}
	//b没有完的话插入
	while (pb >= 0) {
		a[current] = b[pb];
		pb--;
		current--;
	}

	//a没有完的不用插入
}