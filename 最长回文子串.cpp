/*15.2020.3.19 最长回文子串
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
注意:
假设字符串的长度不会超过 1010。
示例 1: 
输入:
"abccccdd"
输出:
7
解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。*/ 
//正向思维
 int longestPalindrome1(string s) 
 {
	 int a[128]={0};//a和A的ASII码
	 int num=0;
	 for(int i=0;i<s.size();i++)
	 {
		 a[s[i]]++;
	 }
	 for(int i=0;i<128;i++)
	 {
		 num=num+(a[i]/2*2);
		 if(a[i]%2==1&&num%2==0)//只加一次1
		 {
			 num++;
		 }
	 }
	 return num;
 }
 //反向思维
 int longestPalindrome(string s)
 {
	 unordered_map<char,int>hash;
	 int count=0;
	 int len=s.size();
	 for(int i=0;i<s.size();i++)
	 {
		 hash[s[i]]++;
	 }
	 for(auto i:hash)
	 {
		 if(i.second%2==1)
		 {
			 count++;
		 }
	 }
	 return count==0?len:len-count+1;
 }
 int main()
 {
	 string s="abccccdd";
	 cout<<longestPalindrome(s); 
 }

