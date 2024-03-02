#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll,ll>
using namespace std;
const ll N = 1e5 + 5;
ll dis[N];
ll parent[N];
vector<pr>v[N];
class cmp
{
    public:
    bool operator()(pr a,pr b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pr,vector<pr>,cmp> q;
    q.push({src, 0});
    dis[src] = 0;
    while(!q.empty())
    {
        pr par = q.top();
        q.pop();
        ll node = par.first;
        ll cost = par.second;
        for (pr child : v[node])
        {
            ll childNode = child.first;
            ll childCost = child.second;
            if(childCost+cost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                q.push({childNode,dis[childNode]});
                parent[childNode] = node;
            }
        }
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++)
    {
        dis[i] = 1e18;
        parent[i] = -1;
    }
    dijkstra(1);
    if(dis[n]==1e18)cout<<-1;
    else
    {
        ll x = n;
    vector<ll>ans;
    while(x!=-1)
    {
        ans.push_back(x);
        x = parent[x];
    }
    reverse(ans.begin(),ans.end());
    for(ll i : ans)
    {
        cout<<i<<" ";
    }
    }
    return 0;
}