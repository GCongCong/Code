5.������Ʊ�����ʱ��  2020��3��9
����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������
ע���㲻���������Ʊǰ������Ʊ��
ʾ�� 1:
����: [7,1,5,3,6,4]
���: 5
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
     ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�
ʾ�� 2:
����: [7,6,4,3,1]
���: 0
����: �����������, û�н������, �����������Ϊ 0��

/*������
int maxProfit(vector<int>& prices)
{
	int pro=0;
	for(int i=0;i<prices.size();i++)
	{
		for(int j=i;j<prices.size();j++)
		{
			int temp=prices[j]-prices[i];
			if(temp>pro)
			{
				pro=temp;
			}
		}
	}
	return pro;
}*/
//�������ڷ���ÿ����С�ģ�����һ������
/*int maxProfit(vector<int>& prices)
{
	if(!(prices.empty()))
	{
		int r=0;//�����
		int c=1;//������
		int cru=0;
		int pro=0;
		for(c;c<prices.size();c++)
		{
			if(prices[r]>prices[c])//ÿ�ΰ�С�ĸ������
			{
				r=c;
			}
			cru=prices[c]-prices[r];//���㵱ǰ����
			pro=cru>pro?cru:pro;
		}
		return pro;
	}
	else
		return 0;
	
}
int main()
{
	vector<int>a;
	//a.push_back(7);
	a.push_back(2);
	a.push_back(4);
	a.push_back(1);
	//a.push_back(6);
	//a.push_back(4);
	cout<<maxProfit(a)<<endl;
}
