#include<bits/stdc++.h>
using namespace std;
const int N =1005;
int vis[N][N];
pair<int,int> path[N][N];
int n,m;
vector<pair<int,int>>v = {{0,1},{0,-1},{-1,0},{1,0}};
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
/*
#include <bits/stdc++.h>
using namespace std;
const int sz = 1005;
char mat[sz][sz];
bool vst[sz][sz];
pair<int, int> par[sz][sz];
int n, m;
pair<int, int> A, B;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 and j >= 0 and i < n and j < m);
}

void bfs_(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vst[si][sj] = 1;

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int a = p.first, b = p.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first, cj = b + d[i].second;
            if (isValid(ci, cj) and !vst[ci][cj] and mat[ci][cj] != '#')
            {
                vst[ci][cj] = 1;
                q.push({ci, cj});
                par[ci][cj] = {a, b};
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'A')
                A = {i, j};
            if (mat[i][j] == 'B')
                B = {i, j};
        }
    }

    int si = A.first, sj = A.second;
    par[si][sj] = {-1, -1};
    bfs_(si, sj);

    if (vst[B.first][B.second])
    {
        cout << "YES\n";
        auto cur = B;
        string ans;
        while (true)
        {
            int a = cur.first, b = cur.second;
            int c = par[a][b].first, d = par[a][b].second;

            if (a > c and b == d)
                ans += 'D';
            else if (a < c and b == d)
                ans += 'U';
            else if (a == c and b > d)
                ans += 'R';
            else if (a == c and b < d)
                ans += 'L';

            if (si == a and sj == b)
                break;
            cur = par[a][b];
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl
             << ans << endl;
    }
    else
        cout << "NO\n";

    return 0;
}
*/