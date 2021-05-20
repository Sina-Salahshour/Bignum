#include <iostream>
using std::string;
class Bignum
{
private:
bool signchanged = false;
void changesign()
{
    if (!signchanged)
    {
    sign == pos ? sign = neg : sign = pos;
    signchanged = true;
    }
}
    void remzeros(string &input)
    {
        while (input[0]=='0')
        {
            input = input.substr(1,-1);
        }
        if(input == "")
        input="0";
        
    }
    string invertnum(string num)
    {
        string result="";
        for(char digit:num)
        {
            result += (105-digit);
        }
        return result;
    }
    string numadd(string num1, string num2)
{
	string * bignum;
	string * smallnum;
	if (num1.length() > num2.length()) {bignum = &num1; smallnum = &num2;} else {bignum = &num2; smallnum = &num1;}
	bool addition=false;
	int currentsum=0;
	const string one = "1";
    const int blength = bignum->length();
    const int slength = smallnum->length();
    string result = string(blength,'0');
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
    //     while (result[0]=='0')
    // {
    //     result = result.substr(1,-1);
    // }
	return result;
}
    string numsub(string num1, string num2)
    {
	string * bignum;
	string * smallnum;
	if (num1.length() != num2.length())
    {
        if (num1.length() < num2.length())
        {bignum=&num2; smallnum = &num1;changesign();}
        else
        {bignum=&num1; smallnum = &num2;}
    }else
    {
        {bignum=&num1; smallnum = &num2;}
    }
    string ibignum = invertnum(*bignum);
    string result = numadd(ibignum,*smallnum);
    const int blength = bignum->length();
    if(result.length() > blength)
    {
        changesign();
        string tmp1="0";
        string tmp2;
        for(int i=0;i<=result.length()-bignum->length();i++)
        {
            tmp2=result[i];
            tmp1=numadd(tmp1,tmp2);

        }
        tmp1+=string(blength-1,'0');
        tmp2=result.substr(result.length()-blength+1,-1);
        tmp2=invertnum(tmp2);
        result=numsub(tmp1,tmp2);
    }else
    result = invertnum(result);
    return result;
    }
    string value;
    const char pos{'+'};
    const char neg{'-'};
    char sign;
public:
    Bignum()
    {
    value = "0";
    sign = pos;
    }
    Bignum(const char * input)
    {
        this->value = input;
        this->sign = pos;
    }
    Bignum(string input)
    {
        this->value = input;
        this->sign = pos;
    }
    Bignum(string input,char sn)
    {
        this->value = input;
        this->sign = sn;
    }
    Bignum operator = (const Bignum input)
    {
        this->value = input.value;
        return *this;
    }
    Bignum operator + (Bignum input)
    {   
        Bignum bn;
        bn.value=bn.numadd(this->value , input.value);
        remzeros(bn.value);
        return bn;
    }
    Bignum operator - (Bignum input)
    {
        Bignum bn;
        bn.value=bn.numsub(this->value,input.value);
        signchanged =false;
        remzeros(bn.value);
        if (bn.value == "0") bn.sign = '+';
        return bn;
    }
    friend std::istream& operator >> (std::istream& in , Bignum& num)
    {
        string temp;
        in >> temp;
        num.value = temp;
        return in;
    }
    friend std::ostream& operator << (std::ostream& out , Bignum num)
    {
        if (num.sign=='-')
        {
            string result = "-" + num.value;
            out << result;
        }
        else
        out << num.value;
        return out;
    }
};