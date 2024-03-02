#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int vis[N];
int level[N];
vector<int>v[N];
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
                vis[child] = true;
                level[child]=level[par]+1;
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
    int src,des,k;
    cin>>src>>des>>k;
    bfs(src);
    int stp = level[des];
    if(vis[des]==true)
    {
        if(stp<=k*2)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}