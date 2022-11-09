#pragma once

#include <iostream>
using namespace std;

class FormaGeometrica
{
public:
	virtual double getArea(int, int) = 0;

protected:
	float area;
};

