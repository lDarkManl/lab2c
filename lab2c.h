#pragma once

class Point {
public:
    char name[20];
    int x;
    int y;
    int z;
    Point();
    void print_point();
};

class ColoredPoint : public Point {
public:
    char color[20];
    ColoredPoint();
    void print_colored_point();
};

class Vector {
public:
    ColoredPoint point1;
    ColoredPoint point2;
    float length_vector();
    int* coordinates();
    float scalar_multiplication(Vector* v2);
    void print_vector();
};

class Parallelogramm {
public:
    Vector vector1;
    Vector vector2;
    int perimeter();
    float square();
    void print_parallelogramm();
};

class Triangle {
public:
    ColoredPoint point1;
    ColoredPoint point2;
    ColoredPoint point3;
    int perimeter();
    float square();
    void print_triangle();
};