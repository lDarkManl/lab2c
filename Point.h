#pragma once

class Point {
private:
    int x, y, z;
    string name;
    static int count;
public:
    Point();

    Point(int x, int y, int z, string name);

    static void printFormat();

    int getX();

    int getY();

    int getZ();

    string getName();

    void printPoint();

    Point operator +(Point point);
};