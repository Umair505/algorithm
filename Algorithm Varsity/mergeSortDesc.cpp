#include<bits/stdc++.h>
using namespace std;
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
void merge(int a[],int l,int m,int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i] = a[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i] = a[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]>=R[j])
        {
            a[k] = L[i];
            i++;
            k++;
        }
        else
        {
            a[k] = R[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[],int l,int r)
{
    if(l<r)
    {
        int m = l+(r-l) / 2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main()
{
    int a[] = {200,-1,100,2,3,-100};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSort(a,0,n-1);
    print(a,n);
}
