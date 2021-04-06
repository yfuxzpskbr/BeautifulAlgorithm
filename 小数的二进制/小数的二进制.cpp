#include <iostream>
#include <string>
using namespace std;
int main() {
	double a = 0.625;
	string ans = "0.";
	//乘2取整法
	while (a) {
		//乘以2
		a *= 2;
		//整数位大于0，该位为1
		if (a >= 1) {
			ans += "1";
			a -= 1;
		}
		//否则该位为0
		else ans += "0";
		//小数点后32位无法表示，输出ERROR，并return
		if (ans.size() > 34) {
			cout << "ERROR" << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}