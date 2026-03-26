/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার,
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0);  // fast IO! but only when online_judge
#define debug 0
#else
#define fast ;
#define debug 1
#endif

// some typedefs for my convenience
#define int long long int
#define pii pair<int, int>
#define vi vector<int>
#define si set<int>
#define mi map<int, int>
// some speedup macros
#define gap ' '
#define endl '\n'
#define print(str) cout << str << endl
#define YES print("YES")
#define NO print("NO")
#define loop(i, begin, end) for(__typeof(end)i=begin-(begin>end); i!=end-(begin>end); i+=1-2*(begin>end))
#define all(v) v.begin(), v.end()

void solve();
int32_t main()
{
    fast
    int total_cases = 1;
    cin >> total_cases;
    loop(cases, 1, total_cases+1) solve();
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vi v(n);
    loop (i,0,n) cin >> v[i];

    int dp[n+1][3];
    dp[0][0] = dp[0][1] = v[0]+1, dp[0][2] = INT32_MIN;
    loop(i,1,n){
        dp[i][0] = max(v[i]+i+1, dp[i-1][0]);
        dp[i][1] = max(v[i]+dp[i-1][0], dp[i-1][1]);
        dp[i][2] = max(v[i]-(i+1)+dp[i-1][1], dp[i-1][2]);
    }
    print(dp[n-1][2]);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        25-05-2023 01:03
*/