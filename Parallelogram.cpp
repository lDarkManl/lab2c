#include <iostream>
#include <windows.h>
#include <format>
#include <windows.h>
#include <cmath>
#include <list>
#include "Vector.h"
#include "Figure.h"
using namespace std;

//Добавлены сортировка и поиск
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

    bool comparePerimeter(Parallelogram& p1, Parallelogram& p2)
    {
        return p1.perimeter() < p2.perimeter();
    }

    Parallelogram findMinPerimeter(list<Parallelogram>& parallelograms)
    {
        return *min_element(parallelograms.begin(), parallelograms.end(), comparePerimeter);
    }

    Parallelogram findMaxPerimeter(list<Parallelogram>& parallelograms)
    {
        return *max_element(parallelograms.begin(), parallelograms.end(), comparePerimeter);
    }
};