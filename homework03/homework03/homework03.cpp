/*
	< 과제 3 >

	Rectangle은 왼쪽 위의 좌표-오른쪽 아래의 좌표,
	혹은 왼쪽 아래의 좌표-오른쪽 위의 좌표를 인수로 가진다.
	Rectangle의 넓이를 구하는 area() 함수, Rectangle class가
	잘 동작함을 보여주는 main()를 포함한 Rectangle.cpp를 작성하여 제출하라
*/

#include "homework03.h"

int main() {
	Point p1 = Point(1, 2);
	Point p2 = Point(3, 4);
	PointArray pArr = PointArray();

	// push_back
	pArr.push_back(p1);
	cout << "p1 : " << "( " << pArr.get(0).getX() << ", " << pArr.get(0).getY() << " )" << endl;

	// insert
	pArr.insert(1, p2);
	cout << "p2 : " << "( " << pArr.get(1).getX() << ", " << pArr.get(1).getY() << " )" << endl;

	// area
	Rectangle rec = Rectangle(p1, p2);
	cout << "rectangle " << "( " << p1.getX() << ", " << p1.getY() << " )" << " , "
		<< "( " << p2.getX() << ", " << p2.getY() << " ) area is " << rec.area() << endl;

	return 0;
}