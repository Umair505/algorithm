#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1001;
int vis[N][N];
int maze[N][N];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
bool valid(int i,int j)
{
    return !vis[i][j] && maze[i][j]!= -1 && i>=0 && i<n && j>=0 && j<m;
}
void bfs(pair<int,int>src)
{
    queue<pair<int,int>> q;
    q.push(src);
    int count = 0;
    vis[src.first][src.second] = true;
    while (!q.empty())
    {
        count++;
        auto p = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int ci = p.first + dx[i];
            int cj = p.second + dy[i];
            if(valid(ci,cj))
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
            }
        }
    }
    cout<<count<<endl;
}
int main()
{
    cin>>n>>m;
    pair<int,int> src,des;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='#') maze[i][j] = -1;
            if(s[j]=='A') src = {i,j};
            if(s[j]=='B') des = {i,j};
        }
    } 
    bfs(src);
    if(vis[des.first][des.second]==true)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}