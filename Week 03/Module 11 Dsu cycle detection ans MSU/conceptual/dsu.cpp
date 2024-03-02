#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
void make(int v)
{
    parent[v] = v;//v ke nijer parent baniye dilam

}
int find(int v)
{
    if(v==parent[v]) return v;
    return find(parent[v]);
}
void Union(int a,int b)
{
    if(find(a)!=find(b))
    {
        
    }
}
int main()
{
     
    return 0;
}