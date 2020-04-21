// 1. read() / write() �� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�
// 1. Create a program to copy files to read() / write()

#include <fstream>
#include <string>
using namespace std;

int main() {
    // �� ����(hw2_1.txt) �б�
    // �� Read file (hw2_1.txt)
    ifstream input("test2_1.txt", ios::in | ios::binary);
    string str;

    // 1. ��ġ ������(Ŀ��)�� ���� ������ �ű��
    // 1. Move the cursor to the end of the file
    input.seekg(0, ios::end);

    // 2. ���� ���� ��ġ�� �д´� 
    // 2. Read the location at the end of the file
    int size = input.tellg(); // size : ������ ũ��

    // 3. str�� size�� ������ ũ�⸸ŭ �Ҵ��Ѵ�
    // 3. Allocate the size of the str by the size of the file
    str.resize(size);

    // 4. ��ġ �����ڸ� �ٽ� ó������ �ʱ�ȭ�Ѵ�
    // 4. Initialize the location designator for the first time
    input.seekg(0, ios::beg);

    // 5. ������ (��ü)������ str�� �д´�
    // 5. Read the (full) contents of the file to the str
    input.read(&str[0], size);
    input.close(); // ���� �ݱ�

    // �� ����(copy.txt) ����
    // �� Copy file (hw2_1.txt)
    ofstream output("copy.txt", ios::out | ios::binary);

    output.write(&str[0], size);
    output.close();

    return 0;
}