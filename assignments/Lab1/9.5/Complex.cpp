#include "Complex.h"
#include <iostream>
using namespace std;

Complex::Complex(double r, double i)
{
	realNum = r;
	iNum = i;
}

Complex Complex::add(Complex obj)
{
	Complex temp;
	temp.realNum = realNum + obj.realNum;
	temp.iNum = iNum + obj.iNum;
	return temp;
}

Complex Complex::subtract(Complex obj)
{
	Complex temp;
	temp.realNum = realNum - obj.realNum;
	temp.iNum = iNum - obj.iNum;
	return temp;
}

void Complex::print() const
{
	cout << "(" << realNum << ", " << iNum << ")" << endl;
}
