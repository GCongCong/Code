/*13 2020.3.17  拼写单词   
给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。
注意：每次拼写时，chars 中的每个字母都只能用一次。
返回词汇表 words 中你掌握的所有单词的 长度之和。
示例 1：
输入：words = ["cat","bt","hat","tree"], chars = "atach"
输出：6
解释： 
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
示例 2：
输入：words = ["hello","world","leetcode"], chars = "welldonehoneyr"
输出：10
解释：
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。*/

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
