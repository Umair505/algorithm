 dp[0][0]=true;
    for(int i=1;i<=s1;i++)
    {
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s1;j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[n][s1])cout<<"YES"<<endl;
    else cout<<"NO";