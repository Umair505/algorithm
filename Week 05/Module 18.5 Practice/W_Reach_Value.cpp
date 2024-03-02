#include <bits/stdc++.h>
using namespace std;
bool reach_value(long long int n, long long int v)
{
    if (n == v)
        return true;
    if (n > v)
        return false;
    bool op1 = reach_value(n * 10, v);
    bool op2 = reach_value(n * 20, v);
    return op1 || op2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
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