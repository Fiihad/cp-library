/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার
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
#define si ordered_set
#define msi ordered_multiset
#define mi map<int, int>
#define mmi multimap<int, int>
// some speedup macros
#define gap ' '
#define endl '\n'
#define pb push_back
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

int dfs(vector<vi> &adj_list, set<int> &s, vector<bool> &visited, int node, int start_node, int once_done){
    // bug(node);
    visited[node] = true;
    bool exist = s.count(node);
    if (exist) s.erase(node);
    if (s.empty()) return 1;

    for (auto nbr: adj_list[node]){
        if (visited[nbr]) continue;
        int check = dfs(adj_list, s, visited, nbr, start_node, once_done);
        if (check == 1) return check;
        if (check == 0 && (once_done || start_node != node)){
            // bug(node, once_done, start_node);
            return check;
        }
        if (check == 0 && start_node == node) once_done = 1;
    }
    if (exist) return 0;
    return 2;
}

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;

    vector<vi> adj_list(n+1);
    loop(i,0,n-1){
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    cin >> q;
    while (q--){
        int m;
        cin >> m;
        set<int> s;
        loop(i,0,m){
            int a;
            cin >> a;
            s.insert(a);
        }
        vector<bool> is_visited(n+1, false);
        // for (auto x: s){
        //     auto t = s;
        //     vector<bool> is_visited(n+1, false);
        //     flag = dfs(adj_list, t, is_visited, x);
        //     if (flag) break;
        // }
        flag = dfs(adj_list, s, is_visited, *s.begin(), *s.begin(), 0);
        if (flag) print("YES");
        else print("NO");
    }
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        24-01-2023 14:08
*/