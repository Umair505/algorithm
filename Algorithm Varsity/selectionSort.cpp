// ---------*MOINUL ISLAM UMAIR*-----------
//Selection Sort Ascending Order
#include<bits/stdc++.h>
using namespace std;
void selection_sort(int a[],int n)
{
    for(int i=0;i<n - 1;i++)
    {
        int mini = i;
        for(int j=i;j<n;j++)
        {
            if(a[j] < a[mini])
            {
                mini = j;
            }
        }
        int tmp = a[mini];
        a[mini] = a[i];
        a[i] = tmp;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    } 
    selection_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}