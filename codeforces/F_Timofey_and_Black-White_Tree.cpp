/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার,
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define debug 0
#else
#define fast ;
#define debug 0
#endif

// for policy based data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// ordered_set: extends set to find_by_order and order_of_key
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// some typedefs for my convenience
#define int long long int
#define double long double
#define pii pair<int, int>
#define vi vector<int>
#define si set<int>
#define msi multiset<int>
#define mi map<int, int>
// some speedup macros
#define gap ' '
#define endl '\n'
#define print(str) cout << str << endl
#define YES print("YES")
#define NO print("NO")
#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define scanx(array) { for (auto &x: array) cin >> x; }
#define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }
#define loop(i, begin, end) for(__typeof(end)i=begin-(begin>end); i!=end-(begin>end); i+=1-2*(begin>end))
#define loopit(v) for (auto it=v.begin(); it!=v.end(); it++)
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
int32_t main()
{
    fast // fast IO! but only when online_judge
    int test_cases = 1;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++) solve(cases);

    return 0;
}

// SOLVE STARTS HERE

void dfs(int cur, int par, vector<vi> &gr, vi &dep, vector<vi> &Par, int n)
{
    int m = log2(n);
    dep[cur] = dep[par] + 1;
    Par[cur][0] = par;
    for (int j=1; j<m; j++) Par[cur][j] = Par[Par[cur][j-1]][j-1];
    for (auto x: gr[cur]){
        if (x!=par) dfs(x, cur, gr, dep, Par, n);
    }
}
int lca(int u, int v, vi &dep, vector<vi> &Par, int n, vector<vi> &dp)
{
    if (dp[u][v] != -1) return dp[u][v];
    if (dep[u] < dep[v]) swap(u, v);
    int m = log2(n);
    int diff = dep[u] - dep[v];
    bug(diff);
    for (int i=m-1; i>=0; i--)
        if ((diff >> i) & 1) u = Par[u][i];
    if (u == v){
        dp[u][v] = u;
        return u;
    }
    for (int i=m-1; i>=0; i--)
        if (Par[u][i] != Par[v][i]) u = Par[u][i], v = Par[v][i];
    dp[u][v] = Par[u][0];
    return Par[u][0];
}
int distance(int u, int v, vi &dep, vector<vi> &Par, int n, vector<vi> &dp)
{
    int l = lca(u, v, dep, Par, n, dp);
    bug(l);
    return dep[u] + dep[v] - 2*dep[l];
}

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> q;

    vector<vi> gr(n+1), Par(n+1, vi(log2(n)+1)), dp(n+1, vi(n+1, -1));
    vi dep(n+1, 0);

    vi v(n), output;
    v[0] = q;
    loop(i,1,n) cin >> v[i];

    loop(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1, 1, gr, dep, Par, n);
    // for (auto x: Par) printx(x);

    loop(i,1,n){
        if (mini == 1){
            output.push_back(1);
            continue;
        }
        for (int j=0; j<i; j++){
            int l = distance(v[j], v[i], dep, Par, n, dp);
            bug(l, mini, v[i], v[j]);
            mini = min(mini, l);
        }
        output.push_back(mini);
    }
    printx(output);
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        27-01-2023 22:53
*/