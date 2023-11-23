#pragma once
#include "Point.h"

class Triangle {
private:
    Point point1;
    Point point2;
    Point point3;

public:
    Triangle() {}

    void setPoint1(Point point);

    Point getPoint1();

    void setPoint2(Point point);

    Point getPoint2();

    void setPoint3(Point point);

    Point getPoint3() {
        return this->point3;
    }

    int perimeter();

    float square();

    void printTriangle();
};