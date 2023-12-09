#include <iostream>
#include <windows.h>
#include <format>
#include <windows.h>
#include <cmath>
#include <list>
#include "Point.h"

using namespace std;

//Добавлен контейнер
class Vector {
private:
    list <Point> points;

public:
    friend void setPoints(Vector vector, Point point1, Point point2)
    {
        vector.points.push_back(point1);
        vector.points.push_back(point2);
    }

    Vector() {}

    Vector(Point point1, Point point2) {
        this->points.push_back(point1);
        this->points.push_back(point2);
    }

    void setPoint2(Point point) {
        this->points.pop_back();
        this->points.push_back(point);
    }

    Point getPoint2() {
        return this->points.back();
    }

    void setPoint1(Point point) {
        this->points.pop_front();
        this->points.push_front(point);
    }

    Point getPoint1() {
        return this->points.front();
    }

    float lengthVector() {
        return sqrt(pow(points.back().getX() - points.front().getX(), 2) + pow(points.back().getY() - points.front().getY(), 2) + pow(points.back().getZ() - points.front().getZ(), 2));
    }

    int* coordinates() {
        static int coordinates[3];
        coordinates[0] = points.back().getX() - points.front().getX();
        coordinates[1] = points.back().getY() - points.front().getY();
        coordinates[2] = points.back().getZ() - points.front().getZ();
        return coordinates;
    }

    float scalarMultiplication(Vector v2) {
        int* coordinatesV1 = this->coordinates();
        int* coordinatesV2 = v2.coordinates();
        return coordinatesV1[0] * coordinatesV2[0] + coordinatesV1[1] * coordinatesV2[1] + coordinatesV1[2] * coordinatesV2[2];
    }

    void printVector() {
        int* coordinates = this->coordinates();
        cout << "Вектор " << points.front().getName() << points.back().getName() << "(" << coordinates[0] << ", " << coordinates[1] << ", " << coordinates[2] << ")" << endl;
    }
};