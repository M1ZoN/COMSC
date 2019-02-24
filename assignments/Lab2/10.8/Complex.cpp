// Fig. 10.15: Complex.cpp
// Complex class member-function definitions.
#include <iostream>
#include "Complex.h" // Complex class definition
using namespace std;

// Constructor
Complex::Complex( double realPart, double imaginaryPart ) 
   : real( realPart ),
   imaginary( imaginaryPart ) 
{ 
   // empty body
} // end Complex constructor

// addition operator
Complex Complex::operator+( const Complex &operand2 ) const
{
   return Complex( real + operand2.real, 
      imaginary + operand2.imaginary );
} // end function operator+

// subtraction operator
Complex Complex::operator-( const Complex &operand2 ) const
{
   return Complex( real - operand2.real, 
      imaginary - operand2.imaginary );
} // end function operator-

// display a Complex object in the form: (a, b)
void Complex::print() const
{ 
   cout << '(' << real << ", " << imaginary << ')';
} // end function print

ostream &operator<<( ostream &output, const Complex &obj)
{
    output << "( " << obj.real << ", " << obj.imaginary << " )";
    return output;
}

istream &operator >> ( istream &input, Complex &obj)
{
    cout << "Please enter the real part: ";
    input >> obj.real;
    cout << "Now enter the imaginary part: ";
    input >> obj.imaginary;
    return input;
}

bool Complex::operator==(const Complex &operand2) const
{
    if (real == operand2.real && imaginary == operand2.imaginary)
        return true;
    else
        return false;
}

bool Complex::operator!=(const Complex &operand2) const
{
    return !(*this == operand2);
}