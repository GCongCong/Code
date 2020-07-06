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
/*1.编程实现将字符串转换为整型数；
int  my_atoi(const char *str);
1.遇到非数字字母，停止转换；【if处理】
示例： str = "234.324" ; 返回值是234；
2.首先出现空格的字符串可以转换，转换开始后，遇到空格停止转换；【index跳过空格】
示例: str ="    342 456"; 返回值是342；
3.可以处理正负号；,+号ASCII为43，-号为45【flag标志位处理】
示例： str = "    +234.bad" ; 返回值是 234； str ="   -342ab.234" ; 返回值是：-342；
4.可以处理八进制，和十六进制；f-a=5,f在十六进制表示15，所以应为f-'a'+10
示例： str = "  +0xff";  返回值是 255；    str = " 0123" ;  返回值是 83；
5 可以处理int 型溢出的情况；
示例； str = "567898765678987656789"; str = 2147483647; (INT_MAX 宏在 limits.h 头文件中）用等式进行判断即可。
str = "-234324665544325345325; str = - 2147483648; (INT_MIN 宏在limits.h 头文件中）
*/
//修改错误函数
char change(char x)
{
	char s=x;
	switch(x)
	{
	case 'o':
	case 'O':
		s='0';
		break;
	case 'l':
	case 'L':
		s='1';
		break;
	default:
		s=x;
	}
	return s;
}
int dec(const char* str,int len,int res,int temp,int index,int flag)//处理十进制
{
	for(int i=index;i<len;i++)
	{
		char x=change(str[i]);//进行纠错，后面都用字符x进行判断
		if(!isdigit(x))//非数字字母，停止转换
		{
			break;
		}
		temp=x-'0';
		if (res > INT_MAX / 10 || (res == INT_MAX/10 && temp > 7)) 
		{
			if(flag)
				return INT_MIN;
			else
				return INT_MAX;
		}
		res=res*10+temp;
	}
	return res;
}
int hex(const char* str,int len,int res,int temp,int index)//处理十六进制
{
	index++;
	for(int i=index;i<len ;i++)
	{
		char x=change(str[i]);//进行纠错
		if(isxdigit(x))//判断是否为16进制
		{
			
			if(isdigit(x))//数字
			{
				temp=x-'0';
				res=res*16+temp;
			}
			else//字符
			{
				char s=tolower(x);//转换为小写,str[i]不会改变，x保存转换后的值
				temp=s-'a'+10;//字符转换，f->15
				res=res*16+temp;
			}
		}
		else
			break;
	}
	return res;
}
int oct(const char* str,int len,int res,int temp,int index)//处理八进制
{
	//0123,从1开始处理，所以不用++
	for(int i=index;i<len;i++)
	{
		char x=change(str[i]);//进行纠错
		if(x>='0' && x<='7')
		{
			temp=x-'0';
			res=res*8+temp;
		}
		else
			break;
	}
	return res;
}

int  my_atoi(const char *str)
{
	int temp=0;
	int res=0;
	int len=(int)strlen(str);
	bool flag=false;//标识负号
	//处理空格
	int index=0;//标识空格出现的位置
	while(str[index]==' ')
		index++;
	if(str[index]=='-'||str[index]=='+')
	{
		if(str[index]=='-')
		{
			flag=true;//表示是负数
		}
		index++;
	}
	if(str[index]!='0')//不存在十六进制，八进制
	{
		res=dec(str,len,res,temp,index,flag);
	}
	else //处理十六进制，八进制
	{
		index++;//因为index位为0，现在要判断0后面的数值
		if(str[index]=='x')//十六进制
		{
			res=hex(str,len,res,temp,index);
		}
		else//八进制
		{
			 res=oct(str,len,res,temp,index);
		}
	}
	if(flag)//为负数
	{
		res=0-res;
	}
	return res;
}
int main()
{
	cout<<"遇到非数字字母，停止转换："<<my_atoi("l34.324")<<endl;
	cout<<"开头处理转换开始后，遇到空格停止转换："<<my_atoi("    342 456")<<endl;
	cout<<"处理正号："<<my_atoi("    +204.bad")<<endl;
	cout<<"处理负号："<<my_atoi("   -342ab.234")<<endl;
	cout<<"十六进制："<<my_atoi("  +0xa1")<<endl;
	cout<<"八进制："<<my_atoi("0123")<<endl;
	cout<<"纠正L，l错误："<<my_atoi("L23")<<endl;
	cout<<"纠正O，o错误："<<my_atoi("1o2")<<endl;
	cout<<"上溢出："<<my_atoi("2147483647")<<endl;
	cout<<"下溢出："<<my_atoi("-2147483648")<<endl;
}
