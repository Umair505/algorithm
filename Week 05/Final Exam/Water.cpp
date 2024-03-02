#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        ll maxm = INT_MIN;
        ll smaxm = INT_MIN;
        int i1,i2;
        i2 = -1;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>maxm)
            {
                smaxm = maxm;
                maxm = arr[i];
            }
            else if(arr[i]>smaxm)
            {
                smaxm = arr[i];
            }
        }
         for(int i=0;i<n;i++)
        {
            if(maxm==arr[i])i1 = i;
            if(smaxm==arr[i])i2 = i;
        }
        if(i1>=i2){
            cout<<i2<<" "<<i1<<endl;
        }
        else
        {
            cout<<i1<<" "<<i2<<endl;
        }
    }
    
    return 0;
}