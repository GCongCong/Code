8.2020.3.12    子符串的最大因子    
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。
示例 1：
输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"
示例 2：
输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"
示例 3：
输入：str1 = "LEET", str2 = "CODE"
输出：""
//1.穷举法
bool check(string s,string t)
{
	int count=t.length()/s.length();
	string temp="";
	for(int i=0;i<count;i++)
	{
		temp+=s;
		if(temp==t)
		{
			return true;
		}
	}
	return false;

}
string gcdOfStrings(string str1, string str2) 
{
	int len1=str1.length();
	int len2=str2.length();
	int len=min(len1,len2);
	for(len;len>0;len--)
	{
		if(len1%len==0&&len2%len==0)
		{
			string s=str1.substr(0,len);
			if(check(s,str1)&&check(s,str2))
			{
				return s;
			}
		}
	}
	return "";	
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
//2.引入欧几里得公式求最大公约数，然后检验即可
string gcdOfStrings1(string str1, string str2) 
{
	int len1=str1.length();
	int len2=str2.length();
	int len=min(len1,len2);
	string s=str1.substr(0, gcd(len1,len2));//c++17才支持
	if(check(s,str1)&&check(s,str2))
	{
				return s;
	}
	return "";	
}
//3.欧几里得加数学思维
string gcdOfStrings2(string str1, string str2) 
{
	if(str1+str2!=str2+str1) return "";
	return str1.substr(0,gcd(str1.length(),str2.length()));
}
int main()
{
	string str1="ABABAB";
	string str2="ABAB";
	cout<<gcdOfStrings2(str1,str2)<<endl; 
}
