#include <iostream>
class Bignum
{
private:
    std::string numadd(std::string num1, std::string num2)
{
	const std::string one = "1";
	std::string * bignum;
	std::string * smallnum;
	std::string finalresult;
	bool addition=false;
	int currentsum=0;
	if (num1.length() > num2.length()) {bignum = &num1; smallnum = &num2;} else {bignum = &num2; smallnum = &num1;}
	char result[bignum->length()-1];
    // std::string result = std::string(bignum->length()-1 ,'0');
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
		if (currentsum >= 58) {addition = true; currentsum -=10; }
			result[bignum->length()-smallnum->length()-i-1]=(char)currentsum;
		}else
		{
			result[bignum->length()-smallnum->length()-i-1]=bignum[0][bignum->length()-smallnum->length()-i-1];
		}
	}
	if(addition)
		finalresult = one + ((std::string)result).substr(0,bignum->length());
	else
		finalresult = ((std::string)result).substr(0,bignum->length());;
	return finalresult;
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

