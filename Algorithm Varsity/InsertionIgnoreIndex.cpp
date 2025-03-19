#include<bits/stdc++.h>
using namespace std;
void print(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
 
}
void insertionSort(int a[],int n,int index)
{
    vector<int>s;
    int it;
    s.push_back(a[0]);
    for(int i=1;i<n;i++)
    {
        it = s.size() - 1;
        if(i==index){
            // s.insert(s.begin()+index,a[index]);
            continue;
        }
        while(1)
        {
            if(it == index){
                it--;
                continue;
            }
            if(it<0)
            {
                s.insert(s.begin()+0,a[i]);
                break;
            }
            if(s[it]<a[i])
            {
                s.insert(s.begin()+it+1,a[i]);
                break;
            }
            else{
                it--;
            }
        }
    }
    s.insert(s.begin()+index,a[index]);
    for(int i=0;i<s.size();i++)
    {
        cout<<s[i]<<" ";
    }
    
}
int main()
{
    int n,index;
    cin>>n;
    cin>>index;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    insertionSort(a,n,index); 
    return 0;
}