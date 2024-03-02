#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a1, b1;
        cin >> a1 >> b1;
        if (mat[a1][b1] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            if (a1 == b1)
            {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
    }

    return 0;
}