// 5c. "Hello World"를 n번 찍는 프로그램을 구현하라 (do while 사용)

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	do {
		cout << "Hello World\n";
		n--;
	} while (n > 0);

	return 0;
}