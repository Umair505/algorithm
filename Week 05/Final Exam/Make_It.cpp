#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N];
bool reach_value(long long int n, long long int v)
{
    if (n == v)
        return true;
    if (n > v)
        return false;
    if(dp[n] !=-1) return dp[n];
    bool op1 = reach_value(n + 3, v);
    bool op2 = reach_value(n * 2, v);
    return dp[n] = op1 || op2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        memset(dp,-1,sizeof(dp));
        if (reach_value(1, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}