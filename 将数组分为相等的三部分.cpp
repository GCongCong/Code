7.2020，3，11 将数组分为相等的三部分
给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。
示例 1：
输出：[0,2,1,-6,6,-7,9,1,2,0,1]
输出：true
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
示例 2：
输入：[0,2,1,-6,6,7,9,-1,2,0,1]
输出：false
示例 3：
输入：[3,3,6,5,-2,2,5,1,-9,4]
输出：true
解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 
bool canThreePartsEqualSum(vector<int>& A) 
{
	int count=0;
	int sum=0;
	int temp=0;
	sum = accumulate(A.begin(), A.end(), 0);
	  
	if(sum%3!=0)
	{
		return false;
	}
	sum=sum/3;
	for(int i=0;i<A.size();i++)
	{
		temp+=A[i];
		if(temp==sum)
		{
			count++;
			temp=0;
		}
		if(count==3)//放在里面可以判断出相加为0，但是数据个数大于6的数组，放外面没用。
		{
			return true;
		}	
	}
		return false;
}
int main()
{
	vector<int> A;
	//A.push_back(0);
	A.push_back(10);
	//A.push_back(1);
	A.push_back(-10);
	A.push_back(10);
	A.push_back(-10);
	A.push_back(10);
	A.push_back(-10);
	A.push_back(10);
	A.push_back(-10);
	//A.push_back(1);
	cout<<canThreePartsEqualSum( A)<<endl;
}
