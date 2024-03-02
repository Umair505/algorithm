#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    int mat[n][n];
    memset(mat,0,sizeof(mat));//initialy mat er shob element ke 0 kore disi
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        mat[a][b]=1;//(1,5) rakhle tho (5,1) ao rakha lagbe tai
        mat[b][a]=1;//directed graph a eita hoina
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    if(mat[3][3]==1)
    cout<<"Connection ache"<<endl;
    else
    cout<<"Connection nai"<<endl;
    return 0;
}
 /*    0 
    /  \ \
   1    \  4--2 
    \    \ / 
     5    5
*/ 