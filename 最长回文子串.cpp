/*15.2020.3.19 ������Ӵ�
����һ��������д��ĸ��Сд��ĸ���ַ������ҵ�ͨ����Щ��ĸ����ɵ���Ļ��Ĵ���
�ڹ�������У���ע�����ִ�Сд������ "Aa" ���ܵ���һ�������ַ�����
ע��:
�����ַ����ĳ��Ȳ��ᳬ�� 1010��
ʾ�� 1: 
����:
"abccccdd"
���:
7
����:
���ǿ��Թ������Ļ��Ĵ���"dccaccd", ���ĳ����� 7��*/ 
//����˼ά
 int longestPalindrome1(string s) 
 {
	 int a[128]={0};//a��A��ASII��
	 int num=0;
	 for(int i=0;i<s.size();i++)
	 {
		 a[s[i]]++;
	 }
	 for(int i=0;i<128;i++)
	 {
		 num=num+(a[i]/2*2);
		 if(a[i]%2==1&&num%2==0)//ֻ��һ��1
		 {
			 num++;
		 }
	 }
	 return num;
 }
 //����˼ά
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

