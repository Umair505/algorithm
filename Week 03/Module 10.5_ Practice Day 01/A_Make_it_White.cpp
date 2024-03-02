#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int si = -1, li = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                if (si == -1)
                {
                    si = i;
                }
                li = i;
            }
        }
        int ans = abs(si - li) + 1;
        cout << ans <<endl;
    }
    return 0;
}