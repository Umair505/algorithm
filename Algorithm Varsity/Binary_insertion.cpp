// ---------*MOINUL ISLAM UMAIR*-----------
// Binary Insertion ASCENDING*
#include<bits/stdc++.h>
using namespace std;
void print(vector<int>v)
{
    for(int i =0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
void binary_insertion(vector<int>&u)
{
    vector<int>s;
    s.push_back(u[0]);
    int l,r,mid;
    for(int i=1;i<u.size();i++)
    {
        l = 0,r=s.size();
        while(1)
        {
            if(l>r)
            {
                if(s[mid]<u[i])
                {
                    s.insert(s.begin()+mid+1,u[i]);
                }
                else
                {
                    s.insert(s.begin()+mid,u[i]);
                }
                break;
            }
            mid = (l+r)/2;
            if(u[i]>s[mid])
            {
                l = mid + 1;
            }
            if(u[i]<s[mid])
            {
                r = mid - 1;
            }
        }
    }
    print(s);
}
int main()
{
    vector<int>u ={20000,-10,1,3,2,-1,-2,-3,-1000};
    binary_insertion(u);
}