#include <iostream>
#include <windows.h>
#include <format>
#include <windows.h>
#include <cmath>
#include "Vector.h"
#include "Figure.h"
using namespace std;


class Parallelogram : Figure {
private:
    Vector vector1;
    Vector vector2;

public:
    Parallelogram() {}

    Parallelogram(Vector vector1, Vector vector2)
    {
        this->vector1 = vector1;
        this->vector2 = vector2;
    }

    void setVector1(Vector vector)
    {
        this->vector1 = vector;
    }

    Vector getVector1()
    {
        return this->vector1;
    }

    void setVector2(Vector vector)
    {
        this->vector2 = vector;
    }

    Vector getVector2()
    {
        return this->vector2;
    }

    int perimeter() {
        return (int)(vector1.lengthVector() * 2 + vector2.lengthVector() * 2);
    }

    void print() {
        vector1.printVector();
        vector2.printVector();
    }
};