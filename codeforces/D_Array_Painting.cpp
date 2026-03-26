/*
        আমার অমনোযোগী ক্লাসরুম... আমার মগজে নষ্ট ধুম...
        আমার বাহিরে বুদ্ধ, ভেতরে হিটলার... লাশের মোড়কে ঘুম :)
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
// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

// some typedefs for my convenience
#define int long long int
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
// some speedup macros
#define print(str) cout << str << '\n'
#define YES print("YES")
#define NO print("NO")
#define loop(i, begin, end) for (__typeof(end)i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
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
int ans, n;
int dp[200001][2][2];

int rec(int i, int k, int next_color){
    if (i == n) return 0;
    if (dp[i][k][next_color] != -1) return dp[i][k][next_color];

    if (v[i] == 2) return dp[i][k][next_color] = !next_color + rec(i+1, 0, 1);
    if (i != n-1 && v[i+1] == 2 && !next_color) return dp[i][k][next_color] = rec(i+1, 0, 0);

    if (v[i] == 0 || k){
        if (next_color) return dp[i][k][next_color] = rec(i+1, 0, 0);

        if (i == n-1 || v[i+1] != 1) return dp[i][k][next_color] = 1 + rec(i+1, 0, 0);
        return dp[i][k][next_color] = min(1 + rec(i+1, 0, 0), rec(i+1, 1, 0));
    }

    return dp[i][k][next_color] = !next_color + rec(i+1, 0, 1);
}

void solve(int cases)
{
    memset(dp, -1, sizeof(dp));
    int in;
    cin >> n;
    v.resize(n);
    #define scanx(array) { for (int i=0; i<array.size(); ++i) cin >> array[i]; }
    scanx(v);

    print(rec(0, 0, 0));
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        27-07-2023 21:19
*/