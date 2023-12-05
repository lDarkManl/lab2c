#pragma once

//Абстрактный класс
class Figure {
private:
	string color;
public:
	virtual void print();
	virtual int perimeter();
};