#include <iostream>

using namespace std;

//Абстрактный класс
class Figure {
public:
	virtual void print();
	virtual int perimeter();
};