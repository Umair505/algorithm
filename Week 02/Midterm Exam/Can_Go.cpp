#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll mx = 1e15;
const ll N = 1004;
ll dis[N];
vector<pair<int, int>> v[N];
class cmp
{
public:
    bool operator()(pair<int, ll> a, pair<int, ll> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<int, ll>, vector<pair<int, ll>>, cmp> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        auto par = q.top();
        q.pop();
        int node = par.first;
        ll cost = par.second;
        for (pair<int, ll> child : v[node])
        {
            int childNode = child.first;
            ll childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for (int i = 0; i <= n; i++)
    {
        dis[i] = mx;
    }
    int src;
    cin >> src;
    dijkstra(src);
    int t;
    cin >> t;
    while (t--)
    {
        int node;
        ll cost;
        cin >> node >> cost;
        if (dis[node] <= cost)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}