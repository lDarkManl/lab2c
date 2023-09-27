#pragma once

struct point {
    char name[20];
    int x;
    int y;
    int z;
    void set_point(struct point* s);
    void print_point(struct point* s);
};

struct colored_point {
    struct point self_point;
    char color[20];
    void set_colored_point(struct colored_point* s);
    void print_colored_point(struct colored_point* s);
};

struct vector {
    struct colored_point point1;
    struct colored_point point2;
    void set_vector(struct vector* v);
    float length_vector(struct vector* v);
    int* coordinates(struct vector* v);
    float scalar_multiplication(struct vector* v1, struct vector* v2);
    void print_vector(struct vector* v);
};

struct parallelogramm {
    struct vector vector1;
    struct vector vector2;
    void set_parallelogramm(struct parallelogramm* p);
    int perimeter(struct parallelogramm* p);
    float square(struct parallelogramm* p);
    void print_parallelogramm(struct parallelogramm* p);
};

struct triangle {
    struct colored_point point1;
    struct colored_point point2;
    struct colored_point point3;
    void set_triangle(struct triangle* t);
    int perimeter(struct triangle* t);
    float square(struct triangle* t);
    void print_triangle(struct triangle* t);
};