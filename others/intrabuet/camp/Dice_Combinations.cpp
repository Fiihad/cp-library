// 08-06-2023 15:09
#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;

int main (void)
{
    int n;
    cin >> n;
    dp.resize(n+1, 0);

    for (int i=1; i<=n; i++){
        if (i<7) dp[i] = 1;
        for (int j=1; j<=6; j++) dp[i] += (dp[max(i-j,0)])%(1000000007);
        dp[i] %= 1000000007;
    }
    cout << dp[n] << endl;

    return 0;
}