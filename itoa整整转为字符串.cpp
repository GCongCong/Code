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

/*2. ���ʵ�ֽ�������ֵת��Ϊ�ַ�����
char *my_itoa(int value, char *buffer, int radix); 
����˵����
value����ת������ֵ��
buffer��Ŀ���ַ����ĵ�ַ��
radix��ת����Ľ�������������2���ƣ�10���ơ�16���Ƶȡ�
ʾ���� value = 10; radix = 2; string="1010"
������value Ϊ������
�뺯��int sprintf(char *string, char *format ,...);�Ƚϣ���ʲô��ͬ��
*/
//��nȡ��
char*  my_itoa(int value, char* buffer, int radix)
{
	char* stra="0123456789abcdefghijklmnopqrdtuvwxyz";//���Է��������е�Ҳ���ַ���������ת����
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

	for(int i=temp.size()-1;i>=0;i--)//����Ž�ȥ
	{
		buffer[index++]=temp[i];
	}
	buffer[index]='\0';
	
	return buffer;
}
int main()
{
	char buffer[128]="";
	cout<<"10ת��Ϊ������:"<<my_itoa(10,buffer,2)<<endl;
	cout<<"83ת��Ϊ�˽���:"<<"0"<<my_itoa(83,buffer,8)<<endl;
	cout<<"18ת��Ϊ�Ž���:"<<my_itoa(18,buffer,9)<<endl;
	cout<<"161ת��Ϊʮ������:"<<"0x"<<my_itoa(161,buffer,16)<<endl;
}
