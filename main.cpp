#include <iostream> 
#define OUT(x) cout << x << endl;
using namespace std;
string numadd(string num1, string num2)
{
	const string one = "1";
	string * bignum;
	string * smallnum;
	string finalresult;
	bool addition=false;
	int currentsum=0;
	if (num1.length() > num2.length()) {bignum = &num1; smallnum = &num2;} else {bignum = &num2; smallnum = &num1;}
	char result[bignum->length()];
	for(int i=0;i<smallnum->length();i++)
	{
		currentsum=(int)(bignum[0][bignum->length()-i-1]) + (int)(smallnum[0][smallnum->length()-i-1]) -48;
		if (addition) 
		{
			addition = false;
			currentsum += 1;
		}
		if (currentsum >= 58) {addition = true; currentsum -=10; }
			result[bignum->length()-i-1] = (char)currentsum;
	}
	for(int i=0;i<(bignum->length()-smallnum->length());i++)
	{
		if(addition)
		{
			addition=false;
			currentsum=(int)(bignum[0][bignum->length()-smallnum->length()-i-1])+1;
			OUT((char)currentsum)
			result[bignum->length()-smallnum->length()-i-1]=(char)currentsum;
		}else
		{
			result[bignum->length()-smallnum->length()-i-1]=bignum[0][bignum->length()-smallnum->length()-i-1];
		}
	}
	if(addition)
		finalresult = one + result;
	else
		finalresult = result;
	return finalresult;
}
int main()
{
	string big1;
	string big2;
	cin >> big1;
	cin >> big2;
	OUT(numadd(big1,big2))
	return 0;
}