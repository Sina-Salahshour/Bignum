#include <iostream>
#include "Bignum.hpp" 

#define OUT(x) cout << x << endl;

using namespace std;

int main()
{
	Bignum bn1 = "-1";
	Bignum bn2 = "-1";
	OUT(bn2*bn1);
	return 0;
}