#include<bits/stdc++.h>
using namespace std;
void print(vector<int>&v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
void insertionSort(vector<int>&v,int n)
{
    vector<int>sorted;
    sorted.push_back(v[0]);
    int j;
    for(int i=1;i<v.size();i++)
    {
        j = sorted.size()-1;
        while(1)
        {
            if(j < 0)
            {
                sorted.insert(sorted.begin()+0,v[i]);
                break;
            }
            if(sorted[j]<v[i])
            {
                sorted.insert(sorted.begin()+j+1,v[i]);
                break;
            }
            else{
                j--;
            }
        }
    }
    print(sorted);
}
int main()
{
    vector<int>v = {100,2,31,20,-1,0,-2,-3};
    int n = v.size();
    insertionSort(v,n); 
    return 0;
}