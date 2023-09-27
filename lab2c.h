#pragma once

class Point {
public:
    char name[20];
    int x;
    int y;
    int z;
    void set_point();
    void print_point();
};

class ColoredPoint : public Point {
public:
    char color[20];
    void set_colored_point();
    void print_colored_point();
};

class Vector {
public:
    ColoredPoint point1;
    ColoredPoint point2;
    void set_vector();
    float length_vector();
    int* coordinates();
    float scalar_multiplication(Vector* v2);
    void print_vector();
};

class Parallelogramm {
public:
    Vector vector1;
    Vector vector2;
    void set_parallelogramm();
    int perimeter();
    float square();
    void print_parallelogramm();
};

class Triangle {
public:
    ColoredPoint point1;
    ColoredPoint point2;
    ColoredPoint point3;
    void set_triangle();
    int perimeter();
    float square();
    void print_triangle();
};