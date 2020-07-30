5.买卖股票的最佳时期  2020，3，9
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
注意你不能在买入股票前卖出股票。
示例 1:
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

/*暴力法
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
//滑动窗口法，每次找小的，计算一次利润
/*int maxProfit(vector<int>& prices)
{
	if(!(prices.empty()))
	{
		int r=0;//买入点
		int c=1;//卖出点
		int cru=0;
		int pro=0;
		for(c;c<prices.size();c++)
		{
			if(prices[r]>prices[c])//每次把小的给买入点
			{
				r=c;
			}
			cru=prices[c]-prices[r];//计算当前利润
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
