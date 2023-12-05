#include <iostream>
#include <windows.h>
#include <format>
#include <windows.h>
#include <cmath>
#include "Point.cpp"

using namespace std;

//������������
template <typename Color>
class ColoredPoint : Point {
    //���� ����� ���� hex, string ��� ������ �������
	Color color;

public:
    ColoredPoint() {}

    ColoredPoint(int x, int y, int z, string name, Color color) {
        Point(x, y, z, name);
        this->color = color;
    }

    void printPoint() {
        Point:printPoint();
        cout << "����: " << color << endl;
    }

    void setColor(string color)
    {
        this->color = color;
    }

    string getColor()
    {
        return this->color;
    }
};