8.2020.3.12    �ӷ������������    
�����ַ��� S �� T��ֻ���� S = T + ... + T��T ���������� 1 �λ��Σ�ʱ�����ǲ��϶� ��T �ܳ��� S����
������ַ��� X��Ҫ������ X �ܳ��� str1 �� X �ܳ��� str2��
ʾ�� 1��
���룺str1 = "ABCABC", str2 = "ABC"
�����"ABC"
ʾ�� 2��
���룺str1 = "ABABAB", str2 = "ABAB"
�����"AB"
ʾ�� 3��
���룺str1 = "LEET", str2 = "CODE"
�����""
//1.��ٷ�
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
//2.����ŷ����ù�ʽ�����Լ����Ȼ����鼴��
string gcdOfStrings1(string str1, string str2) 
{
	int len1=str1.length();
	int len2=str2.length();
	int len=min(len1,len2);
	string s=str1.substr(0, gcd(len1,len2));//c++17��֧��
	if(check(s,str1)&&check(s,str2))
	{
				return s;
	}
	return "";	
}
//3.ŷ����ü���ѧ˼ά
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
