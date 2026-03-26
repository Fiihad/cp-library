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
int n;
vi a, b, c;
int dp[100001][3];

int rec(int i, int mode)
{
    if (i >= n) return 0;
    if (mode!=-1 && dp[i][mode] != -1) return dp[i][mode];

    int m1=0, m2=0, m0=0;
    if (mode!=0) m0 = rec(i+1, 0) + a[i];
    if (mode!=1) m1 = rec(i+1, 1) + b[i];
    if (mode!=2) m2 = rec(i+1, 2) + c[i];

    return dp[i][mode] = max({m0, m1, m2});
}

void solve(int cases)
{
    cin >> n;
    a.resize(n), b.resize(n), c.resize(n);
    memset(dp, -1, sizeof(dp));
    loop(i,0,n) cin >> a[i] >> b[i] >> c[i];
    print(rec(0, -1));
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        16-05-2023 12:27
*/