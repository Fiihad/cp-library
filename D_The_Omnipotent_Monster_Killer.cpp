/*
        আমার অমনোযোগী ক্লাসরুম... আমার মগজে নষ্ট ধুম...
        আমার বাহিরে বুদ্ধ, ভেতরে হিটলার... লাশের মোড়কে ঘুম :)
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); // fast IO! but only when online_judge
#define debug 0
#else
#define fast ;
#define debug 1
#endif
// for debugging
#define bug(...) \
    if (debug)   \
    __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
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
#define loop(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(v) v.begin(), v.end()

void solve(int cases);
int32_t main()
{
    fast int total_cases = 1;
    cin >> total_cases;
    loop(cases, 1, total_cases + 1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE

class graph
{
    vector<set<int>> adj_list;
    bool directed;
    int n; // number of vertices

public:
    graph(int i, bool dir = false)
    {
        n = i;
        adj_list.resize(n + 1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
    }
    void add_edge(int from, int to)
    {
        adj_list[from].insert(to);
        if (!directed)
            adj_list[to].insert(from);
    }

    vector<int> parent_bfs, distance;
    void bfs(int source)
    {
        parent_bfs.resize(n + 1, -1);
        distance.resize(n + 1, INT_MAX);

        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;
        distance[source] = 0;

        while (!q.empty())
        {
            int vertex = q.front();
            // Do some work for every node here
            q.pop();

            for (auto nbr : adj_list[vertex])
            {
                if (!visited[nbr])
                {
                    q.push(nbr), visited[nbr] = true;
                    parent_bfs[nbr] = vertex;
                    distance[nbr] = distance[vertex] + 1;
                }
            }
        }
    }

    vector<int> parent_dfs;
    void dfs(int source = 1)
    {
        parent_dfs.resize(n + 1, -1);
        vector<bool> visited(n + 1, false);
        dfs_helper(source, visited);
    }

    void dfs_helper(int source, vector<bool> &visited)
    {
        // Do some work for every node here
        visited[source] = true;

        for (auto nbr : adj_list[source])
        {
            if (!visited[nbr])
            {
                parent_dfs[nbr] = source;
                dfs_helper(nbr, visited);
            }
        }
    }

    // Function to two-colorize the tree
    vector<int> color; // -1 indicates uncolored
    void two_colorize(int source = 1)
    {
        parent_dfs.resize(n + 1, -1);
        vector<bool> visited(n + 1, false);
        color.resize(n+1, -1);

        // Start DFS from the given source
        dfs_color(source, visited, 0);
    }

    void dfs_color(int source, vector<bool> &visited, int curr_color)
    {
        visited[source] = true;
        color[source] = curr_color;

        for (auto nbr : adj_list[source])
        {
            if (!visited[nbr])
            {
                dfs_color(nbr, visited, 1 - curr_color);
            }
        }
    }

    vi taken;
    int rec(int i) {
        
    }
};

void solve(int cases)
{
    int n, q, out = 0, sum = 0, sum2 = 0, maxi = LLONG_MIN, mini = LLONG_MAX;
    int in;
    cin >> n;

    vi v(n+1);
#define scanx(array)                           \
    {                                          \
        for (int i = 1; i < array.size(); ++i) \
            cin >> array[i];                   \
    }
    scanx(v);

    graph g(n + 1);
    g.taken.resize(n+1, 0);
    if (n > 1)
    {
        loop(i, 0, n - 1)
        {
            int a, b;
            cin >> a >> b;
            g.add_edge(a, b);
        }

        g.two_colorize(1);
    }

    for (auto x : v) out += x;
    if (sum < sum2)
        out += sum;
    else
        out += sum2;
    print(out);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        15-07-2024 22:22
*/