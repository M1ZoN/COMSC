#include<iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex c1(10,-3);
    Complex c2;

    cout<<"Imaginary numbers program."<<endl;
    cout<<"Complex number with '<<' operator: "<<c1<<endl;
    cout<<"Now let's try with '>>' operator."<<endl;
    cin>>c2;
    cout<<"Here is your complex number with '<<' operator: "<<c2<<endl;
    cout<<"Now let's check them on equality."<<endl;
    cout<<"Performing '==' on "<<c1<<" and "<<c2<<endl;
    cout<<"Result: "<<(c1==c2)<<endl;
    cout<<"Performing '!=' on "<<c1<<" and "<<c2<<endl;
    cout<<"Result: "<<(c1!=c2)<<endl;
    cout<<"Good Bye!"<<endl;
}