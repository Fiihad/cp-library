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
#define debug 1
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
    // cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++) solve(cases);

    return 0;
}

// SOLVE STARTS HERE
pair<bool, string> dfs(string out, vector<string> &paths, pii parent, int i, int j, vector<vector<pair<int, string>>> &dp, vector<vi> &visited){
    // bug(i, j);
    if (dp[i][j].first != -1) return dp[i][j];
    // visited[i][j] = true;
    if (paths[i][j] == 'B'){
        dp[i][j] = {true, out};
        return dp[i][j];
    }
    visited[i][j] = true;

    bool possible = false;
    int flag = LLONG_MAX;
    string output;
    if (i>0 && !visited[i-1][j] && paths[i-1][j] != '#'){
        auto check = dfs(out, paths, {i, j}, i-1, j, dp, visited);
        if (check.first){
            check.second.push_back('U');
            bug(check.second, i, j);
            // return {true, check.second};
            possible = true;
            if (check.second.size() < flag) flag = check.second.size(), output = check.second;
        }
    }
    if (i<paths.size()-1 && !visited[i+1][j] && paths[i+1][j] != '#'){
        auto check = dfs(out, paths, {i, j}, i+1, j, dp, visited);
        if (check.first){
            check.second.push_back('D');
            bug(check.second, i, j);
            // return {true, check.second};
            possible = true;
            if (check.second.size() < flag) flag = check.second.size(), output = check.second;
        }
    }
    if (j>0 && !visited[i][j-1] && paths[i][j-1] != '#'){
        auto check = dfs(out, paths, {i, j}, i, j-1, dp, visited);
        if (check.first){
            check.second.push_back('L');
            bug(check.second, i, j);
            // return {true, check.second};
            possible = true;
            if (check.second.size() < flag) flag = check.second.size(), output = check.second;
        }
    }
    bug(visited[i][j+1], i, j);
    if (j<paths[i].size()-1 && !visited[i][j+1] && paths[i][j+1] != '#'){
        auto check = dfs(out, paths, {i, j}, i, j+1, dp, visited);
        if (check.first){
            check.second.push_back('R');
            bug(check.second, i, j);
            // return {true, check.second};
            possible = true;
            if (check.second.size() < flag) flag = check.second.size(), output = check.second;
        }
    }
    dp[i][j] = {possible, output};
    visited[i][j] = false;
    return {possible, output};
}

void solve(int cases)
{
    int n, q;
    string in;
    pii flag = {-1, -1};
    cin >> n >> q;
    vector<vector<pair<int, string>>> dp(n, vector<pair<int, string>>(q, {-1, ""}));
    vector<string> paths(n);

    loop(i,0,n){
        cin >> in;
        paths[i] = in;
        if (flag.first == -1) loop(j,0,q)
            if (in[j] == 'A') flag = {i, j};
    }
    string out;
    vector<vi> visited(n, vi(q, false));

    auto check = dfs(out, paths, {-1, -1}, flag.first, flag.second, dp, visited);
    if (check.first){
        reverse(all(check.second));
        print("YES");
        print(check.second.size());
        print(check.second);
    }
    else print("NO");
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        27-01-2023 16:42
*/