��Ǯ�һ�   2020 3��8
������ͬ����Ӳ�� coins ��һ���ܽ�� amount����дһ��������������Դճ��ܽ����������ٵ�Ӳ�Ҹ�����
���û���κ�һ��Ӳ�����������ܽ����� -1��
ʾ�� 1:
����: coins = [1, 2, 5], amount = 11
���: 3 
����: 11 = 5 + 5 + 1
ʾ�� 2:
����: coins = [2], amount = 3
���: -1*/

void dp(vector<int>& coins, int amount, int c_index, int count, int& ans)
{
    if (amount == 0)
    {
        ans = min(ans, count);
        return;
    }
    if (c_index == coins.size()) return;

    for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)//����
    {
        dp(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);//�ݹ�
    }
}
int coinChange(vector<int>& coins, int amount) //�����٣�ÿ�ζ���������,���������������,�����Ҳ�û�п��ǵ������˶����´ղ�������硣
{
	if(amount==0)
		return 0;
	sort(coins.rbegin(),coins.rend());//�Ӵ�С
	int min=INT_MAX;//������ʾ���Ž⣬ÿ�δ����С�ġ�
	dp(coins,amount,0,0,min);
	return min==INT_MAX?-1:min;//���ھͱ�ʾû�м��㡣
	�Ǹ�������Ž�����⣬����Ҳ�����뵽��̬�滮������������ӽṹ�������ǲ��ڴ˴�����֤���ˡ�����֪����һ��Ӳ�ҵĸ���һ��Ϊ��һ������Ӳ�Ҹ�����һ�����ǲ������϶��µĽ�������� 2. �Ƶ���ת�Ʒ��̣� 3. > F(S-C)=F(S)+1; 
C����ǰӲ�ҵĴ�С��F(S)Ϊ���ܽ��ΪSʱ������Ӳ������
}
//��̬�滮
class Solution {
    vector<int>count;//������СӲ����
    int dp(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (count[amount - 1] != 0) return count[amount - 1];//���磺F(2)=F(1)+F(1)
        int Min = INT_MAX;
        for (int coin:coins) {
            int res = dp(coins, amount - coin);//Ϊ��ǰ����Ӳ����
            if (res >= 0 && res < Min) {
                Min = res + 1;//��һ
            }
        }
        count[amount - 1] = Min == INT_MAX ? -1 : Min;
        return count[amount - 1];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        count.resize(amount);//��ʼ��
        return dp(coins, amount);
    }
};
int main()
{
	vector <int> a;
	//a.push_back(186);
	a.push_back(1);
	a.push_back(2);
	a.push_back(5);
	cout<<coinChange(a,11);

}
