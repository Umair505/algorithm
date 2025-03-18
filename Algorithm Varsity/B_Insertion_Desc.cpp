// -----------*MOINUL ISLAM UMAIR*-----------
// Binary Insertion DESCENDING*

#include<bits/stdc++.h>
using namespace std;
void print(vector<int>v){
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
void binary_insertion(vector<int>&u)
{
    int l,r,mid;
    vector<int>s;
    s.push_back(u[0]);
    for(int i=1;i<u.size();i++)
    {
        l = 0;
        r = s.size() - 1;
        while(1)
        {
            if(l > r)
            {
                if(u[i] > s[mid])
                {
                    s.insert(s.begin()+mid,u[i]);
                }
                else
                {
                    s.insert(s.begin()+mid+1,u[i]);
                }
                break;
            }
            mid = (l+r)/2;
            if(u[i] > s[mid])
            {
                r = mid - 1;
            }
            if(u[i]<s[mid])
            {
                l = mid + 1;
            }
        }
        
    }
    print(s);
}
int main()
{
    vector<int>u ={5,-10,1,3,2,-1,-2,-3,-1000};
    binary_insertion(u); 
    return 0;
}