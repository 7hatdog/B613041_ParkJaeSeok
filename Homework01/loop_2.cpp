// 2. �� ���� Ȥ�� �� ���� Ȥ�� �� ������ ���� ���ϴ� �Լ� sum�� �ۼ��϶�

#include <iostream>
using namespace std;

int sum(int a, int b) {
	return a + b;
}

int sum(int a, int b, int c) {
	return a + b + c;
}

int sum(int a, int b, int c, int d) {
	return a + b + c + d;
}

int main() {
	cout << sum(1, 2) << endl;
	cout << sum(3, 4, 5) << endl;
	cout << sum(6, 7, 8, 9) << endl;

	return 0;
}