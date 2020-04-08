// 5b. "Hello World"를 n번 찍는 프로그램을 구현하라 (while 사용)

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	while (n > 0) {
		cout << "Hello World\n";
		n--;
	}

	return 0;
}