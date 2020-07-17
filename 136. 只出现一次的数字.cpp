/*136. 只出现一次的数字
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:
输入: [2,2,1]
输出: 1
示例 2:
输入: [4,1,2,1,2]
输出: 4。
*/
//1.哈希表
int singleNumber1(vector<int>& nums) 
{
	unordered_map<int,int>hash;
	for(int i=0;i<nums.size();i++)
	{
		hash[nums[i]]++;
	}
	for(auto i:hash)//遍历哈希表
	{
		if(i.second==1)//判断出现次数
		{
			return i.first;
		}
	}
	return 0;
}
//2.排序比较前后两个数
int singleNumber2(vector<int>& nums) 
{
	sort(nums.begin(),nums.end());
	for(int i=0;i<nums.size();i+=2)
	{
		if( i==nums.size()-1||nums[i]!=nums[i+1] )
		{
			return nums[i];
		}
	}
	return 0;
}
//位运算异或交换律：1^1=0,1^0=1,1^2^1=1^1^2=2这样就可以找到只出现一个的那个
int singleNumber(vector<int>& nums) 
{
	int sum=nums[0];;
	for(int i=1;i<nums.size();i++)
	{
		sum=nums[i]^sum;
	}
	return sum;
}
int main()
{
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	cout<<singleNumber(nums); 
}
