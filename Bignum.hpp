#include <iostream>
using std::string;
class Bignum
{
private:
bool signchanged = false;
    char signmult(char s1, char s2)
    {
        char result;
        s1==s2 ? result='+':result='-';
        return result;
    }
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
    string nummult(string nums1, string nums2) {
   int n = nums1.size();
   int m = nums2.size();
   string ans(n + m, '0');
   for(int i = n - 1; i>=0; i--){
      for(int j = m - 1; j >= 0; j--){
         int p = (nums1[i] - '0') * (nums2[j] - '0') + (ans[i + j + 1] - '0');
         ans[i+j+1] = p % 10 + '0';
         ans[i+j] += p / 10 ;
      }
   }
   for(int i = 0; i < m + n; i++){
      if(ans[i] !='0')return ans.substr(i);
   }
   return "0";
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
        string temp = input;
        if(temp[0] != '-')
        {
            if(temp[0] != '+')
            {
            this->value = temp;
            this->sign = pos;
            }else
            {
                this->value = temp.substr(1,-1);
                this->sign = pos;
            }
        }else{
            this->value = temp.substr(1,-1);
            this->sign = neg;
        }
    }
    Bignum(string input)
    {
        if(input[0] != '-')
        {
            if(input[0] != '+')
            {
            this->value = input;
            this->sign = pos;
            }else
            {
                this->value = input.substr(1,-1);
                this->sign = pos;
            }
        }else{
            this->value = input.substr(1,-1);
            this->sign = neg;
        }
    }
    Bignum(string input,char sn)
    {
        this->value = input;
        this->sign = sn;
    }
    bool operator == (Bignum input)
    {
        if(this->value == input.value && this->sign == input.sign)
        return true;
        return false;
    }
    bool operator != (Bignum input)
    {
        if(this->value == input.value && this->sign == input.sign)
        return false;
        return true;
    }
    Bignum operator = (const Bignum input)
    {
        this->value = input.value;
        this->sign = input.sign;
        return *this;
    }
    Bignum operator = (const string input)
    {
        if(input[0] != '-')
        {
            if(input[0] != '+')
            {
            this->value = input;
            this->sign = pos;
            }else
            {
                this->value = input.substr(1,-1);
                this->sign = pos;
            }
        }else{
            this->value = input.substr(1,-1);
            this->sign = neg;
        }
        return *this;
    }
    Bignum operator * (Bignum input)
    {
        Bignum bn;
        bn.value=bn.nummult(this->value,input.value);
        remzeros(bn.value);
        bn.sign=signmult(input.sign,this->sign);
        if (bn.value == "0") bn.sign = '+';
        return bn;
    }
    Bignum operator + (Bignum input)
    {   
        Bignum bn;
        if(input.sign == this->sign)
        {
        bn.value=bn.numadd(this->value , input.value);
        bn.sign=input.sign;
        }else if (input.sign == '-')
        {
        bn.value=bn.numsub(this->value,input.value);
        signchanged =false;
        }else
        {
        bn.value=bn.numsub(input.value,this->value);
        signchanged =false;
        }
        remzeros(bn.value);
        if (bn.value == "0") bn.sign = '+';
        return bn;
    }
    Bignum operator - (Bignum input)
    {
        Bignum bn;
        if(input.sign==this->sign)
        {
        bn.sign=input.sign;
        bn.value=bn.numsub(this->value,input.value);
        signchanged =false;
        }else if (input.sign == '-')
        {
            bn.value=bn.numadd(this->value , input.value);
            bn.sign = pos;
        }else
        {
            bn.value=bn.numadd(this->value , input.value);
            bn.sign = neg;
        }
        remzeros(bn.value);
        if (bn.value == "0") bn.sign = '+';
        return bn;
    }
    friend std::istream& operator >> (std::istream& in , Bignum& num)
    {
        string temp;
        in >> temp;
        if(temp[0] != '-')
        {
            if(temp[0] != '+')
            {
            num.value = temp;
            num.sign = num.pos;
            }else
            {
                num.value = temp.substr(1,-1);
                num.sign = num.pos;
            }
        }else{
            num.value = temp.substr(1,-1);
            num.sign = num.neg;
        }

        // num.value = temp;
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