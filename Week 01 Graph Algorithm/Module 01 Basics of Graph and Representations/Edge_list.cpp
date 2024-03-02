#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> v;//প্রতিটা ইন্ডেক্সে একটা পেয়ার থাকবে
    
    while (e--)
    {
        int a,b;
        cin>>a>>b;
        //v.push_back(make_pair(a,b));
        v.push_back({a,b});
    }//shob gula edge ke store korsi
    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v[i].first<<" "<<v[i].second<<endl;;
    // }
    // for(pair<int,int>p : v)//shortcut print
    // {
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
     for(auto p : v)//shortcut print
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}