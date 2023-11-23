#include <iostream>
#include <windows.h>
#include <format>
#include <windows.h>
#include <cmath>

using namespace std;

class ColoredPoint {
private:
    int x, y, z;
    string name;
public:
    ColoredPoint() {}

    ColoredPoint(int x, int y, int z, string name) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->name = name;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getZ() {
        return z;
    }

    string getName() {
        return name;
    }

    void printPoint() {
        cout << "Точка " << name << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

class Vector {
private:
    ColoredPoint point1;
    ColoredPoint point2;

public:
    Vector() {}

    Vector(ColoredPoint point1, ColoredPoint point2) {
        this->point1 = point1;
        this->point2 = point2;
    }

    void setPoint2(ColoredPoint point) {
        this->point2 = point;
    }

    ColoredPoint getPoint2() {
        return this->point2;
    }

    void setPoint1(ColoredPoint point) {
        this->point1 = point;
    }

    ColoredPoint getPoint1() {
        return this->point1;
    }

    float lengthVector() {
        return sqrt(pow(point2.getX() - point1.getX(), 2) + pow(point2.getY() - point1.getY(), 2) + pow(point2.getZ() - point1.getZ(), 2));
    }

    int* coordinates() {
        static int coordinates[3];
        coordinates[0] = point2.getX() - point1.getX();
        coordinates[1] = point2.getY() - point1.getY();
        coordinates[2] = point2.getZ() - point1.getZ();
        return coordinates;
    }

    float scalarMultiplication(Vector v2) {
        int* coordinatesV1 = this->coordinates();
        int* coordinatesV2 = v2.coordinates();
        return coordinatesV1[0] * coordinatesV2[0] + coordinatesV1[1] * coordinatesV2[1] + coordinatesV1[2] * coordinatesV2[2];
    }

    void printVector() {
        int* coordinates = this->coordinates();
        cout << "Вектор " << point1.getName() << point2.getName() << "(" << coordinates[0] << ", " << coordinates[1] << ", " << coordinates[2] << ")" << endl;
    }
};

class Triangle {
private:
    ColoredPoint point1;
    ColoredPoint point2;
    ColoredPoint point3;

public:
    Triangle() {}

    void setPoint1(ColoredPoint point) {
        this->point1 = point;
    }

    ColoredPoint getPoint1() {
        return this->point1;
    }

    void setPoint2(ColoredPoint point) {
        this->point2 = point;
    }

    ColoredPoint getPoint2() {
        return this->point2;
    }

    void setPoint3(ColoredPoint point) {
        this->point3 = point;
    }

    ColoredPoint getPoint3() {
        return this->point3;
    }

    int perimeter() {
        Vector v1(this->point1, this->point2);
        Vector v2(this->point2, this->point3);
        Vector v3(this->point1, this->point3);
        return (int)(v1.lengthVector() + v2.lengthVector() + v3.lengthVector());
    }

    float square() {
        Vector v1(this->point1, this->point2);
        Vector v2(this->point2, this->point3);
        float cosinus, sinus, lengthV1 = v1.lengthVector(), lengthV2 = v2.lengthVector();
        cosinus = v1.scalarMultiplication(v2) / (lengthV1 * lengthV2);
        sinus = sqrt(1 - pow(cosinus, 2));
        return lengthV1 * lengthV2 * sinus / 2;
    }

    void printTriangle() {
        point1.printPoint();
        point2.printPoint();
        point3.printPoint();
    }
};

int main() {
    Triangle triangle;
    ColoredPoint p1(0, 0, 0, "A");
    ColoredPoint p2(1, 0, 0, "B");
    ColoredPoint p3(0, 1, 0, "C");

    triangle.setPoint1(p1);
    triangle.setPoint2(p2);
    triangle.setPoint3(p3);

    triangle.printTriangle();

    return 0;
}
