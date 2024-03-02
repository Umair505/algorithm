#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int flor[N][N];
int visited[N][N];
int n, m;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return !visited[i][j] && flor[i][j] != -1 && i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> Q;
    Q.push(src);

    visited[src.first][src.second] = true;

    while (!Q.empty())
    {
        pair<int, int> parent = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = parent.first + d[i].first;
            int cj = parent.second + d[i].second;

            if (isValid(ci, cj))
            {
                Q.push({ci, cj});
                visited[ci][cj] = true;
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
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
            {
                flor[i][j] = -1;
            }
        }
    }

    int apartments = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && flor[i][j] != -1)
            {
                bfs({i, j});
                apartments++;
            }
        }
    }

    cout << apartments << endl;
    return 0;
}