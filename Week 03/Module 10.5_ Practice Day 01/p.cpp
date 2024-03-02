#include<bits/stdc++.h>
using namespace std;
const int N =1005;
int vis[N][N];
pair<int,int> path[N][N];
int n,m;
vector<pair<int,int>>v = {{0,-1},{0,1},{-1,0},{1,0}};
bool valid(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m && !vis[i][j];
}
void bfs(int si,int sj)
{
    queue<pair<int,int>>q;
    q.push({si,sj});
    vis[si][sj] = true;
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
                vis[ci][cj]= true;
                path[ci][cj]= {v[i].first,v[i].second};
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    pair<int,int>src,des;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            if(c=='#')vis[i][j] = true;
            if(c=='A')src={i,j};
            if(c=='B')des={i,j};
        }
    } 
    bfs(src.first,src.second);
    vector<pair<int,int>>ans;
    if(vis[des.first][des.second]==true)
    {
        cout<<"YES"<<endl;
        while(des.first != src.first || des.second != src.second)
        {
            ans.push_back({path[des.first][des.second]});
            des.first-=ans.back().first;
            des.second-=ans.back().second;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto i : ans)
        {
            if(i.first == 0 && i.second == 1) cout<<"R";
            if(i.first == 0 && i.second == -1) cout<<"L";
            if(i.first == -1 && i.second == 0) cout<<"U";
            if(i.first == 1 && i.second == 0) cout<<"D";
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}