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
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
int dp[101][100001], dpsum[101][100001];

void solve(int cases)
{
    int n, q;
    int M = 1e9+7;

    cin >> n >> q;
    vi v(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(v);
    
    loop(i,0,n+1) dp[i][0] = dpsum[i][0] = 1;
    loop(i,1,q+1) dp[0][i] = 0, dpsum[0][i] = 1;

    loop(i,1,n+1){
        loop(j,1,q+1){
            dp[i][j] = dpsum[i-1][j];
            if (j-v[i-1] > 0) dp[i][j] -= dpsum[i-1][j-v[i-1]-1];
            dp[i][j] += M;
            dp[i][j] %= M;
            dpsum[i][j] = (dpsum[i][j-1] + dp[i][j])%M;
        }
    }

    print(dp[n][q]);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        17-05-2023 16:48
*/