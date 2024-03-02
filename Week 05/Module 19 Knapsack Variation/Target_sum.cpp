#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main()
{
    int n;
    cin>>n;
    int a[n],sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int dif; cin>>dif;
    int s1  = (sum+dif)/2;
    dp[0][0]=1;
    for(int i=1;i<=s1;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s1;j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-a[i-1]]+ dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][s1]<<endl;
    return 0;
}