#include<bits/stdc++.h>
using namespace std;
int binary_search(int arr[],int n,int target)
{
    int low = 0, high = n-1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  
        if(low == 4 || high == 4) break;
        if (arr[mid] == target) {
            return mid;  
        }
        else if (arr[mid] < target) {
            low = mid + 1;  
        }
        else {
            high = mid - 1;  
        }
    }
    low = 4;
    high = n -1;
    while(low<=high)
    {
        int mid = low + (high - low) / 2;  
        if (arr[mid] == target) {
            return mid;  
        }
        else if (arr[mid] > target) {
            low = mid + 1;  
        }
        else {
            high = mid - 1;  
        }
    }

    return -1;  
}
int main()
{
    int a[]= {0,2,3,5,6,13,12,11,9,8};
    int element;
    cin>>element;
    int n = sizeof(a)/sizeof(a[0]);
    int found = binary_search(a,n,element);
    if(found!=-1)cout<<"Element found"<<endl;
    else cout<<"Element not found";
    return 0;
}