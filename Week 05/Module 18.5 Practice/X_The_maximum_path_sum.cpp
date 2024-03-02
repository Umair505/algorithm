#include<bits/stdc++.h>
using namespace std;
int row,col;
int mat[11][11];
long long max_path_sum(int n,int m)
{
    if(n>row || m>col) return INT_MIN;
    
    if(n==row && m == col)return mat[n][m];

    long long op1 = max_path_sum(n+1,m);
    long long op2 = max_path_sum(n,m+1);
    return mat[n][m] + max(op1,op2);
}
int main()
{
    cin>>row>>col;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            cin>>mat[i][j];
        }
    } 
    long long sum = max_path_sum(1,1);
    cout<<sum<<endl;
    return 0;
}