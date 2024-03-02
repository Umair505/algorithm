#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row, col, row2, col2;
    cin >> row >> col;
    int arr[row][col], sum[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin >> row2 >> col2;
    int arr2[row2][col2];
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> arr2[i][j];
        }
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            sum[i][j] = arr2[i][j] + arr[i][j];
        }
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}