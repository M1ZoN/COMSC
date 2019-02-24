#include "Complex.h"
#include <iostream>

using namespace std;

int main()
{
	Complex a(5.5, -6.3);
	Complex b(8.8, 3.3);
	Complex c;

	cout << "Complex Number Program" << endl;
	cout << "a = ";
	a.print();
	cout << "b = ";
	b.print();
	cout << "c = ";
	c.print();

	cout << "Performing an operation : c = a + b" << endl;
	c = a.add(b);
	cout << "c = ";
	c.print();
	cout << "Performing an operation : c = a - b" << endl;
	c = a.subtract(b);
	cout << "c = ";
	c.print();
	return (0);
}