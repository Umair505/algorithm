#include<bits/stdc++.h>
using namespace std;
const int N = 101;
vector<int>adj[N];
bool vis[N];
int cnt = 0;
void dfs(int src)
{
    cnt++;
    vis[src] = true;
    for(int child : adj[src])
    {
        if(vis[child]==false)
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
    int count = 0;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
          cnt = 0;
          dfs(i);
          if(cnt>1)count++;
        }
    }
    cout<<count<<endl;
    return 0;
}