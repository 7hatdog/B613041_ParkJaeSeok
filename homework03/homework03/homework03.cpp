/*
	���� 3

	Rectangle�� ���� ���� ��ǥ-������ �Ʒ��� ��ǥ,
	Ȥ�� ���� �Ʒ��� ��ǥ-������ ���� ��ǥ�� �μ��� ������.
	Rectangle�� ���̸� ���ϴ� area() �Լ�, Rectangle class��
	�� �������� �����ִ� main()�� ������ Rectangle.cpp�� �ۼ��Ͽ� �����϶�
*/

#include <iostream>
using namespace std;

class Point {
	int x, y;

public:
	Point(int xx = 0, int yy = 0) {
		x = xx; y = yy;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(int xx) {
		x = xx;
	}
	void setY(int yy) {
		y = yy;
	}
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

	PointArray(Point pts[], int pArraySize) {
		size = pArraySize;
		points = pts;
	}

	void clear() {
		size = 0;
		points = new Point[size];
	}

	int getSize() {
		return size;
	}

	void push_back(Point& p) {
		resize(++size);
		points[size - 1] = p;
	}

	void insert(int pos, Point& p) {
		if (pos > size || pos < 0) {
			cerr << "�迭 ���� ���� position�� �Դϴ�." << endl;
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

	void remove(int pos) {
		if (pos >= size || pos < 0) {
			cerr << "�迭 ���� ���� position�� �Դϴ�." << endl;
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

	Point get(int pos) {
		return this->points[pos];
	}

	const Point get(const int pos) const {
		return this->points[pos];
	}
};

// Polygon Ŭ������ ����ġ ����...
class Polygon {
protected:
	int numPolygons; // numPolygons�� ��� �ٷ������...
	PointArray points;
public:
	Polygon() {
		numPolygons = 0;
		// PointArray points�� ��� �ʱ�ȭ�ؾ��ϳ�...
	}
	Polygon(PointArray& pa) {
		numPolygons = pa.getSize();
		points = pa;
	}
	Polygon(PointArray& pa, int numPoints) {
		numPolygons = numPoints;
		points = pa;
	}
	///virtual double area() const = 0; 
	int getNumPolygons() { return numPolygons; }
	int getNumSides() { return points.getSize(); }
	PointArray* getPoints() { return &points; }
	~Polygon() { --numPolygons; }
};

class Rectangle : public Polygon {
	Point left, right;

public:
	Rectangle(Point& a, Point& b) {
		if (a.getX() < b.getX()) {
			left = a;
			right = b;
		}
		else {
			left = b;
			right = a;
		}
	}
	Rectangle(int a, int b, int c, int d) {
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
	Point p2 = Point(9, 10);
	PointArray pArr = PointArray();

	// push_back
	pArr.push_back(p1);
	cout << "p1 : " << "( " << pArr.get(0).getX() << ", " << pArr.get(0).getY() << " )" << endl;

	// insert
	pArr.insert(1, p2);
	cout << "p2 : " << "( " << pArr.get(1).getX() << ", " << pArr.get(1).getY() << " )" << endl;

	// remove
	cout << "remove ���� pArr ũ�� : " << pArr.getSize() << " -> ";
	pArr.remove(1);
	cout << "remove ���� pArr ũ�� : " << pArr.getSize() << endl;

	// p1, p2�� ���� �� ������ ��ǥ�� �ϴ� �簢�� rec�� ����
	Rectangle rec = Rectangle(p1, p2);
	cout << "��ǥ " << "( " << p1.getX() << ", " << p1.getY() << " )" << " , "
		<< "( " << p2.getX() << ", " << p2.getY() << " ) �� �簢�� ���� = " << rec.area() << endl;

	return 0;
}