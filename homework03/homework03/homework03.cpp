/*
	< 과제 3 >

	Rectangle은 왼쪽 위의 좌표-오른쪽 아래의 좌표,
	혹은 왼쪽 아래의 좌표-오른쪽 위의 좌표를 인수로 가진다.
	Rectangle의 넓이를 구하는 area() 함수, Rectangle class가
	잘 동작함을 보여주는 main()를 포함한 Rectangle.cpp를 작성하여 제출하라
*/

#include <iostream>
using namespace std;

class Point {
	int x, y;

public:
	Point(int xx = 0, int yy = 0) { x = xx; y = yy; }
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(const int xx) { x = xx; }
	void setY(const int yy) { y = yy; }
};

class PointArray {
	int size;
	Point* points;

	void resize(int s) {
		Point* tmp = new Point[s];

		for (int i = 0; i < s - 1; i++) {
			tmp[i] = points[i];
		}
		delete points;
		points = tmp;
	}

public:
	PointArray() {
		size = 0;
		points = new Point[size];
	}

	PointArray(Point pts[], const int pArraySize) {
		size = pArraySize;
		points = pts;
	}

	PointArray(const PointArray& pv) {
		size = pv.size;
		points = pv.points;
	}

	~PointArray() { delete points; }

	void clear() {
		size = 0;
		points = new Point[size];
	}

	int getSize() const { return size; }

	void push_back(const Point& p) {
		resize(++size);
		points[size - 1] = p;
	}

	void insert(const int pos, const Point& p) {
		if (pos > size || pos < 0) {
			cerr << "배열 범위 밖의 position값 입니다." << endl;
		}
		else {
			Point* tmp = new Point[size - pos];

			for (int i = pos; i < size; i++) {
				tmp[i - pos] = points[i];
			}
			resize(++size);
			points[pos] = p;
			for (int i = pos + 1; i < size; i++) {
				points[i] = tmp[i - pos - 1];
			}
		}
	}

	void remove(const int pos) {
		if (pos >= size || pos < 0) {
			cerr << "배열 범위 밖의 position값 입니다." << endl;
		}
		else {
			Point* tmp = new Point[size - pos];

			for (int i = pos; i < size; i++) {
				tmp[i - pos] = points[i];
			}
			resize(--size);
			for (int i = pos + 1; i < size; i++) {
				points[i] = tmp[i - pos - 1];
			}
		}
	}

	Point get(const int pos) { return this->points[pos]; }
	const Point get(const int pos) const { return this->points[pos]; }
};

class Polygon {
protected:
	int numPolygons;
	PointArray points;
public:
	Polygon() {
		numPolygons = 0;
	}
	Polygon(const PointArray& pa) {
		numPolygons = pa.getSize();
		points = pa;
	}
	Polygon(const PointArray& pa, const int numPoints) {
		numPolygons = numPoints;
		points = pa;
	}
	// virtual double area() const = 0; 
	int getNumPolygons() { return numPolygons; }
	int getNumSides() { return points.getSize(); }
	PointArray* getPoints() { return &points; }
	~Polygon() { --numPolygons; }
};

class Rectangle : public Polygon {
	Point left, right;

public:
	Rectangle(const Point& a, const Point& b) {
		if (a.getX() < b.getX()) {
			left = a;
			right = b;
		}
		else {
			left = b;
			right = a;
		}
	}
	Rectangle(const int a, const int b, const int c, const int d) {
		if (a < c) {
			left.setX(a);
			left.setY(b);
			right.setX(c);
			right.setY(d);
		}
		else {
			left.setX(c);
			left.setY(d);
			right.setX(a);
			right.setY(b);
		}
	}

	double area() {
		double width = (double)right.getX() - left.getX();
		double height = (double)right.getY() - left.getY();
		if (height < 0) {
			height = -height;
		}

		return width * height;
	}
};

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