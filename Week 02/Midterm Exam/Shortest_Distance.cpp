#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll mxm = 1e15;
int main()
{
    int  n,e;
    cin>>n>>e;
    ll adj[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            adj[i][j] = mxm;
            if(i==j)
            {
                adj[i][j] = 0;
            }
        }
    }
    while(e--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        if(adj[a][b]>c)
        {
            adj[a][b] = c;
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(adj[i][k]+adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    int t; cin>>t;
    while (t--)
    {
        ll s,d;
        cin>>s>>d;
        if(adj[s][d]==mxm)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<adj[s][d]<<endl;
        }
    }
    
    return 0;
}