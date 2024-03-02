//Problem Link->https://docs.google.com/document/d/1i69euR7HqvyYsBe90Fp_kOqRrXXtKKuG/edit
#include<bits/stdc++.h>
using namespace std;
const int N =1e5+5;
bool vis[N];
vector<int>adj[N];
int cnt = 0;
void dfs(int src)
{
    cnt++;
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
    int src;
    cin>>src;
    dfs(src);
    cout<<cnt;
    return 0;
}