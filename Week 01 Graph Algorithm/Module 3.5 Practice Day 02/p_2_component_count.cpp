#include<bits/stdc++.h>
using namespace std;
const int N =1e5+5;
bool vis[N];
vector<int>adj[N];
void dfs(int src)
{
    vis[src] = true;
    for(int child : adj[src])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    int cnt =0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i);
        }
    
    }
    cout<<cnt;
    return 0;
}