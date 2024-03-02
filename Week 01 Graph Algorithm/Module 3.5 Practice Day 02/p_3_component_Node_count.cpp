#include<bits/stdc++.h>
using namespace std;
const int N =1e5+5;
vector<int>v[N];
int vis[N];
vector<int>ans;
int cntNode;
void dfs(int src)
{
    cntNode++;
    ans.push_back(src);    
    vis[src] = true;
    for(int child : v[src])
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
        v[a].push_back(b);
        v[b].push_back(a);
    } 
    int cnt=0;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            cntNode =0;
            dfs(i);
            ans.push_back(cntNode);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i : ans)
    {
        cout<<i<<" ";
    }
    return 0;
}