#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1001;
int f[N][N];
int vis[N][N];
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && f[i][j] != -1;
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    vis[src.first][src.second] = true;
    while (!q.empty())
    {
        auto par = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {

            int ci = par.first + v[i].first;
            int cj = par.second + v[i].second;
            if (valid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
            {
                f[i][j] = -1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && f[i][j] != -1)
            {
                bfs({i, j});
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}