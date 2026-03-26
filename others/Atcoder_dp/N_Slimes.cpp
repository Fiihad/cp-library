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
int dp[401][401];
vi v(401), pref(401);

int rec(int l, int r){
    if (dp[l][r] != -1) return dp[l][r];

    if (l==r) return dp[l][r] = 0;
    if (r == l+1) return dp[l][r] = v[l]+v[r];

    int mini = LLONG_MAX;
    loop(k,l,r) mini = min(mini, rec(l,k)+rec(k+1,r)+pref[r]-pref[l-1]);
    return dp[l][r] = mini;
}

void solve(int cases)
{
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;

    loop(i,1,n+1) cin >> v[i], pref[i] = pref[i-1]+v[i];

    print(rec(1,n));
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        08-06-2023 18:11
*/