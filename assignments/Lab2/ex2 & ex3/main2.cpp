#include<iostream>
#include "FeetInches.h"

using namespace std;

int main()
{
	FeetInches f1;
	FeetInches f3;
	int num;

	cout<<"FeetInches Problem."<<endl;
	cout<<"Setting the values of 2st variable, input the feet part:";
	cin>>num;
	f1.setFeet(num);
	cout<<"Setting the values of 2st variable, input the inches part:";
	cin>>num;
	f1.setInches(num);
	cout<<"The other values will be set with constructor: (1,10)"<<endl;
	FeetInches f2(1,10);
	cout<<"The values of 2nd variable, feet: "<<f2.getFeet()<<", inches: "<<f2.getInches()<<endl;
	cout<<"Performing addition: ("<<f1.getFeet()<<","<<f1.getInches()<<") + ("<<f2.getFeet()<<","<<f2.getInches()<<")"<<endl;
	f3 = f1+f2;
	cout<<"The answer is: ("<<f3.getFeet()<<","<<f3.getInches()<<")"<<endl;
	cout<<"Performing simplify of: ("<<f3.getFeet()<<","<<f3.getInches()<<")"<<endl;
	f3.simplify();
	cout<<"The answer is: ("<<f3.getFeet()<<","<<f3.getInches()<<")"<<endl;
	cout<<"Performing subtruction: ("<<f1.getFeet()<<","<<f1.getInches()<<") - ("<<f2.getFeet()<<","<<f2.getInches()<<")"<<endl;
	f3 = f1-f2;
	cout<<"The answer is: ("<<f3.getFeet()<<","<<f3.getInches()<<")"<<endl;
	cout<<"--------------------------------------------------------"<<endl;
	cout<<"Now lets use operators '<<' and '>>'"<<endl;
	cout<<"First Variable:"<<endl;
	cin>>f1;
	cout<<"Second Variable:"<<endl;
	cin>>f2;
	cout<<"First Variable:"<<f1<<endl;
	cout<<"Second Variable:"<<f2<<endl;
	cout<<f1<<" != "<<f2<< " ===> "<<(f1!=f2)<<endl;
	cout<<f1<<" <= "<<f2<< " ===> "<<(f1<=f2)<<endl;
	cout<<f1<<" >= "<<f2<< " ===> "<<(f1>=f2)<<endl;
}