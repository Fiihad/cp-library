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
vi v;
int dp[3000][3000][2];

int rec(int i, int j, int m){
    if (i > j) return 0;

    if (dp[i][j][m] != -1) return dp[i][j][m];
    if (m == 0) return dp[i][j][m] = max(rec(i+1, j, 1)+v[i], rec(i, j-1, 1)+v[j]);
    else return dp[i][j][m] = min(rec(i+1, j, 0)-v[i], rec(i, j-1, 0)-v[j]);
}

void solve(int cases)
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    v.resize(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(v);
    
    print(rec(0, n-1, 0));
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        17-05-2023 16:02
*/