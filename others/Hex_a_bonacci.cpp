#include <cstdio>
#include <vector>
using namespace std;

#define int long long
int mod = 10000007;

int a, b, c, d, e, f;
int fn(int n, vector<int> &dp) {
    if (dp[n] != -1) return dp[n];

    if (n == 0) return dp[n] = a;
    if (n == 1) return dp[n] = b;
    if (n == 2) return dp[n] = c;
    if (n == 3) return dp[n] = d;
    if (n == 4) return dp[n] = e;
    if (n == 5) return dp[n] = f;
    return dp[n] = (fn(n-1, dp)%mod + fn(n-2, dp)%mod + fn(n-3, dp)%mod + fn(n-4, dp)%mod + fn(n-5, dp)%mod + fn(n-6, dp)%mod)%mod;
}
signed main() {
    int n, cases;
    scanf("%d", &cases);
    for (int caseno = 1; caseno <= cases; ++caseno) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        vector<int> dp(n+1, -1);
        printf("Case %lld: %lld\n", caseno, fn(n, dp));
    }
    return 0;
}