#include <iostream>
#include <windows.h>
#include <math.h>
#include <format>
#include <windows.h>
using namespace std;

class Point {
public:
	int x, y, z;
	string name;
    Point()
    {
        string name;
        int x, y, z;
        cout << "Введите название точки: ";
        cin >> name;
        cout << "Введите координаты точки: ";
        cin >> x >> y >> z;
        this->name = name;
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void print_point()
    {
        cout << this->name << this->x << this->y << this->z;
    }
};

class ColoredPoint : public Point {
public:
    string color;
    ColoredPoint()
    {
        cout << "Введите цвет: ";
        cin >> color;
    }
    void print_point()
    {
        Point::print_point();
        cout << "Цвет: " << color;
    }
};

class Vector {
public:
    ColoredPoint point1;
    ColoredPoint point2;
    float length_vector()
    {
        return sqrt(pow((this->point2.x - this->point1.x), 2) + pow((this->point2.y - this->point1.y), 2) + pow((this->point2.z - this->point1.z), 2));
    }
    int* coordinates()
    {
        int coordinates[3] = { this->point2.x - this->point1.x,  this->point2.y - this->point1.y, this->point2.z - this->point1.z };
        return coordinates;
    }
    float scalar_multiplication(Vector* v2)
    {
        int* coordinates_v1 = this->coordinates(), *coordinates_v2 = v2->coordinates();
        return coordinates_v1[0] * coordinates_v2[0] + coordinates_v1[1] * coordinates_v2[1] + coordinates_v1[2] * coordinates_v2[2];
    }

    void print_vector()
    {
        int* coordinates = this->coordinates();
        cout << "Вектор ", std::format("{}{}({}{}{})", this->point1.name, this->point2.name, coordinates[0], coordinates[1], coordinates[2]) ;
    }
};

class Parallelogramm {
public:
    Vector vector1;
    Vector vector2;
    int perimeter()
    {
        return this->vector1.length_vector() * 2 + this->vector2.length_vector() * 2;
    }
    float square()
    {
        float cosinus, sinus, length_v1 = this->vector1.length_vector(), length_v2 = this->vector2.length_vector();
        cosinus = this->vector1.scalar_multiplication(&this->vector2) / (length_v1 * length_v2);
        sinus = sqrt(1 - pow(cosinus, 2));
        return length_v1 * length_v2 * sinus;
    }
    void print_parallelogramm()
    {
        this->vector1.print_vector();
        this->vector2.print_vector();
    }
};

class Triangle {
public:
    ColoredPoint point1;
    ColoredPoint point2;
    ColoredPoint point3;
    int perimeter()
    {
        Vector v1, v2, v3;
        v1.point1 = this->point1;
        v1.point2 = this->point2;
        v2.point1 = this->point2;
        v2.point2 = this->point3;
        v3.point1 = this->point1;
        v3.point2 = this->point3;
        return v1.length_vector() + v2.length_vector() + v3.length_vector();
    }
    float square()
    {
        Vector v1, v2;
        v1.point1 = this->point1;
        v1.point2 = this->point2;
        v2.point1 = this->point2;
        v2.point2 = this->point3;
        float cosinus, sinus, length_v1 = v1.length_vector(), length_v2 = v2.length_vector();
        cosinus = v1.scalar_multiplication(&v2) / (length_v1 * length_v2);
        sinus = sqrt(1 - pow(cosinus, 2));
        return length_v1 * length_v2 * sinus / 2;
    }
    void print_triangle()
    {
        this->point1.print_point();
        this->point2.print_point();
        this->point3.print_point();
    }
};

