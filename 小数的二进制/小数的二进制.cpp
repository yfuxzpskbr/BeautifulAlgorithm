#include <iostream>
#include <string>
using namespace std;
int main() {
	double a = 0.625;
	string ans = "0.";
	//��2ȡ����
	while (a) {
		//����2
		a *= 2;
		//����λ����0����λΪ1
		if (a >= 1) {
			ans += "1";
			a -= 1;
		}
		//�����λΪ0
		else ans += "0";
		//С�����32λ�޷���ʾ�����ERROR����return
		if (ans.size() > 34) {
			cout << "ERROR" << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}