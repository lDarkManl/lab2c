#include <iostream>
#include <windows.h>
#include <format>
#include <windows.h>
#include <cmath>
#include "Point.h"

using namespace std;

class Vector {
private:
    Point point1;
    Point point2;

public:
    friend void setPoints(Vector vector, Point point1, Point point2)
    {
        vector.point1 = point1;
        vector.point2 = point2;
    }

    Vector() {}

    Vector(Point point1, Point point2) {
        this->point1 = point1;
        this->point2 = point2;
    }

    void setPoint2(Point point) {
        this->point2 = point;
    }

    Point getPoint2() {
        return this->point2;
    }

    void setPoint1(Point point) {
        this->point1 = point;
    }

    Point getPoint1() {
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