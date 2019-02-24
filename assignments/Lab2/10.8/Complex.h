// Fig. 10.14: Complex.h
// Complex class definition.
#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>

class Complex
{
public:
    explicit Complex( double = 0.0, double = 0.0 ); // constructor
    Complex operator+( const Complex & ) const; // addition
    Complex operator-( const Complex & ) const; // subtraction
    void print() const; // output
    friend std::ostream &operator<<(std::ostream &, const Complex &);
    friend std::istream &operator>>(std::istream &, Complex &);
    bool operator == (const Complex &) const;
    bool operator != (const Complex &) const;
private:
    double real; // real part
    double imaginary; // imaginary part
}; // end class Complex

#endif