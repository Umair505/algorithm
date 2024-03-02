#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[20][20];
bool vis[20][20];
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;//uporer condition fullup na hole true return korbe
}
vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for(int i=0;i<4;i++)
    {
        int ci = si+ p[i].first;
        int cj = sj + p[i].second;
        if(valid(ci,cj) && vis[ci][cj]==false)
        {
            dfs(ci,cj);
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
            cin >> a[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    int si, sj;
    cin >> si >> sj;
    dfs(si, sj);
    return 0;
}