#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>mat[n];
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int node; cin>>node;
    int cnt = 0;
    for(int x:mat[node])
    {
        cnt++;
        // cout<<x<<" ";
    }
    cout<<endl;
    cout<<cnt;
    return 0;
}