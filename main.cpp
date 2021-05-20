#include <iostream>
#include "Bignum.hpp" 

#define OUT(x) cout << x << endl;

using namespace std;
void operator| (Bignum& bnl, Bignum& bnr)
{
	Bignum tmp = bnl;
	bnl = bnr;
	bnr = tmp;
}

int main()
{
	Bignum bn1;
	Bignum bn2;

	cin >> bn1;
	cin >> bn2;
	OUT(bn1-bn2);
	return 0;
}