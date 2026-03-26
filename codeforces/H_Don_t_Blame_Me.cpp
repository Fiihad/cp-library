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
#define endl '\n'
#define print(str) cout << str << endl
#define loop(i, begin, end) for(__typeof(end)i=begin-(begin>end); i!=end-(begin>end); i+=1-2*(begin>end))

int M = 1e9 + 7;
void solve(int cases);
int32_t main()
{
    fast
    int total_cases = 1;
    cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE

int dp[200001][128], v[200001];
int rec(int i, int AND, int q)
{
    if (i<0) return (__builtin_popcount(AND)==q);
    if (dp[i][AND]!=-1) return dp[i][AND];

    int nottake = rec(i-1, AND, q);
    int take = rec(i-1, AND&v[i], q);
    return dp[i][AND] = (take + nottake)%M;
}

void solve(int cases)
{
    int n, q, out=0;
    int in;
    cin >> n >> q;
    
    loop(i,0,n){
        cin >> v[i];
        loop(j,0,128) dp[i][j] = -1;
    }

    out = rec(n-1, 127, q);
    print(out);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        07-05-2023 01:50
*/