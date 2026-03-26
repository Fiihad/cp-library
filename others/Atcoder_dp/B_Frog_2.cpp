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


void solve(int cases);
int32_t main()
{
    fast
    int total_cases = 1;
    // cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
vi dp(2e5+2, -1);
int k;

int rec(int n, vi &v)
{
    if (n <= 0) return 0;
    if (dp[n] != -1) return dp[n];
    if (n <= k) return dp[n] = llabs(v[0]-v[n]);

    int out = LLONG_MAX;
    for (int i=n-1; i>=n-k; i--) out = min(out, rec(i, v)+llabs(v[n]-v[i]));

    return dp[n] = out;
}

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> k;

    vi v(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(v);

    print(rec(n-1, v));

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        16-05-2023 12:06
*/