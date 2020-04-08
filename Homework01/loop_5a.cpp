// 5a. "Hello World"를 n번 찍는 프로그램을 구현하라 (for 사용)

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Hello World\n";
	}

	return 0;
}