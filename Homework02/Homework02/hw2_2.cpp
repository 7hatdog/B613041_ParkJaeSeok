// 2. test.txt�� �� �ٿ� �ִ� �� ���� �о� �� ���� ����ϴ� �Լ��� �����Ͻÿ�.
// 2. Read the two numbers on one line of test.txt to implement the function to output the sum

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void coutSum(string fName) {
	ifstream input(fName);

	if (input.is_open()) {
		string line;
		
		while (getline(input, line)) {
			int cnt = 0, sum = 0;
			// cnt�� 0�� ���� �ش� ���� 1��° ��, 1�� ���� 2��° ��
			// 1st number on that line when cnt is 0 and 2nd number on 1
			string num[2] = { "", "" }; 
			// num[0]���� �ش� ���� 1��° ����, num[1]���� 2��° ���� ����ȴ�
			// number [0] stores the first number of the line, and number [1] stores the second number

			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ' ') {
					cnt++; 
					continue;
				}
				num[cnt] += line[i]; 
				// ���ڿ� num[cnt]�� ' ' ���������� ��(����)���� �̾���δ�
				// connect the number of characters before ' ' to string number [cnt]
			}
			
			for (int i = 0; i < 2; i++) {
				int n = 0;

				// ���� ���·� ����� ���� ���� ���·� ��ȯ�Ѵ�
				// convert the number stored in a letter into an integer form
				for (int j = 0; j < num[i].length(); j++) {
					n = n * 10 + (num[i][j] - '0');
				}
				sum += n;
			}
			cout << num[0] << " + " << num[1] << " = " << sum << endl;
		}
	}
	else cout << "������ ���� ���߽��ϴ�."; 

	input.close();
}

int main() {
	string fName = "test2_2.txt";
	coutSum(fName);

	return 0;
}

/*
	16��
	string num1, num2 ������ �����ϴ� �� ����,
	string num[] �迭�� �������ִ� ���� ��Ʈ���ϱ⿡ �� ����

	string s = "";
	s += "a";
	s += "bcd";
	�̷��� string�� ���ڿ� �̾���̱Ⱑ �����ϴ�
*/