// 08-06-2023 15:09
#include <bits/stdc++.h>
using namespace std;


int main (void)
{
    int n, q;
    cin >> q >> n;
    vector<long long> dp(n+1, INT32_MAX), coins(q);

    dp[0] = 0;

    for (int i=0; i<q; i++){
        cin >> coins[i];
        if (coins[i] <= n) dp[coins[i]] = 1;
    }
    sort(coins.begin(), coins.end());

    for (int i=1; i<=n; i++){
        for (int j=0; j < q && i-coins[j] >= 0; j++)
            dp[i] = min(dp[i], dp[i-coins[j]]+1);
    }

    if (dp[n] == INT32_MAX) cout << -1 << endl;
    else cout << dp[n] << endl;

    return 0;
}