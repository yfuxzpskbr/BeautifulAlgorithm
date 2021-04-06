#include <iostream>
using namespace std;
void swap(int& a, int& b);
int partition(int arr[], int p, int r, int& eq, int& bigger);
int main() {
	int arr[] = { 6,5,8,1,9,0,3,7,1,6,4,1,9,2,1 };
	int eq, bigger;
	cout << "分区后：" << endl;
	if (partition(arr, 0, 14, eq, bigger) != -1) {
		cout << "相等的元素没有" << endl;
	}
	else {
		cout << "相等的元素有：" << bigger - eq + 1 << endl;
		cout << "从" << eq << "到" << bigger << "都等于主元" << endl;
	}
	for (int i = 0; i < 15; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

//交换函数
void swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

//快排之三指针分区法
int partition(int arr[], int p, int r, int& eq, int& bigger) {
	//eq指的是等于主元的第一个元素
	//bigger指的是其右边的元素全部大于主元，即bigger+1是大于主元的第一个元素
	//也就是bigger最后指的是等于主元的最后一个元素
	int pivot = arr[p];
	int sp = p + 1;	//扫描指针
	eq = p + 1;
	bigger = r;
	bool tag = false;	//tag表示是否已经遇到了等于主元的值
	while (sp <= bigger) {
		if (!tag) {//没有遇到过等于主元的元素
			if (arr[sp] < pivot)sp++;	//小于就sp右移
			else if (arr[sp] > pivot) {
				if (sp < bigger)//sp指的内容大于主元且sp和bigger不是同一位置就交换，bigger左移
					swap(arr[sp], arr[bigger]);
				bigger--;
			}
			else {//第一次找到等于主元的元素
				tag = true;	//遇到了等于主元的值
				eq = sp;
			}
		}
		else {//已有等于主元的元素存在
			if (arr[sp] == pivot)sp++;//等于 右移
			else if (arr[sp] > pivot) {
				if (sp < bigger)//大于且sp和bigger不相等，交换左移
					swap(arr[sp], arr[bigger]);
				bigger--;
			}
			else {//小于
				swap(arr[eq], arr[sp]);
				eq++;
			}
		}
	}
	if (tag) {//存在与主元相同的元素
		swap(arr[--eq], arr[p]);//主元置中
		return -1;//返回-1
	}
	else {//没有与主元相同的元素
		swap(arr[p], arr[bigger]);
		return bigger;
	}
}