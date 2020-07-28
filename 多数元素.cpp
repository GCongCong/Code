9. 2020.3.13 多数元素
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ? n/2 ? 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
示例 1:
输入: [3,2,3]
输出: 3
示例 2:
输入: [2,2,1,1,1,2,2]
输出: 2
//1.排序
 int majorityElement1(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
	return nums[nums.size()/2];
}
//2.哈希表
 int majorityElement2(vector<int>& nums)
 {
	 unordered_map<int,int> record;
	 for(int i=0;i<nums.size();i++)
	 {
		 record[nums[i]]++;
		 if(record[nums[i]]>nums.size()/2)
		 {
			 return nums[i];
		 }
	 }
	 return -1;
 }
//3.投票法
 int majorityElement (vector<int>& nums)
 {
	 int cand=nums[0];
	 int count=1;
	 for(int i=1;i<nums.size();i++)
	 {
		 if(nums[i]==cand)
		 {
			 count++;
		 }
		 else if(--count<0)
		 { 
			 cand=nums[i];
			 count=1;
		 }
		
	 }
	 return cand;

 }
int main()
{
	vector<int>a;
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	 
	cout<<majorityElement(a);
}
