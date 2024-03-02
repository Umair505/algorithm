//Link->https://leetcode.com/problems/min-cost-climbing-stairs/description/
class Solution {
public:
    int dp[1000];
    int choose(vector<int>& cost,int n)
    {
        if(n>=cost.size())
        return 0;
        if(dp[n]!=-1)return dp[n];
        int op1 = choose(cost,n+1)+cost[n];
        int op2 = choose(cost,n+2)+cost[n];
        return dp[n]=min(op1,op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp,-1,sizeof(dp));
        int op1 = choose(cost,0);
        int op2 = choose(cost,1);
        return min(op1,op2);
    }
};