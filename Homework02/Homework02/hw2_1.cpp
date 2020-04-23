// 1. read() / write() 로 파일을 복사하는 프로그램을 작성하시오

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// ※ 파일 (test2_1.txt) 쓰기
	ofstream writeFile;
	writeFile.open("test2_1.txt");
	
	if(writeFile.is_open()) {
		writeFile << "B613041" << endl;
		writeFile << "ParkJaeSeok" << endl;
		
	} else { cerr << "파일 쓰기 실패" << endl; return -1; }
	
    // ※ 파일(test2_1.txt) 읽기
    ifstream input("test2_1.txt", ios::in | ios::binary);
    if (!input.is_open()) { cerr << "파일을 읽지 못했습니다" << endl; return -1; }
    string str;

    // 1. 위치 지정자(커서)를 파일 끝으로 옮긴다
    input.seekg(0, ios::end);

    // 2. 파일 끝의 위치를 읽는다 
    int size = input.tellg(); // size : 파일의 크기

    // 3. str의 size를 파일의 크기만큼 할당한다
    str.resize(size);

    // 4. 위치 지정자를 다시 처음으로 초기화한다
    input.seekg(0, ios::beg);

    // 5. 파일의 전체 내용을 str에 읽는다
    input.read(&str[0], size);
    input.close(); // 파일 닫기

    // ※ 파일(copy.txt) 복사
    ofstream output("copy.txt", ios::out | ios::binary);

    output.write(&str[0], size);
    output.close();

    return 0;
}
