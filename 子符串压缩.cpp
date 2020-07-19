/*12.2020.3.16  子符串压缩
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。
若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。
 示例1:
 输入："aabcccccaaa"
 输出："a2b1c5a3"
 示例2:
 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。*/ 
string compressString(string S) 
{
	string t="";
	int count=1;
	for(int i=0,j=1;i<S.length();)
	{
		if(S[i]==S[j])
		{
			count++;
			j++;
		}
		else
		{
			t+=S[i]+to_string(count);//把数字转换为字符串
			i=j;
			j++;
			//temp=S[i];
			count=1;
		}
	}
	if(t.length()<S.length())
	{
		return t;
	}
	return S;
}
int main()
{
	string s="aabbbccccd";
	cout<<compressString(s);
}
