#include <bits/stdc++.h>
using namespace std;
char a[50][50];
bool vis[50][50];
int dis[50][50];
int n;
vector<pair<int, int>> d;
bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < n)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] != 'T')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;
            }
        }
    }
}
int main()
{
    d.push_back({0, 1});
    d.push_back({0, -1});
    d.push_back({-1, 0});
    d.push_back({1, 0});
    while (cin >> n)
    {
        int si, sj;
        int di, dj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (a[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        cout << dis[di][dj] << endl;
    }
    return 0;
}

/*
Link->https://school.outsbook.com/problems/problemdetails/10106
#include<bits/stdc++.h>
using namespace std;
int vis[35][35];
pair<int,int> path[35][35];
vector<pair<int,int>>v = {{0,-1},{0,1},{-1,0},{1,0}};
int n;
bool valid(int i,int j)
{
    return !vis[i][j] && i>=0 && i<n && j>=0 && j<n;
}
void bfs(int si,int sj)
{
    queue<pair<int,int>>q;
    q.push({si,sj});
    vis[si][sj] = true;
    while(!q.empty())
    {
        auto par = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int ci = par.first + v[i].first;
            int cj = par.second + v[i].second;
            if(valid(ci,cj))
            {
                q.push({ci,cj});
                vis[ci][cj]=true;
                path[ci][cj] ={v[i].first,v[i].second};
            }
        }
    }
}
int main()
{
    cin>>n;
    pair<int,int>src,des;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char c;
            cin>>c;
            if(c=='T')vis[i][j]=true;
            if(c=='S')src = {i,j};
            if(c=='E')des = {i,j};
        }
    } 
     bfs(src.first,src.second);
    vector<pair<int,int>>ans;
    if(vis[des.first][des.second]==true)
    {
        while(des.first != src.first || des.second != src.second)
        {
            ans.push_back({path[des.first][des.second]});
            des.first-=ans.back().first;
            des.second-=ans.back().second;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
    }
    return 0;
}
*/