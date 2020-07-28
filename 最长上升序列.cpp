10��2020.3.14 ���������  
����һ��������������飬�ҵ���������������еĳ��ȡ�
ʾ��:
����: [10,9,2,5,3,7,101,18]
���: 4 
����: ��������������� [2,3,7,101]�����ĳ����� 4��
//��̬�滮
int lengthOfLIS1(vector<int>& nums) 
{
	if(nums.size()==0)return 0;
	vector<int> dp(nums.size(),0);
	int len=1;//��ʼΪ1
	for(int i=0;i<nums.size();i++)
	{
		dp[i]=1;
		for(int j=0;j<i;j++)
		{
			if(nums[j]<nums[i])
			{
				dp[i]=max(dp[j]+1,dp[i]);//ת�Ʒ���
				len=max(len,dp[i]);//�������
			}
		}
	}
	return len;
} 
//̰���㷨+���ֲ���
int lengthOfLIS(vector<int>& nums) 
{
	if(nums.size()==0)return 0;
	vector<int>a(nums.size()+1,0);
	int len=1;
	a[len]=nums[0];
	int pos=0;
	for(int i=1;i<nums.size();i++)
	{
		if(nums[i]>a[len])
		{
			len++;
			a[len]=nums[i];
		}
		else//���ֲ���λ�ò���
		{
			int l=0,r=len,mid=0,pos=0;
			while(l<=r)
			{
				mid=(r-l)/2+l;
				if(nums[i]>a[mid])
				{
					l=mid+1;
					pos=mid+1;
				}
				else
					r=mid-1;
			}
			a[pos]=nums[i];
		}
	}
	return len;

}
int main()
{
	vector<int>a;
	a.push_back(10);
	a.push_back(9);
	a.push_back(2);
	a.push_back(5);
	a.push_back(3);
	a.push_back(7);
	a.push_back(101);
	a.push_back(18);
	cout<<lengthOfLIS(a);
}
