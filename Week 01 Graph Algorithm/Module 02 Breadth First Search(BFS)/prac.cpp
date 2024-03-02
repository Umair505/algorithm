#include<bits/stdc++.h>
using namespace std;
vector<int>v[1005];//maximum size ta rakhbo 
bool vis[1005];//visited kina oita check korar jonno
//BFS time complixity->O(V+E)(node=v,E=edge)
//Space complixity->O(v);
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    vector<int>vec;
    while (!q.empty())//O(n)
    {
        int par = q.front();
        q.pop();
        vec.push_back(par);
        for(int child: v[par])
        {
            if(vis[child]==false)
            {
                q.push(child);
                vis[child]=true;
                
            }
        }
    }
    for(int val:vec)
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
    int src;
    cin>>src;
    memset(vis,false,sizeof(vis));
    bfs(src);
    return 0;
}