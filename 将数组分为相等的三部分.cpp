7.2020��3��11 �������Ϊ��ȵ�������
����һ���������� A��ֻ�п��Խ��仮��Ϊ��������ȵķǿղ���ʱ�ŷ��� true�����򷵻� false��
��ʽ�ϣ���������ҳ����� i+1 < j ������ (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) �Ϳ��Խ��������ȷ֡�
ʾ�� 1��
�����[0,2,1,-6,6,-7,9,1,2,0,1]
�����true
���ͣ�0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
ʾ�� 2��
���룺[0,2,1,-6,6,7,9,-1,2,0,1]
�����false
ʾ�� 3��
���룺[3,3,6,5,-2,2,5,1,-9,4]
�����true
���ͣ�3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 
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
		if(count==3)//������������жϳ����Ϊ0���������ݸ�������6�����飬������û�á�
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
