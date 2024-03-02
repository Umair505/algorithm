#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
    int u,v,w;
    Edge(int u,int v,int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>v[n];
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    } 
    vector<Edge>edgelist;
    for(int i=0;i<n;i++)
    {
        for(pair<int,int>child : v[i])
        {
            int childNode = child.first;
            int Cost = child.second;
            edgelist.push_back(Edge(i,childNode,Cost));

        }
    }
    for(Edge edge : edgelist)
    {
        cout<<edge.u<<" "<<edge.v<<" "<<" "<<edge.w<<endl;
    }
    return 0;
}