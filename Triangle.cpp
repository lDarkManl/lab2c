#include <iostream>
#include <windows.h>
#include <format>
#include <windows.h>
#include <cmath>
#include "Point.h"
#include "Vector.h"

using namespace std;

class Triangle {
private:
    Point point1;
    Point point2;
    Point point3;

public:
    Triangle() {}

    void setPoint1(Point point) {
        this->point1 = point;
    }

    Point getPoint1() {
        return this->point1;
    }

    void setPoint2(Point point) {
        this->point2 = point;
    }

    Point getPoint2() {
        return this->point2;
    }

    void setPoint3(Point point) {
        this->point3 = point;
    }

    Point getPoint3() {
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