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
class graph {
    vector<vector<int>> adj_list;
    bool directed;
    int n; // number of vertices

public:
    vi dp;
    graph(int i, bool dir=false){
        n = i;
        adj_list.resize(n+1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
        dp.resize(n+1, -1);
    }
    void add_edge(int from, int to){
        adj_list[from].push_back(to);
        if (!directed) adj_list[to].push_back(from);
    }

    void bfs(int source)
    {
        vector<bool> visited(n+1, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty()){
            int vertex = q.front();
            // Do some work for every node here
            cout << vertex << ' ';
            q.pop();

            for (auto nbr: adj_list[vertex])
                if (!visited[nbr]) q.push(nbr), visited[nbr] = true;
        }
        cout << endl;
    }

    void dfs(int source)
    {
        vector<bool> visited(n+1, false);
        dfs_helper(source, visited);
        cout << endl;
    }
    void dfs_helper(int source, vector<bool> &visited)
    {
        // Do some work for every node here
        cout << source << ' ';
        visited[source] = true;

        for (auto nbr: adj_list[source])
            if (!visited[nbr]) dfs_helper(nbr, visited);
    }
    int count(int node){
        if (dp[node] != -1) return dp[node];
        int o = 0;
        for (auto x: adj_list[node]){
            o++;
            o += count(x);
        }
        dp[node] = o;
        return o;
    }
};

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;
    graph g(n, true);
    loop(i,1,n){
        cin >> in;
        g.add_edge(in, i+1);
    }
    loop(i, 1, n+1) cout << g.count(i) << gap;
    cout << endl;
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        27-01-2023 01:32
*/