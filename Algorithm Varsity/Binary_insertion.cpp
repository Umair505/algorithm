#include<bits/stdc++.h>
using namespace std;
void printsorted(vector<int>s)
{
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int>u= {5,10,1,3,2};
    printsorted(u);
    vector<int>s;
    int l,h,mid;
    s.push_back(u[0]);
    for(int i=1; i<5; i++)
    {
        l=0;
        h=s.size()-1;
        while(1)
        {
            if(l>h)
            {
                if(u[i]>s[mid])
                {
                    s.insert(s.begin()+mid+1,u[i]);
                    break;
                }
                else
                {
                    s.insert(s.begin()+mid,u[i]);
                    break;
                }
            }
            mid=(l+h)/2;
            if(u[i]>s[mid])
            {
                l=mid+1;
            }
            if(u[i]<s[mid])
            {
                h=mid-1;
            }
        }
    }
    cout<<"Final Array"<<endl;
    printsorted(s);
}
 