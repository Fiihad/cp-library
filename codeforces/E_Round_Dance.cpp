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
// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}
#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }

// SOLVE STARTS HERE
class graph {
    vector<set<int>> adj_list;
    bool directed;
    int n; // number of vertices

public:
    int ring=0, connec=0, noring=0;

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

    int dfs()
    {
        vector<bool> visited(n+1, false);
        loop(i,1,n+1){
            int prev_ring = ring;
            if (visited[i] == false){
                connec++, dfs_helper(i, visited, 0);
                if (ring == prev_ring) noring = 1;
            }
        }
        // cout << endl;
        return connec;
    }
    void dfs_helper(int source, vector<bool> &visited, int parent)
    {
        // Do some work for every node here
        // cout << source << ' ';
        visited[source] = true;
        bug(ring, source, parent);
        int prev_ring = ring;
        // printx(adj_list[source]);

        for (auto nbr: adj_list[source]){
            if (visited[nbr] && nbr!=parent && prev_ring==ring){
                ring++;
                bug(ring, nbr, source, parent);
            }
            if (!visited[nbr]) dfs_helper(nbr, visited, source);
        }
    }
};

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;

    graph g(n);
    loop(i,0,n){
        cin >> in;
        g.add_edge(i+1, in);
    }
    out = g.dfs();
    print(g.ring+g.noring << gap << out);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        19-05-2023 22:00
*/