#include <iostream>
#include <windows.h>
#include <format>
#include <windows.h>
#include <cmath>

using namespace std;

class Point {
private:
    int x, y, z;
    string name;
    //������� ���������� �������� - ����������� ����������
    static int count;
public:
    Point() {
        count++;
    }

    Point(int x, int y, int z, string name) {
        count++;
        this->x = x;
        this->y = y;
        this->z = z;
        this->name = name;
    }
    //����������� ����� - ����� ������� ������ �����
    static void printFormat() {
        cout << "����� <�������� �����>(x, y, z)" << endl;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getZ() {
        return z;
    }

    string getName() {
        return name;
    }

    void printPoint() {
        cout << "����� " << name << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
    //���������� ��������� +
    Point operator +(Point point) {
        return Point(this->x + point.getX(), this->y + point.getY(), this->z + point.getZ(), this->name + point.getName());
    }
};