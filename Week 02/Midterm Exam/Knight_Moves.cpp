#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v = {{-1,2},{1,2},{-1,-2},{1,-2},{-2,-1},{-2,1},{2,-1},{2,1}};
int n,m;
int dis[101];
int mat[101][101];
bool vis[101][101];
int levelarr[101][101];
bool valid(int i,int j)
{
    return !vis[i][j] && i>=0 && i<n && j>=0 && j<m;
}
void bfs(int ki,int kj)
{
    queue<pair<int,int>>q;
    q.push({ki,kj});
    vis[ki][kj] = true;
    levelarr[ki][kj] = 0;
    while(!q.empty())
    {
        pair<int,int>par = q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            int ci = par.first + v[i].first;
            int cj = par.second + v[i].second;
            if(valid(ci,cj))
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                levelarr[ci][cj] = levelarr[par.first][par.second]+1;
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int ki,kj,qi,qj;
        cin>>n>>m>>ki>>kj>>qi>>qj;
        memset(vis,false,sizeof(vis));
        memset(levelarr,-1,sizeof(levelarr));
        bfs(ki,kj);
        cout<<levelarr[qi][qj]<<endl;
    }
    
    return 0;
}