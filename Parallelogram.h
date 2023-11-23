#pragma once
#include "Vector.h"

class Parallelogram {
private:
    Vector vector1;
    Vector vector2;

public:
    Parallelogram();

    Parallelogram(Vector vector1, Vector vector2);

    void setVector1(Vector vector);

    Vector getVector1();

    void setVector2(Vector vector);

    Vector getVector2();

    int perimeter();

    void printParallelogram();
};