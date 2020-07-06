# include<iostream>
using namespace std;
# include<string>
# include<vector>
# include<limits.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<vector>
# include<ctype.h>
// 

/*2. 编程实现将整型数值转换为字符串。
char *my_itoa(int value, char *buffer, int radix); 
参数说明：
value：欲转换的数值。
buffer：目标字符串的地址。
radix：转换后的进制数，可以是2进制，10进制、16进制等。
示例： value = 10; radix = 2; string="1010"
不考虑value 为负数。
与函数int sprintf(char *string, char *format ,...);比较，有什么不同；
*/
//除n取余
char*  my_itoa(int value, char* buffer, int radix)
{
	char* stra="0123456789abcdefghijklmnopqrdtuvwxyz";//所以放入数组中的也是字符，不用再转换了
	//char* strb="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if(radix<2 || radix>strlen(stra))
		return "";
	vector<char> temp;
	int c=value;
	int y=0;
	while(c)
	{
		y=c%radix;
		temp.push_back(stra[y]);
		c/=radix;
	}
	int index=0;

	for(int i=temp.size()-1;i>=0;i--)//倒序放进去
	{
		buffer[index++]=temp[i];
	}
	buffer[index]='\0';
	
	return buffer;
}
int main()
{
	char buffer[128]="";
	cout<<"10转换为二进制:"<<my_itoa(10,buffer,2)<<endl;
	cout<<"83转换为八进制:"<<"0"<<my_itoa(83,buffer,8)<<endl;
	cout<<"18转换为九进制:"<<my_itoa(18,buffer,9)<<endl;
	cout<<"161转换为十六进制:"<<"0x"<<my_itoa(161,buffer,16)<<endl;
}
