/*12.2020.3.16  �ӷ���ѹ��
�ַ���ѹ���������ַ��ظ����ֵĴ�������дһ�ַ�����ʵ�ֻ������ַ���ѹ�����ܡ����磬�ַ���aabcccccaaa���Ϊa2b1c5a3��
����ѹ��������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ���������Լ����ַ�����ֻ������СдӢ����ĸ��a��z����
 ʾ��1:
 ���룺"aabcccccaaa"
 �����"a2b1c5a3"
 ʾ��2:
 ���룺"abbccd"
 �����"abbccd"
 ���ͣ�"abbccd"ѹ����Ϊ"a1b2c2d1"����ԭ�ַ������ȸ�����*/ 
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
			t+=S[i]+to_string(count);//������ת��Ϊ�ַ���
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
