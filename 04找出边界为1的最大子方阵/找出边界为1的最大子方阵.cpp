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
	cout << "边界为1的最大子矩阵为: " << max1Arr(arr) << "阶" << endl;
	return 0;
}

int max1Arr(int(*arr)[5])
{
	int ans = 5;
	//遍历阶数，从最高阶开始
	while (ans) {
		//遍历每一个顶点
		for (int i = 0; i < 5; i++) {
			if (i + ans > 5)break;//顶点不足ans阶，break
			for (int j = 0; j < 5; j++) {
				if (j + ans > 5)break;//顶点不足ans阶，break
				//定义顶点
				int pi = i;
				int pj = j;
				bool end = false;
				//验证四条边
				while (pj < j + ans) {//上
					if (arr[pi][pj] == 0) {
						end = true;
						break;
					}
					pj++;
				}
				if (end)continue;
				pj--;
				while (pi < i + ans) {//右
					if (arr[pi][pj] == 0) {
						end = true;
						break;
					}
					pi++;
				}
				if (end)continue;
				pi--;
				while (pj >= j) {//下
					if (arr[pi][pj] == 0) {
						end = true;
						break;
					}
					pj--;
				}
				if (end)continue;
				pj++;
				while (pi >= i) {//左
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