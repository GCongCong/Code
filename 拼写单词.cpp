/*13 2020.3.17  ƴд����   
����һ�ݡ��ʻ�����ַ������飩 words ��һ�š���ĸ�����ַ����� chars��

����������� chars �еġ���ĸ�����ַ���ƴд�� words �е�ĳ�������ʡ����ַ���������ô���Ǿ���Ϊ��������������ʡ�
ע�⣺ÿ��ƴдʱ��chars �е�ÿ����ĸ��ֻ����һ�Ρ�
���شʻ�� words �������յ����е��ʵ� ����֮�͡�
ʾ�� 1��
���룺words = ["cat","bt","hat","tree"], chars = "atach"
�����6
���ͣ� 
�����γ��ַ��� "cat" �� "hat"�����Դ��� 3 + 3 = 6��
ʾ�� 2��
���룺words = ["hello","world","leetcode"], chars = "welldonehoneyr"
�����10
���ͣ�
�����γ��ַ��� "hello" �� "world"�����Դ��� 5 + 5 = 10��*/

int countCharacters(vector<string>& words, string chars) 
{
	int c[26]={0};
	int count=0;
	int fin=0;
	for(int i=0;i<chars.size();i++)
	{
		c[chars[i]-'a']+=1;
	}
	for(string s:words)
	{
		
		int temp[26]={0};
		for(int i=0;i<s.length();i++)
		{
			temp[s[i]-'a']+=1;
			if(c[s[i]-'a']>=temp[s[i]-'a'])
			{
				count++;
			}
			else
			{
				count=0;
				break;

			}
			
			
		}
		fin+=count;
		count=0;
	}
	return fin;
}
int main()
{
	vector<string>words;
	string chars="atach";
	words.push_back("cat");
	words.push_back("hat");
	words.push_back("tree");
	cout<<countCharacters(words,chars);
}
