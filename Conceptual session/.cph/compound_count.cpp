#include<bits/stdc++.h>
using namespace std;
const int N = 101;
vector<int>adj[N];
bool vis[N];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int child : adj[p])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child] = true;
            }
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
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            bfs(i);
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}