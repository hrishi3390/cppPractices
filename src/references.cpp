//============================================================================
// Name        : references.cpp
// Author      : Hrishikesh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
/*referece
 * so basically in reference, tumko jo aya function paramter me .. wahi return karnah
 * reference jab bhej rhe h then we have already assigned it to some object elsewhere
 * hence we need to return what is already assign or initialize
 * In below example, i m returning a reference of int, means it must have refereneced
 * somewhere. so a ko value already main function me de rakha h
 * reference means duplicate, alias. just name is different but same memory location
 *
 */
int& sum(int &a){
	a +=8;
	return a;
}

class complex{
	double re;
	double img;

public:
	complex(double r, double i):re{r}, img{i}{

	}

	/* In below function, returning complex ka reference. means we already have the memory
	 * allocated to complex object and need to return that. so it means we are just
	 * returning the copy of complex object. Now += operator is invoked on c object and c1
	 * is sent as reference to this function. hence we are returning the same object c
	 * hence here we have just used *this. this is basically a pointer. hence *this returns
	 * the original object of complex
	 */

	complex& operator +=(complex &num){
		re+=num.re;
		img+=num.img;
		return *this;
	}

	/*
	 * In below function, we are saying that, the operator<< can only access the private
	 * variable of this class. When I consider someone as friend. then he will know my
	 * secrets as well. otherway around is not possible. Hence making friends should be
	 * very selective :P
	 * now this function to return the reference cout which is passed to it as parameter
	 * hence memory for cout is already created somewhere we just need to return it as it
	 * is
	 */

	 friend ostream & operator<<( ostream &cout, const complex &D ) {
	         cout<< D.re << " +i" << D.img;
	         return cout;
	      }

};

int main() {

	complex c(4.3, .04);
	complex c1(4.3, .04);

	c +=c1;

	cout<<c;


	return 0;
}
