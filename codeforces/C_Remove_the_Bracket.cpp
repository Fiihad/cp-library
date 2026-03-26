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
    cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

int dfs(int i, int x, int n, vi &v, vector<pii> &ps, vector<vi> &dp, int mode){
    if (dp[i][mode] != -1) return dp[i][mode];
    // bug(i, x);
    if (i==n-1){
        dp[i][mode] = x*v[i];
        return x*v[i];
    }

    int out = min((ps[i-1].first * x + dfs(i+1, ps[i-1].second, n, v, ps, dp, 2)), (ps[i-1].second * x + dfs(i+1, ps[i-1].first, n, v, ps, dp, 1)));
    // bug(i, x, ps[i-1].first, ps[i-1].second, out);
    dp[i][mode] = out;
    return out;
}

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> q;
    vi v(n);
    #define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
    #define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
    #define scanx(array) { for (auto &x: array) cin >> x; }
    #define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }
    scanx(v);

    int flag1 = v[0];
    vector<pii> ps;
    vector<vi> dp(n+1, vi(3, -1));
    loop(i,1,n-1){
        int x, y;
        if (v[i] > q){
            x = q;
            y = v[i] - q;
        }
        else{
            x = 0;
            y = v[i];
        }
        // out += flag1 * x;
        // flag1 = y;
        ps.push_back({x, y});
    }
    // out += flag1 * v.back();

    // int mode = 0;
    // if (v[0]*max(ps[0].first, ps[0].second) < v[n-1]*max(ps[n-3].first, ps[n-3].second)) mode = 1;
    // for (auto &x: ps){
    //     if (mode == 0){
    //         if (x.first > x.second) swap(x.first, x.second);
    //     }
    //     if (mode == 1){
    //         if (x.first < x.second) swap(x.first, x.second);
    //     }
    // }
    // printxp(ps);

    // loop(i,0, n-2){
    //     out += flag1 * ps[i].first;
    //     flag1 = ps[i].second;
    // }
    // out += flag1 * v.back();

    out = dfs(1, v[0], n, v, ps, dp, 1);
    print(out);
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        29-01-2023 21:20
*/