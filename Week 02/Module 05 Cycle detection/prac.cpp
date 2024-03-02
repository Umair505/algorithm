#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
vector<int>v[N];
bool ans;
bool pathVisit[N];
bool vis[N];
void dfs(int par)
{
    vis[par] = true;
    pathVisit[par] = true;
    for(int child :v[par])
    {
        if(pathVisit[true])
        {
            ans = true;
        }
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
        v[a].push_back(b);
    }
    ans = false;
    memset(vis,false,sizeof(vis));
    memset(pathVisit,false,sizeof(pathVisit));
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    if(ans) cout<<"FOUND";
    else cout<<"NOT FOUND";
    return 0;
}