// 3. 임의의 개수(n개)의 정수의 합을 구하는 함수 sum을 작성하라.

#include <iostream>
using namespace std;

int sum(int n) {
	int i, input, total = 0;

	cout << n << "개의 정수를 입력하세요 : ";
	for (i = 0; i < n; i++) {
		cin >> input;
		total += input;
 	}
	return total;
}

int main() {
	int n, res;
	cout << "정수의 개수를 입력하세요 : ";
	cin >> n;

	res = sum(n);
	cout << "입력된 정수의 총합은 " << res << "입니다\n";

	return 0;
}
