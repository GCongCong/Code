/*136. ֻ����һ�ε�����
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
˵��������㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
ʾ�� 1:
����: [2,2,1]
���: 1
ʾ�� 2:
����: [4,1,2,1,2]
���: 4��
*/
//1.��ϣ��
int singleNumber1(vector<int>& nums) 
{
	unordered_map<int,int>hash;
	for(int i=0;i<nums.size();i++)
	{
		hash[nums[i]]++;
	}
	for(auto i:hash)//������ϣ��
	{
		if(i.second==1)//�жϳ��ִ���
		{
			return i.first;
		}
	}
	return 0;
}
//2.����Ƚ�ǰ��������
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
//λ������򽻻��ɣ�1^1=0,1^0=1,1^2^1=1^1^2=2�����Ϳ����ҵ�ֻ����һ�����Ǹ�
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
