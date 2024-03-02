#include<bits/stdc++.h>
using namespace std;
const int N = 10001;
int vis[N][N];
int maze[N][N];
int n,m;
vector<pair<int,int>> v = {{0,1},{0,-1},{-1,0},{1,0}};
bool valid(int i,int j)
{
    return !vis[i][j] && maze[i][j]!=-1 && i>=0 && i<n && j>=0 && j<m;
}
void bfs(pair<int,int> src)
{
    queue<pair<int,int>>q;
    q.push(src);
    vis[src.first][src.second] = true;
    while(!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int ci = par.first + v[i].first;
            int cj = par.second + v[i].second;
            if(valid(ci,cj))
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='-')
            {
                maze[i][j] = -1;
            }
        }
    }
    pair<int,int>src,des;
    cin>>src.first>>src.second>>des.first>>des.second;
    bfs(src);
    if(vis[des.first][des.second]==true)
    {
        cout<<"YES"<<endl;
    } 
    else cout<<"NO"<<endl;
    return 0;
}