#pragma once

class Vector {
private:
    Point point1;
    Point point2;

public:
    friend void setPoints(Vector vector, Point point1, Point point2);

    Vector();

    Vector(Point point1, Point point2);

    void setPoint2(Point point);

    Point getPoint2();

    void setPoint1(Point point);

    Point getPoint1();

    float lengthVector();

    int* coordinates();

    float scalarMultiplication(Vector v2);

    void printVector();
};