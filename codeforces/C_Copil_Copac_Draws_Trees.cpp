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

void solve(int cases);
int32_t main()
{
    fast
    int total_cases = 1;
    std::cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
class graph {
public:

    vector<vector<int>> adj_list;
    bool directed;
    int n, out; // number of vertices
    vi serial, reading;
    map<pii, int> edgeserial;

    graph(int i, bool dir=false){
        n = i;
        out = 0;
        serial.resize(n+1, -1);
        reading.resize(n+1);
        adj_list.resize(n+1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
    }
    void add_edge(int from, int to){
        adj_list[from].push_back(to);
        if (!directed) adj_list[to].push_back(from);
    }

    void bfs(int source = 1)
    {
        vector<bool> visited(n+1, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;
        reading[source] = 1;

        while (!q.empty()){
            int vertex = q.front();
            // Do some work for every node here
            // cout << vertex << ' ';
            q.pop();

            for (auto nbr: adj_list[vertex]){
                if (!visited[nbr]){
                    serial[nbr] = max(edgeserial[{nbr, vertex}], edgeserial[{vertex, nbr}]);

                    if (serial[nbr] < serial[vertex]) reading[nbr] = reading[vertex]+1;
                    else reading[nbr] = reading[vertex];
                    // bug(nbr, vertex, serial[nbr], serial[vertex], reading[nbr], reading[vertex]);
                    q.push(nbr), visited[nbr] = true;
                }
            }
        }
    }

    void dfs(int source = 1)
    {
        vector<bool> visited(n+1, false);
        loop(i, 1, n+1){
            if (!visited[i]){
                out++;
                dfs_helper(i, visited);
            }
        }
    }
    void dfs_helper(int source, vector<bool> &visited)
    {
        // Do some work for every node here
        // cout << source << ' ';
        visited[source] = true;

        for (auto nbr: adj_list[source])
            if (!visited[nbr]) dfs_helper(nbr, visited);
    }
};

void solve(int cases)
{
    int n;
    cin >> n;
    graph g(n);

    int e1, e2;
    loop(i,0,n-1){
        cin >> e1 >> e2;
        g.edgeserial[{e1, e2}] = i;
        g.add_edge(e1, e2);
    }
    g.bfs();
    // printx(g.reading);
    print(*max_element(all(g.reading)));

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        29-05-2023 00:14
*/