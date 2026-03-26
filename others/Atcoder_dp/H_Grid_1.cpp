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
int M = 1e9+7;
int h, w;
vector<string> v;
int dp[1001][1001];

int rec(int i, int j){
    if (i==h-1 && j==w-1) return 1;
    if (dp[i][j] != -1) return dp[i][j];

    int m1 = 0, m2 = 0;
    if (i+1<h && v[i+1][j]=='.') m1 = rec(i+1, j);
    if (j+1<w && v[i][j+1]=='.') m2 = rec(i, j+1);
    return dp[i][j] = (m1 + m2)%M;
}

void solve(int cases)
{
    memset(dp, -1, sizeof(dp));
    cin >> h >> w;
    v.resize(h);

    loop(i,0,h) cin >> v[i];
    print(rec(0,0));
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        16-05-2023 14:18
*/