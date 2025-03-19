#include<bits/stdc++.h>
using namespace std;
void selectionSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
//        int mini = i;
        int maxi = i;
        for(int j=i;j<n;j++)
        {
//            if(a[mini] > a[j])
//                mini = j;
            if(a[maxi]<a[j])
                maxi = j;
        }
//        int tmp = a[mini];
//        a[mini] = a[i];
//        a[i] = tmp;
        int tmp = a[maxi];
        a[maxi] = a[i];
        a[i] = tmp;
    }
}
int main()
{
    int a[] = {100,-1,-10,0,2,5};
    int n = sizeof(a) / sizeof(a[0]);
    selectionSort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
