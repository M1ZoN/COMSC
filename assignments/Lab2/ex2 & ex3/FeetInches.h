#ifndef FEETINCHES_H
#define FEETINCHES_H
#include<iostream>

class FeetInches
{
private:
    int feet;
    int inches;
public:
    explicit FeetInches(int = 0, int = 0);
    void setFeet(const int);
    void setInches(const int);
    int getFeet();
    int getInches();
    void simplify();
    FeetInches operator+(const FeetInches &)const;
    FeetInches operator-(const FeetInches &)const;
    bool operator<=(const FeetInches &)const;
    bool operator>=(const FeetInches &)const;
    bool operator!=(const FeetInches &)const;
    bool operator==(const FeetInches &)const;
    friend std::ostream &operator<<(std::ostream &, const FeetInches &);
    friend std::istream &operator>>(std::istream &, FeetInches &);
};

#endif