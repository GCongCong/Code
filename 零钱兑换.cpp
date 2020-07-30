零钱兑换   2020 3，8
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
如果没有任何一种硬币组合能组成总金额，返回 -1。
示例 1:
输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:
输入: coins = [2], amount = 3
输出: -1*/

void dp(vector<int>& coins, int amount, int c_index, int count, int& ans)
{
    if (amount == 0)
    {
        ans = min(ans, count);
        return;
    }
    if (c_index == coins.size()) return;

    for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)//回溯
    {
        dp(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);//递归
    }
}
int coinChange(vector<int>& coins, int amount) //求最少，每次都从最大的找,所以你必须先排序,但是我并没有考虑到丢多了而导致凑不出数额（如。
{
	if(amount==0)
		return 0;
	sort(coins.rbegin(),coins.rend());//从大到小
	int min=INT_MAX;//用来表示最优解，每次存放最小的。
	dp(coins,amount,0,0,min);
	return min==INT_MAX?-1:min;//等于就表示没有计算。
	是个求解最优解的问题，我们也不难想到动态规划来解决。最优子结构性质我们不在此处进行证明了。我们知道下一次硬币的个数一定为上一次最少硬币个数加一，我们采用自上而下的解决方法。 2. 推导出转移方程： 3. > F(S-C)=F(S)+1; 
C代表当前硬币的大小。F(S)为当总金额为S时的最少硬币数。
}
//动态规划
class Solution {
    vector<int>count;//保存最小硬币数
    int dp(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (count[amount - 1] != 0) return count[amount - 1];//例如：F(2)=F(1)+F(1)
        int Min = INT_MAX;
        for (int coin:coins) {
            int res = dp(coins, amount - coin);//为当前最少硬币数
            if (res >= 0 && res < Min) {
                Min = res + 1;//加一
            }
        }
        count[amount - 1] = Min == INT_MAX ? -1 : Min;
        return count[amount - 1];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        count.resize(amount);//初始化
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
