#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>v[N];
bool vis[N];
int parent[N];
int level[N];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child : v[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=true;
                parent[child] = par;
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
        v[a].push_back(b);
        v[b].push_back(a);
    }    
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    bfs(1);
    if(vis[1]==true && vis[n]==true)
    {
        vector<int>ans;
    while (n!=-1)
    {
        ans.push_back(n);
        n = parent[n];
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(int i : ans)
    {
        cout<<i<<" ";
    }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}