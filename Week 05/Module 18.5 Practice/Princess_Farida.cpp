#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[10004];
ll mons(int a[],int n)
{
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    ll op1 = mons(a,n-2) + a[n];
    ll op2 = mons(a,n-1);
    return dp[n] = max(op1,op2);
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        memset(dp,-1,sizeof(dp));
        ll ans =  mons(a,n-1);
        cout<<"Case "<<i<<": "<<ans<<endl;
    } 
    return 0;
}