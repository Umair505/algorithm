#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+5;
int par[N];
int group_size[N];
void dsu_initialize(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if(par[node]==-1)return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union_by_size(int node1,int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(group_size[leaderA]>group_size[leaderB])
    {
        par[leaderB]= leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA]= leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
class Edge
{
    public:
    int u,v;
    ll w;
    Edge(int u,int v,ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a,Edge b)
{
    return a.w < b.w;
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    vector<Edge>edgelist;
    while(e--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edgelist.push_back(Edge(u,v,w));
    } 
    sort(edgelist.begin(),edgelist.end(),cmp);
    ll totalCost = 0;
    int city = n;
    int count = 0;
    for(Edge ed: edgelist)
    {
        int leaderA = dsu_find(ed.u);
        int leaderB = dsu_find(ed.v);
        if(leaderA == leaderB)
        {
            count++;
            continue;
        }
        else
        {
            dsu_union_by_size(ed.u,ed.v);
            totalCost +=ed.w;
            city--;
        }
    }
    if(city>1)
    {
        cout<<"Not Possible"<<endl;
    }
    else
    cout<<count<<" "<<totalCost<<endl;
   
    return 0;
}