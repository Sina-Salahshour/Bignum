#include <iostream>
#include "Bignum.hpp" 

#define OUT(x) cout << x << endl;

using namespace std;

int main()
{
	Bignum bn1 = "1000000";
	Bignum bn2 = "1";
	OUT(bn1+bn2);
	return 0;
}