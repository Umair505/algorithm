#include<bits/stdc++.h>
using namespace std;
bool is_Okey(long long int n,long long int s,long long int a[])
{
    if(n==1) // changed 
    {
        if(s==0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    if(a[n-1]<=s)
    {
        bool opt1 = is_Okey(n-1,s-a[n-1],a);
        bool opt2 = is_Okey(n-1,s,a);
        return opt1||opt2;
    }
    else 
    {
        return is_Okey(n-1,s,a);
    }
}
int main ()
{
    long long int n,s;
    cin>>n>>s;
    long long int a[n];
    long long int ss=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ss+=a[i];
    }
    
    long long int target = (s+ss)/2;
    bool ans = is_Okey(n,target - a[0],a); // changed 
   if((s+ss)%2==0)
   {
     if(ans)
    {
        cout<<"YES"<<endl;
    }
    else 
    {
        cout<<"NO"<<endl;
    }
   }
   else 
   {
    cout<<"NO"<<endl;
   }
    return 0;
}