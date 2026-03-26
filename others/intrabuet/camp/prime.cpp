#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int n, sum=0;
    cin >> n;
    vector<int> ara[n+1];
    
    for (int i=1; i<=n; i++)
    {
        // sum += n/i;
        // for (int j=1; j<=i; j++)
        //     if (i%j==0) cout << j << ' ';
        // cout << endl;
        for (int j=i; j<=n; j+=i) ara[j].push_back(i);
    }
    // cout << sum << endl; 
    // for (int i=1; i<=n; i++)
    // {
    //     for (int j=0; j<ara[i].size(); j++)
    //         cout << ara[i][j] << ' ';
    //     cout << endl;
    // }
    int q; cin >> q;
    while (q--)
    {
        int i, j;
        cin >> i >> j;
        if (j-1>=ara[i].size()){
            cout << -1 << endl;
            continue;
        }
        cout << ara[i][j-1] << endl;
    }

    return 0;
}