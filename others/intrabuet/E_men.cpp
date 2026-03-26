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
    // cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
int weight, n;
vi v;
si out;
int dp[100][100001];

int rec(int i, int w){
    if (w == 0) return 1;
    if (i == n) return 0;
    if (dp[i][w] != -1) return dp[i][w];

    int notake = rec(i+1, w);
    if (v[i] > w) return dp[i][w] = notake;
    int take = rec(i+1, w-v[i]);
    if (take) out.insert(i+1);
    return dp[i][w] = notake + take;
}

void solve(int cases)
{
    memset(dp, -1, sizeof(dp));
    cin >> weight >> n;
    v.resize(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(v);

    int flag = rec(0, weight);
    if (!flag) print(0);
    else if (flag > 1) print(-1);
    else{
        int printed = 1;
        for (auto x: out){
            loop(i, printed, x) cout << i << gap;
            printed = x+1;
        }
        loop(i, printed, n+1) cout << i << gap;
        cout << endl;
    }
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        29-05-2023 04:09
*/