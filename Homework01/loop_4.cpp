// 4. 3�� ������ sum�� recursive�ϰ� �ٽ� �����϶�

#include <iostream>
using namespace std;

int n;

int sum(int cnt, int total) {	
	if (cnt == n) {
		return total;
	}
	else {
		int input;
		cout << ++cnt << "��° ���� �Է� : ";
		cin >> input;
		sum(cnt, total + input);
	}
}

int main() {
	cout << "������ ������ �Է��ϼ��� : ";
	cin >> n;

	int res = sum(0, 0);
	cout << "�Էµ� ������ ������ " << res << "�Դϴ�\n"; 

	return 0;
}