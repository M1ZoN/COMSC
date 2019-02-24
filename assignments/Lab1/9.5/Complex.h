#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	double realNum;
	double iNum;
public:
	explicit Complex(double = 0.0, double = 0.0);
	Complex add(Complex);
	Complex subtract(Complex);
	void print() const;
};
#endif //  !COMPLEX_H
