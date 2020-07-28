9. 2020.3.13 ����Ԫ��
����һ����СΪ n �����飬�ҵ����еĶ���Ԫ�ء�����Ԫ����ָ�������г��ִ������� ? n/2 ? ��Ԫ�ء�
����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�
ʾ�� 1:
����: [3,2,3]
���: 3
ʾ�� 2:
����: [2,2,1,1,1,2,2]
���: 2
//1.����
 int majorityElement1(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
	return nums[nums.size()/2];
}
//2.��ϣ��
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
//3.ͶƱ��
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
