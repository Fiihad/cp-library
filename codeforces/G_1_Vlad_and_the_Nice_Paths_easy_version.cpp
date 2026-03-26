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

// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}


void solve(int cases);

int M = 1e9+7;
int dp[101][101];
int32_t main()
{
    fast
    memset(dp, -1, sizeof(dp));
    int total_cases = 1;
    cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
int q, l;
vector<pii> indices;

int rec(int i, int j, vi &v)
{
    if (j==l) return 1;
    if (i<0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int take = 0, notake = 0;
    if (j%q){
        int index = -1;
        for (int k=i-1; k>=0; k--) if (v[k]==v[i]){
            take = rec(k, j+1, v);
            notake = rec(k, j, v);
        }
        // if (index!=-1) take = rec(index, j+1, v), notake = rec(index, j, v);
    }
    else take = rec(i-1, j+1, v), notake = rec(i-1, j, v);
    
    indices.push_back({i, j});
    bug(i,j,take,notake);
    return dp[i][j] = (take + notake)%M;
}

void solve(int cases)
{
    int n, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> q;
    vi v(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(v);

    l = n/q * q;
    for (; l >= 0; l -= q){
        // loop(i,0,101) loop(j,0,101) loop(k,0,101) dp[i][j][k] = -1;
        // memset(dp, -1, sizeof(dp));
        for (auto x: indices){
            // bug(get<0>(x), get<1>(x), get<2>(x));
            dp[x.first][x.second] = -1;
        }
        indices.clear();
        // bug(dp[n-1][0][0], dp[1][10][12]);
        out = rec(n-1, 0, v);
        if (out){
            print(out);
            return;
        }
    }
    // print(out);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        13-05-2023 14:14
*/