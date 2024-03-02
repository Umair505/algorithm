#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>v[N];
bool vis[N];
void dfs(int src)
{
    vis[src]=true;
    for(int child:v[src])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    long long n,e;
    cin>>n>>e;
    while(e--)
    {
        long long a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    } 
    memset(vis,false,sizeof(vis));
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            ans.push_back(i);
            dfs(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=0;i<ans.size()-1;i++)
    { 
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    return 0;
}