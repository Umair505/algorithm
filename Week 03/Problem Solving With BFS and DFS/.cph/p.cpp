#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 55;

bool vis[MAX_N][MAX_N];
int ans;
int n, m;
pair<int, int> d[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int ci, int cj, int n, int m) {
    return ci >= 0 && ci < n && cj >= 0 && cj < m;
}

void dfs(int si, int sj, int grid[MAX_N][MAX_N], int n, int m) {
    vis[si][sj] = true;
    ans++;
    for (int i = 0; i < 4; i++) {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj, n, m) && !vis[ci][cj] && grid[ci][cj] == 1) {
            dfs(ci, cj, grid, n, m);
        }
    }
}

int maxAreaOfIsland(int grid[MAX_N][MAX_N], int n, int m) {
    memset(vis, false, sizeof(vis));
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == 1) {
                ans = 0;
                dfs(i, j, grid, n, m);
                mx = max(mx, ans);
            }
        }
    }
    return mx;
}

int main() {
    int n, m;
    cin >> n >> m;
    int grid[MAX_N][MAX_N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int result = maxAreaOfIsland(grid, n, m);
    cout << result << endl;
    return 0;
}
