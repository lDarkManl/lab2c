#pragma once

#include "Point.cpp"

using namespace std;

template <typename Color>
class ColoredPoint : Point {
    Color color;

public:
    ColoredPoint() {}

    ColoredPoint(int x, int y, int z, string name, Color color);

    void printPoint();

    void setColor(string color);

    string getColor();
};