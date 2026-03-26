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
    cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

void dfs(int node, const vector<vi> &graph, vi &visited, vi &dp, vi &path, vi &iscyc) {
    visited[node] = 1;       // Mark node as visiting
    path.push_back(node);    // Add node to the current path

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, dp, path, iscyc);
        } else if (visited[neighbor] == 1) {
            // If the neighbor is visiting, we've found a cycle
            for (int i = path.size() - 1; i >= 0; --i) {
                dp[path[i]] = 0; // Mark nodes in the cycle
                iscyc[path[i]] = 1; // Mark nodes in the cycle as cyclic
                if (path[i] == neighbor) break; // Stop marking when we close the cycle
            }
        }
    }

    visited[node] = 2; // Mark node as fully processed
    path.pop_back();   // Remove the node from the current path
}

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;

    vector<vi> graph(n+1);
    loop(i, 1, n+1) cin >> in, graph[in].push_back(i);

    vi dp(n+1, -1);
    vi iscyc(n+1, 0);
    vi visited(n + 1, 0);      // Visited array to track states (0: not visited, 1: visiting, 2: processed)

    loop(i, 1, n + 1) {
        if (!visited[i]) {
            vi path;           // Store the current DFS path
            dfs(i, graph, visited, dp, path, iscyc);
        }
    }

    auto rec = [&](int node, auto &&rec)->int {
        if (dp[node]!= -1) return dp[node];
        dp[node] = 0;
        for (int neighbor : graph[node]) dp[node] += rec(neighbor, rec) + 1;
        return dp[node];
    };

    loop(i, 1, n + 1) { rec(i, rec); }

    loop(i, 1, n + 1) {
        if (iscyc[i])
            for (int neighbor : graph[i])
                if (!iscyc[neighbor]) dp[i] = max(dp[i], dp[neighbor] + 1);
        maxi = max(maxi, dp[i]);
    }
    print(maxi + 2);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        25-12-2024 15:26
*/