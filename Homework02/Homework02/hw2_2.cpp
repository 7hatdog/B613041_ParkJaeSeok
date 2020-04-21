// 2. test.txt의 한 줄에 있는 두 수를 읽어 그 합을 출력하는 함수를 구현하시오.
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
			// cnt가 0일 때는 해당 줄의 1번째 수, 1일 때는 2번째 수
			// 1st number on that line when cnt is 0 and 2nd number on 1
			string num[2] = { "", "" }; 
			// num[0]에는 해당 줄의 1번째 수가, num[1]에는 2번째 수가 저장된다
			// number [0] stores the first number of the line, and number [1] stores the second number

			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ' ') {
					cnt++; 
					continue;
				}
				num[cnt] += line[i]; 
				// 문자열 num[cnt]에 ' ' 이전까지의 수(문자)들을 이어붙인다
				// connect the number of characters before ' ' to string number [cnt]
			}
			
			for (int i = 0; i < 2; i++) {
				int n = 0;

				// 문자 형태로 저장된 수를 정수 형태로 변환한다
				// convert the number stored in a letter into an integer form
				for (int j = 0; j < num[i].length(); j++) {
					n = n * 10 + (num[i][j] - '0');
				}
				sum += n;
			}
			cout << num[0] << " + " << num[1] << " = " << sum << endl;
		}
	}
	else cout << "파일을 읽지 못했습니다."; 

	input.close();
}

int main() {
	string fName = "test2_2.txt";
	coutSum(fName);

	return 0;
}

/*
	16행
	string num1, num2 줄줄이 선언하는 것 보단,
	string num[] 배열로 선언해주는 것이 컨트롤하기에 더 좋다

	string s = "";
	s += "a";
	s += "bcd";
	이렇게 string은 문자열 이어붙이기가 가능하다
*/