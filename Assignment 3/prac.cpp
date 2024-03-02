#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int vis[N][N];
char c[N][N];
map<pair<int, int>, pair<int, int>> mp;
pair<int, int> path[N][N];
int n, m;
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j];
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    vector<pair<int, int>> pr;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + v[i].first;
            int cj = par.second + v[i].second;
            if (valid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                path[ci][cj] = {v[i].first, v[i].second};
                pr.push_back({ci, cj});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    pair<int, int> src, des;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '#')
                vis[i][j] = true;
            if (c[i][j] == 'R')
                src = {i, j};
            if (c[i][j] == 'D')
                des = {i, j};
        }
    }
    bfs(src.first, src.second);
    vector<pair<int, int>> ans;
    vector<pair<int, int>> cross;
    if (vis[des.first][des.second] == true)
    {

        while (des.first != src.first || des.second != src.second)
        {
            ans.push_back({path[des.first][des.second]});
            des.first -= ans.back().first;
            des.second -= ans.back().second;
            cross.push_back({des.first, des.second});
        }
        for(auto val:cross)
        {
            if(val.first==src.first && val.second == src.second)
            {
                continue;
            }
            c[val.first][val.second] = 'X';
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << c[i][j];
            }
            cout<<endl;
        }
    }
    else
    {
       for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << c[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
