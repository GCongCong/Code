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
/*1.���ʵ�ֽ��ַ���ת��Ϊ��������
int  my_atoi(const char *str);
1.������������ĸ��ֹͣת������if����
ʾ���� str = "234.324" ; ����ֵ��234��
2.���ȳ��ֿո���ַ�������ת����ת����ʼ�������ո�ֹͣת������index�����ո�
ʾ��: str ="    342 456"; ����ֵ��342��
3.���Դ��������ţ�,+��ASCIIΪ43��-��Ϊ45��flag��־λ����
ʾ���� str = "    +234.bad" ; ����ֵ�� 234�� str ="   -342ab.234" ; ����ֵ�ǣ�-342��
4.���Դ���˽��ƣ���ʮ�����ƣ�f-a=5,f��ʮ�����Ʊ�ʾ15������ӦΪf-'a'+10
ʾ���� str = "  +0xff";  ����ֵ�� 255��    str = " 0123" ;  ����ֵ�� 83��
5 ���Դ���int ������������
ʾ���� str = "567898765678987656789"; str = 2147483647; (INT_MAX ���� limits.h ͷ�ļ��У��õ�ʽ�����жϼ��ɡ�
str = "-234324665544325345325; str = - 2147483648; (INT_MIN ����limits.h ͷ�ļ��У�
*/
//�޸Ĵ�����
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
int dec(const char* str,int len,int res,int temp,int index,int flag)//����ʮ����
{
	for(int i=index;i<len;i++)
	{
		char x=change(str[i]);//���о������涼���ַ�x�����ж�
		if(!isdigit(x))//��������ĸ��ֹͣת��
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
int hex(const char* str,int len,int res,int temp,int index)//����ʮ������
{
	index++;
	for(int i=index;i<len ;i++)
	{
		char x=change(str[i]);//���о���
		if(isxdigit(x))//�ж��Ƿ�Ϊ16����
		{
			
			if(isdigit(x))//����
			{
				temp=x-'0';
				res=res*16+temp;
			}
			else//�ַ�
			{
				char s=tolower(x);//ת��ΪСд,str[i]����ı䣬x����ת�����ֵ
				temp=s-'a'+10;//�ַ�ת����f->15
				res=res*16+temp;
			}
		}
		else
			break;
	}
	return res;
}
int oct(const char* str,int len,int res,int temp,int index)//����˽���
{
	//0123,��1��ʼ�������Բ���++
	for(int i=index;i<len;i++)
	{
		char x=change(str[i]);//���о���
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
	bool flag=false;//��ʶ����
	//����ո�
	int index=0;//��ʶ�ո���ֵ�λ��
	while(str[index]==' ')
		index++;
	if(str[index]=='-'||str[index]=='+')
	{
		if(str[index]=='-')
		{
			flag=true;//��ʾ�Ǹ���
		}
		index++;
	}
	if(str[index]!='0')//������ʮ�����ƣ��˽���
	{
		res=dec(str,len,res,temp,index,flag);
	}
	else //����ʮ�����ƣ��˽���
	{
		index++;//��ΪindexλΪ0������Ҫ�ж�0�������ֵ
		if(str[index]=='x')//ʮ������
		{
			res=hex(str,len,res,temp,index);
		}
		else//�˽���
		{
			 res=oct(str,len,res,temp,index);
		}
	}
	if(flag)//Ϊ����
	{
		res=0-res;
	}
	return res;
}
int main()
{
	cout<<"������������ĸ��ֹͣת����"<<my_atoi("l34.324")<<endl;
	cout<<"��ͷ����ת����ʼ�������ո�ֹͣת����"<<my_atoi("    342 456")<<endl;
	cout<<"�������ţ�"<<my_atoi("    +204.bad")<<endl;
	cout<<"�����ţ�"<<my_atoi("   -342ab.234")<<endl;
	cout<<"ʮ�����ƣ�"<<my_atoi("  +0xa1")<<endl;
	cout<<"�˽��ƣ�"<<my_atoi("0123")<<endl;
	cout<<"����L��l����"<<my_atoi("L23")<<endl;
	cout<<"����O��o����"<<my_atoi("1o2")<<endl;
	cout<<"�������"<<my_atoi("2147483647")<<endl;
	cout<<"�������"<<my_atoi("-2147483648")<<endl;
}
