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
    // cin >> total_cases;
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

vi iscat;
int q, out;

class graph {
    vector<set<int>> adj_list;
    bool directed;
    int n; // number of vertices

public:
    graph(int i, bool dir=false){
        n = i;
        adj_list.resize(n+1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
    }
    void add_edge(int from, int to){
        adj_list[from].insert(to);
        if (!directed) adj_list[to].insert(from);
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
        dfs_helper(source, 0, visited);
        // cout << endl;
    }
    void dfs_helper(int source, int cats, vector<bool> &visited)
    {
        // bug(source, cats);
        visited[source] = true;
        int next_cat = 0;
        if (iscat[source-1]) next_cat = cats+1;
        if (cats > q) next_cat = q+1;
        int flag = 0;

        for (auto nbr: adj_list[source]){
            if (!visited[nbr]) flag = 1, dfs_helper(nbr, next_cat, visited);
        }
        if (!flag && next_cat <= q) out++;
    }
};

void solve(int cases)
{
    int n;
    cin >> n >> q;
    iscat.resize(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(iscat);

    graph g(n);
    loop(i,1,n){
        int e1, e2;
        cin >> e1 >> e2;
        g.add_edge(e1, e2);
    }

    g.dfs(1);
    print(out);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        03-06-2023 15:31
*/