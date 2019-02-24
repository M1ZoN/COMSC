#include <iostream>
#include "FeetInches.h"
using namespace std;

FeetInches::FeetInches( int f, int i ) 
   : feet( f ),
   inches( i ) 
{ 
// empty body
} // end Complex constructor

void FeetInches::setFeet(const int f)
{
    feet = f;
}

void FeetInches::setInches(const int i)
{
    inches = i;
}

int FeetInches::getFeet()
{
    return feet;
}

int FeetInches::getInches()
{
    return inches;
}

void FeetInches::simplify()
{
	feet += inches/12;
    inches %= 12;
    if (inches < 0 && inches > -12)
    {
        feet--;
        inches = 12 + inches;
    }
}

FeetInches FeetInches::operator+( const FeetInches &operand2 ) const
{
   return FeetInches( feet + operand2.feet, 
      inches + operand2.inches );
} // end function operator+

// subtraction operator
FeetInches FeetInches::operator-( const FeetInches &operand2 ) const
{
   return FeetInches( feet - operand2.feet, 
      inches - operand2.inches );
} // end function operator-

ostream &operator<<( ostream &output, const FeetInches &obj)
{
    output << "( " << obj.feet << ", " << obj.inches << " )";
    return output;
}

istream &operator >> ( istream &input, FeetInches &obj)
{
    cout << "Please enter the Feet: ";
    input >> obj.feet;
    cout << "Now enter the Inches: ";
    input >> obj.inches;
    return input;
}

bool FeetInches::operator==(const FeetInches &operand2) const
{
    if (feet == operand2.feet && inches == operand2.inches)
        return true;
    else
        return false;
}

bool FeetInches::operator!=(const FeetInches &operand2) const
{
    return !(*this == operand2);
}

bool FeetInches::operator <=(const FeetInches &operand2) const
{

    if ((feet * 12 + inches) <= (operand2.feet * 12 + operand2.inches))
        return true;
    else
        return false;
}

bool FeetInches::operator >=(const FeetInches &operand2) const
{
    if ((feet * 12 + inches) >= (operand2.feet * 12 + operand2.inches))
        return true;
    else
        return false;
}