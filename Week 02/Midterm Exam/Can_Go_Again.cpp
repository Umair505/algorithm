#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1004;
ll mxm = 1e18;
ll dis[N];
class Edge
{
public:
    ll u, v;
    ll c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int main()
{
    int n;
    ll e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        ll a, b;
        ll c;
        cin >> a >> b >> c;
        EdgeList.push_back(Edge(a, b, c));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = mxm;
    }
    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (Edge ed : EdgeList)
        {
            ll u = ed.u;
            ll v = ed.v;
            ll c = ed.c;
            if (dis[u] < mxm && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        ll u = ed.u;
        ll v = ed.v;
        ll c = ed.c;
        if (dis[u] < mxm && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }
    if(cycle) cout<<"Negative Cycle Detected"<<endl;
    else 
    {
     int t; cin>>t;
     while (t--)
     {
        ll des; cin>>des;
        if(dis[des]==mxm){
            cout<<"Not Possible"<<endl;
        }
        else
        cout<<dis[des]<<endl;
     }
        
    }
    return 0;
}