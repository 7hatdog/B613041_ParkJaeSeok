// 2. test2_2.txt의 한 줄에 있는 두 수를 읽어 그 합을 출력하는 함수를 구현하시오.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int coutSum(string fName) { // 파일을 읽지 못했을 경우, -1을 반환하기 위해서 int형으로 선언했습니다
	ifstream input(fName);

	if (input.is_open()) {
		string line;
		
		while (getline(input, line)) {
			int cnt = 0, sum = 0;		// cnt가 0일 때는 해당 줄의 1번째 수, 1일 때는 2번째 수를 의미합니다
			string num[2] = { "", "" };	// num[0]에는 해당 줄의 1번째 수가, num[1]에는 2번째 수가 저장됩니다

			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ' ') {
					cnt++; 
					continue;
				}
				num[cnt] += line[i]; 
				// 문자열 num[cnt]에 ' ' 이전까지의 수(문자)들을 이어붙입니다
			}
			
			for (int i = 0; i < 2; i++) {
				int n = 0;

				// 문자 형태로 저장된 수를 정수 형태로 변환합니다
				for (int j = 0; j < num[i].length(); j++) {
					n = n * 10 + (num[i][j] - '0');
					/*
						i\j  0  1	
						 0   1	4
						 1   5	5
					*/
				}
				sum += n;
			}
			cout << num[0] << " + " << num[1] << " = " << sum << endl;
		}
	}
	else { cerr << "파일을 읽지 못했습니다" << endl; return -1; }

	input.close();
}

int main() {
	string fName = "test2_2.txt";
	coutSum(fName);

	return 0;
}

/*
	<16행>
	string num1, num2 
	-> 이런 식으로 줄줄이 선언하는 것 보다는,
	string num[] 
	-> 배열로 선언해주는 것이 컨트롤하기에 더 편리합니다

	<23행>
	string s = "";
	s += "a";
	s += "bcd";
	cout << s;	// abcd
	-> 이런 식으로 string은 문자열 이어붙이기를 할 수 있습니다
*/
