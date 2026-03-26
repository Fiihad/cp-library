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
class graph {
    bool directed;
    int n; // number of vertices

public:
    vector<vector<int>> adj_list;
    vi nodes;

    graph(int i, bool dir=false){
        n = i;
        nodes.resize(n+1);
        adj_list.resize(n+1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
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

    int dfs(int source)
    {
        vector<bool> visited(n+1, false);
        return nodes[source] = dfs_helper(source, visited);
    }
    int dfs_helper(int source, vector<bool> &visited)
    {
        int out = 1;
        visited[source] = true;

        for (auto nbr: adj_list[source])
            if (!visited[nbr]) out += dfs_helper(nbr, visited);

        return nodes[source] = out;
    }
};

#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }
// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;
    graph g(n);
    vector<pii> edges;

    loop(i,0,n-1){
        cin >> in >> out;
        g.add_edge(in, out);
        edges.push_back({in, out});
    }
    g.dfs(1);
    // printx(g.nodes);

    si outs;
    loop(i,0,n-1) {
        if (g.nodes[edges[i].first] < g.nodes[edges[i].second]) swap(edges[i].first, edges[i].second);
        int a1 = g.nodes[edges[i].second];
        int a2 = g.nodes[1]-a1;
        // for (auto x: g.adj_list[edges[i].first]) a2 -= g.nodes[x];
        // bug(i, edges[i].first, edges[i].second, a1, a2);
        if (a2%3==0 && a1%3==0) outs.insert(i+1);
    }
    if (n%3 || outs.size() < n/3-1) print(-1);
    else{
        print(outs.size());
        printx(outs);
    }
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        24-05-2023 13:47
*/