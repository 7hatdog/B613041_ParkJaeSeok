// 3. ������ ����(n��)�� ������ ���� ���ϴ� �Լ� sum�� �ۼ��϶�.

#include <iostream>
using namespace std;

int sum(int n) {
	int i, input, total = 0;

	cout << n << "���� ������ �Է��ϼ��� : ";
	for (i = 0; i < n; i++) {
		cin >> input;
		total += input;
 	}
	return total;
}

int main() {
	int n, res;
	cout << "������ ������ �Է��ϼ��� : ";
	cin >> n;

	res = sum(n);
	cout << "�Էµ� ������ ������ " << res << "�Դϴ�\n";

	return 0;
}
