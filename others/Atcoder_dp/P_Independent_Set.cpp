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
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
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
int mod = 1e9+7;
class graph {
    vector<set<int>> adj_list;
    bool directed;
    int n; // number of vertices

public:
    graph(int i, bool dir=false){
        n = i;
        adj_list.resize(n+1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
        dp.resize(n+1, vi(2, -1));
    }
    void add_edge(int from, int to){
        adj_list[from].insert(to);
        if (!directed) adj_list[to].insert(from);
    }

    vector<vi> dp;
    int rec (int i, int j, int parent){
        if (dp[i][j] != -1) return dp[i][j];
        int temp2 = 1, temp1 = 1;

        for (auto x: adj_list[i])
            if (x != parent)
                temp1 *= rec(x, 1, i)%mod, temp1 %= mod;
        int ans = temp1;

        if (j) {
            for (auto x: adj_list[i])
                if (x != parent)
                    temp2 *= rec(x, 0, i)%mod, temp2 %= mod;
            ans += temp2;
        }
        return dp[i][j] = max(ans, j+1)%mod;
    }
};

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;

    graph g(n);
    loop (i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b);
    }

    print(g.rec(1, 1, -1));
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        02-07-2023 14:43
*/