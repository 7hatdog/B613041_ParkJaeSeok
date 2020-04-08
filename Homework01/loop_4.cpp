// 4. 3번 문제의 sum을 recursive하게 다시 구현하라

#include <iostream>
using namespace std;

int n;

int sum(int cnt, int total) {	
	if (cnt == n) {
		return total;
	}
	else {
		int input;
		cout << ++cnt << "번째 정수 입력 : ";
		cin >> input;
		sum(cnt, total + input);
	}
}

int main() {
	cout << "정수의 개수를 입력하세요 : ";
	cin >> n;

	int res = sum(0, 0);
	cout << "입력된 정수의 총합은 " << res << "입니다\n"; 

	return 0;
}