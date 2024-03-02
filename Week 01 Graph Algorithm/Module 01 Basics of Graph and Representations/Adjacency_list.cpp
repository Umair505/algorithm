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
        mat[a].push_back(b);//a index gia b ke rekhe dao.Jehetu eita undirected tai
        mat[b].push_back(a);//b index gia a ke rekhe dao
    }
    vector<int>v;
    for(int x:mat[0])
    {
        cout<<x<<" ";//mat 0 index a k k connected oigula output dibe
    }
    // for(int i=0;i<mat[0].size();i++)
    // {
    //     cout<<mat[0][i]<<" ";
    // }
    return 0;
}