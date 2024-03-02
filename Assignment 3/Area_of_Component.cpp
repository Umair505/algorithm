#include<bits/stdc++.h>
#define pr pair<int,int>
#define ll long long int
using namespace std;
int n,m;
const int N = 1001;
int vis[N][N];
vector<pr>v={{0,-1},{0,1},{-1,0},{1,0}};
bool valid(int i,int j)
{
    return !vis[i][j] && i>=0 && i<n && j>=0 && j<m;
}
int bfs(int si,int sj)
{
    queue<pr>q;
    q.push({si,sj});
    vis[si][sj] = true;
    int cnt = 0;
    while(!q.empty())
    {
        cnt++;
        pr par = q.front();
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
    return cnt;
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
                vis[i][j] = true;
            }
        }
    }
    int cnt =0;
    vector<int>vec;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(!vis[i][j])
           {
             int ans = bfs(i,j);
            if(ans>=1)
            {
                vec.push_back(ans);
            }
           }
        }
    }
    if(vec.empty())
    {
        cout<<-1;
    }
    else
    {
        int minm = vec[0];
        for(int val : vec)
        {
            minm = min(val,minm);
        }
        cout<<minm;
    }
    
    return 0;
}