//Link->https://leetcode.com/problems/house-robber/description/
class Solution {
public:
    int dp[101];
    int foo(vector<int>& nums,int n)
    {
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int op1 = foo(nums,n-2)+ nums[n];
        int op2 = foo(nums,n-1);
        return dp[n] = max(op1,op2);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int op1 = foo(nums,nums.size()-1);
        return op1;
    }
};

//second way
class Solution {
public:
    int dp[101];
    int foo(vector<int>& nums,int n)
    {
        if(n>=nums.size())return 0;
        if(dp[n]!=-1)return dp[n];
        int op1 = foo(nums,n+2)+ nums[n];
        int op2 = foo(nums,n+1);
        return dp[n] = max(op1,op2);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int op1 = foo(nums,0);
        return op1;
    }
};