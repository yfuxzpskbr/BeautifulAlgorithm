#include <iostream>
#include <cmath>
using namespace std;
void A(int n);
int* kal;
int main() {
	A(100000);
	return 0;
}

//∞£ œ…∏∑®
void A(int n) {
	int length = 2;
	while (length / log(length) < n) {
		length++;
	}
	kal = new int[length] { 0 };
	for (int i = 2; i < length; i++) {
		int k = 2;
		if (kal[i] == -1) {
			continue;
		}
		while (k * i < length) {
			kal[k * i] = -1;
			k++;
		}
	}
	int cnt = 0;
	for (int i = 2; i < length; i++) {
		if (kal[i] != -1) {
			cnt++;
			if (cnt == n) {
				cout << i << endl;
				delete[]kal;
				return;
			}
		}
	}
}