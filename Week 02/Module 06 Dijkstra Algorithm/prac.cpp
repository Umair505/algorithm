#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
const int N = 1e5 + 5;
int dis[N];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edgelist;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgelist.push_back(Edge(u, v, w));
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : edgelist)
        {
            int u, v, w;
            u = ed.u;
            v = ed.v;
            w = ed.w;
            if (dis[u] < INT_MAX && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : edgelist)
    {
        int u, v, w;
        u = ed.u;
        v = ed.v;
        w = ed.w;
        if (dis[u] < INT_MAX && dis[u] + w < dis[v])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
        cout << "Cycle Ditected";
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << " -> " << dis[i] << endl;
    }
    return 0;
}