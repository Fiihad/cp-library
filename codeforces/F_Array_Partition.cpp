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
// #define int long long int
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
    cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE

int ansi, ansj;
map<pii, bool> dp;

bool rec(int i, int j, vi &v, vi &pmax1, vi &pmax2, vector<vi> &pmin){
    if (i >= j-1) return false;
    if (dp.count({i, j})) return dp[{i, j}];

    if (pmax1[i] < pmax2[j]) return dp[{i, j}] = rec(i+1, j, v, pmax1, pmax2, pmin);
    if (pmax1[i] > pmax2[j]) return dp[{i, j}] = rec(i, j-1, v, pmax1, pmax2, pmin);

    // extracting min from sparse table
    int l = i+1, r = j-1;
    int len = r-l+1;
    int k = 31 - __builtin_clz(len);
    int mini = min(pmin[l][k], pmin[r-(1<<k)+1][k]);

    if (pmax1[i] == mini){
        ansi = i, ansj = j;
        return dp[{i, j}] = true;
    }

    int t = pmax2.rend() - upper_bound(pmax2.rbegin(), pmax2.rend(), pmax2[j]);
    if (t <= i+1) t = i+2;
    if (t != j && v[t] == pmax2[j]) t++;
    int u = upper_bound(all(pmax1), pmax1[i]) - pmax1.begin() - 1;
    if (u >= t-1) u = t-2;
    if (u != i && v[u] == pmax1[i]) u--;

    int out = 0;
    if (t != j || u != i) out |= rec(u, t, v, pmax1, pmax2, pmin);
    if (!out) out |= rec(i+1, j, v, pmax1, pmax2, pmin);
    return dp[{i, j}] = out;
}

void solve(int cases)
{
    dp.clear();
    int n;
    cin >> n;

    vi v(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(v);

    vi pmax1(n), pmax2(n);
    pmax1[0] = v[0]; pmax2[n-1] = v[n-1];
    loop(i,1,n) pmax1[i] = max(pmax1[i-1], v[i]);
    loop(i,n-1,0) pmax2[i] = max(pmax2[i+1], v[i]);


    // sparse table
    int LOG = 31 - __builtin_clz(n) + 1;
    vector<vi> pmin(n, vi(LOG));
    loop(i,0,n) pmin[i][0] = v[i];
    loop(k, 1, LOG)
        for (int i=0; i + (1<<k) - 1 < n; i++)
            pmin[i][k] = min(pmin[i][k-1], pmin[i+(1<<(k-1))][k-1]);


    if (rec(0, n-1, v, pmax1, pmax2, pmin)){
        YES;
        print(ansi+1 << gap << ansj-ansi-1 << gap << n-ansj);
    }
    else NO;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        02-06-2023 12:27
*/