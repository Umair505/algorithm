#include<bits/stdc++.h>
using namespace std;
vector<int>v[1005];
bool vis[1005];
void bfs(int src,int lvl)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    vis[src] = true;
    vector<int>node;
    while (!q.empty())
    {
        pair<int,int>p = q.front();
        q.pop();
        int par = p.first;
        int level = p.second;
        if(level == lvl)
        {
           node.push_back(par);
        }
        for(int child : v[par])
        {
            if(vis[child]==false)
            {
                q.push({child,level+1});
                vis[child] = true;
            }
        }
    }
    sort(node.begin(),node.end(),greater<int>());
    for(int val: node)
    {
        cout<<val<<" ";
    }
    
}
int main()
{
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);    
    }
    int src = 0;
    memset(vis,false,sizeof(vis));
    int level;
    cin>>level;
    bfs(src,level);
    return 0;
}