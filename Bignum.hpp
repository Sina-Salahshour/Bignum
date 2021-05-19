#include <iostream>
class Bignum
{
private:
    std::string numadd(std::string num1, std::string num2)
{
	std::string * bignum;
	std::string * smallnum;
	if (num1.length() > num2.length()) {bignum = &num1; smallnum = &num2;} else {bignum = &num2; smallnum = &num1;}
	bool addition=false;
	int currentsum=0;
	const std::string one = "1";
    const int blength = bignum->length();
    const int slength = smallnum->length();
    std::string result = std::string(blength,'0');
	for(int i=0;i<slength;i++)
	{
		currentsum=(int)(bignum[0][blength-i-1]) + (int)(smallnum[0][slength-i-1]) -48;
		if (addition) 
		{
			addition = false;
			currentsum += 1;
		}
		if (currentsum >= 58) {addition = true; currentsum -=10; }
		result[blength-i-1] = (char)currentsum;
	}
	for(int i=0;i<(blength-slength);i++)
	{
		if(addition)
		{
			addition=false;
			currentsum=(int)(bignum[0][blength-slength-i-1])+1;
		if (currentsum >= 58) {addition = true; currentsum -=10; }
			result[blength-slength-i-1]=(char)currentsum;
		}else
		{
			result[blength-slength-i-1]=bignum[0][blength-slength-i-1];
		}
	}
	if(addition)
		result = one + result;
	else
        result = result;
	return result;
}
    const char pos{'+'};
    const char neg{'-'};
    std::string value;
    char sign;
public:
    Bignum()
    {
    value = "0";
    sign = neg;
    }
    Bignum(const char * input)
    {
        this->value = input;
        this->sign = pos;
    }
    Bignum(std::string input)
    {
        this->value = input;
        this->sign = pos;
    }
    Bignum operator = (const Bignum input)
    {
        this->value = input.value;
        return *this;
    }
    Bignum operator + (Bignum input)
    {
        return Bignum(this->numadd(this->value , input.value));
    }
    friend std::istream& operator >> (std::istream& in , Bignum& num)
    {
        std::string temp;
        in >> temp;
        num.value = temp;
        return in;
    }
    friend std::ostream& operator << (std::ostream& out , Bignum num)
    {
        out << num.value;
        return out;
    }
};

