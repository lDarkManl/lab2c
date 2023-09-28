#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <math.h>

struct point {
    char name[20];
    int x;
    int y;
    int z;
    void set_point(struct point *s) 
    {
        char name[20];
        int x, y, z;
        printf("Введите название точки: ");
        gets_s(name);
        printf("Введите координаты точки: ");
        scanf("%d%d%d", &x, &y, &z);
        strcpy(s->name, name);
        s->x = x;
        s->y = y;
        s->z = z;
        while (getchar() != '\n');
    }
    void print_point(struct point* s) 
    {
        printf("%s(%d, %d, %d)\n", s->name, s->x, s->y, s->z);
    }
};

struct colored_point {
    struct point self_point;
    char color[20];
    void set_colored_point(struct colored_point* s) 
    {   
        struct point self_point;
        self_point.set_point(&self_point);
        s->self_point = self_point;
        printf("Введите цвет точки: ");
        gets_s(s->color);
    }
    void print_colored_point(struct colored_point* s)
    {
        s->self_point.print_point(&s->self_point);
        printf("Цвет: %s\n", s->color);
    }

};

struct vector {
    struct colored_point point1;
    struct colored_point point2;
    void set_vector(struct vector* v)
    {
        struct colored_point point1, point2;
        point1.set_colored_point(&point1);
        point2.set_colored_point(&point2);
        v->point1 = point1;
        v->point2 = point2;
    }
    float length_vector(struct vector* v)
    {
        return sqrt(pow((v->point2.self_point.x - v->point1.self_point.x), 2) + pow((v->point2.self_point.y - v->point1.self_point.y), 2) + pow((v->point2.self_point.z - v->point1.self_point.z), 2));
    }
    int* coordinates(struct vector* v)
    {
        int coordinates[3] = { v->point2.self_point.x - v->point1.self_point.x,  v->point2.self_point.y - v->point1.self_point.y, v->point2.self_point.z - v->point1.self_point.z };
        return coordinates;
    }
    float scalar_multiplication(struct vector* v1, struct vector* v2)
    {
        int* coordinates_v1 = v1->coordinates(v1), * coordinates_v2 = v2->coordinates(v2);
        return coordinates_v1[0] * coordinates_v2[0] + coordinates_v1[1] * coordinates_v2[1] + coordinates_v1[2] * coordinates_v2[2];
    }
    
    void print_vector(struct vector* v)
    {
        int* coordinates = v->coordinates(v);
        printf("Вектор %s%s(%d, %d, %d)", v->point1.self_point.name, v->point2.self_point.name, coordinates[0], coordinates[1], coordinates[2]);
    }
};

struct parallelogramm {
    struct vector vector1;
    struct vector vector2;
    void set_parallelogramm(struct parallelogramm* p)
    {
        struct vector vector1, vector2;
        vector1.set_vector(&vector1);
        vector1.set_vector(&vector2);
        p->vector1 = vector1;
        p->vector2 = vector2;
    }
    int perimeter(struct parallelogramm* p)
    {
        return p->vector1.length_vector(&p->vector1) * 2 + p->vector2.length_vector(&p->vector2) * 2;
    }
    float square(struct parallelogramm* p)
    {
        float cosinus, sinus, length_v1 = p->vector1.length_vector(&p->vector1), length_v2 = p->vector2.length_vector(&p->vector2);
        cosinus = p->vector1.scalar_multiplication(&p->vector1, &p->vector2) / (length_v1 * length_v2);
        sinus = sqrt(1 - pow(cosinus, 2));
        return length_v1 * length_v2 * sinus;
    }
    void print_parallelogramm(struct parallelogramm* p)
    {
        p->vector1.print_vector(&p->vector1);
        p->vector2.print_vector(&p->vector2);
    }
};

struct triangle {
    struct colored_point point1;
    struct colored_point point2;
    struct colored_point point3;
    void set_triangle(struct triangle* t)
    {
        t->point1.set_colored_point(&t->point1);
        t->point1.set_colored_point(&t->point2);
        t->point1.set_colored_point(&t->point3);
    }
    int perimeter(struct triangle* t)
    {
        struct vector v1, v2, v3;
        v1.point1 = t->point1;
        v1.point2 = t->point2;
        v2.point1 = t->point2;
        v2.point2 = t->point3;
        v3.point1 = t->point1;
        v3.point2 = t->point3;
        return v1.length_vector(&v1) + v2.length_vector(&v2) + v3.length_vector(&v3);
    }
    float square(struct triangle* t)
    {
        struct vector v1, v2;
        v1.point1 = t->point1;
        v1.point2 = t->point2;
        v2.point1 = t->point2;
        v2.point2 = t->point3;
        float cosinus, sinus, length_v1 = v1.length_vector(&v1), length_v2 = v2.length_vector(&v2);
        cosinus = v1.scalar_multiplication(&v1, &v2) / (length_v1 * length_v2);
        sinus = sqrt(1 - pow(cosinus, 2));
        return length_v1 * length_v2 * sinus / 2;
    }
    void print_triangle(struct triangle* t) 
    {
        t->point1.print_colored_point(&t->point1);
        t->point2.print_colored_point(&t->point2);
        t->point3.print_colored_point(&t->point3);
    }
};

