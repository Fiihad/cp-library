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
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
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
#define gap ' '
#define endl '\n'
#define print(str) cout << str << endl
#define YES print("YES")
#define NO print("NO")
#define loop(i, begin, end) for (__typeof(end) i = begin - (begin > end); i != end - (begin > end); i += 1 - 2 * (begin > end))
#define all(v) v.begin(), v.end()

const int INFINITE = 2e18;

// SOLVE STARTS HERE
class graph
{
public:
    vector<vector<pair<int, int>>> adj_list;
    bool directed;
    int n; // number of vertices
    vector<pair<int, pii>> edge_list;

    graph(int i, bool dir = true)
    {
        n = i;
        adj_list.resize(n + 1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
    }
    void add_edge(int from, int to, int weight)
    {
        adj_list[from].push_back({to, weight});
        if (!directed)
            adj_list[to].push_back({from, weight});
        edge_list.push_back({weight, {from, to}});
        edge_list.push_back({weight, {to, from}});
    }

    // Bellman-Ford Algorithm
    vector<int> parent_bellford, distance_bellford;
    bool bellford(int source)
    // returns true if sp is valid, ie. negetive edge cycle not present
    {
        sort(all(edge_list));
        parent_bellford.resize(n + 1, -1);
        distance_bellford.resize(n + 1, INFINITE);
        distance_bellford[source] = 0;
        bool cycle_present;

        // n-1 times for path calculation and nth time for neg cycle detection
        for (int i = 0; i < n - 1; ++i)
        {

            // iterating through the edges using adj list
            for (auto x : edge_list)
            {
                int node1 = x.second.first, node2 = x.second.second;
                int weight = x.first;
                if (distance_bellford[node1] == INFINITE)
                    continue;

                if (distance_bellford[node2] <= distance_bellford[node1] + weight)
                    continue;

                distance_bellford[node2] = distance_bellford[node1] + weight;
                parent_bellford[node2] = node1;
            }
        }

        return !cycle_present;
    }

    deque<int> path;
    void print_path(int destination, int mode = 2)
    // creates the path and prints it
    // mode 1: bellman-ford, mode 2: dijkstra
    {
        int vertex = destination;
        while (vertex != -1)
        {
            path.push_back(vertex);
            vertex = mode == 1 ? parent_bellford[vertex] : parent_bellford[vertex];
        }
        reverse(path.begin(), path.end());
    }
};

int32_t main()
{
    fast int n, m;
    cin >> n >> m;

    int matrix[n + 1][n + 1];
    graph g(n, false);

    // initializing distances
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            matrix[i][j] = (i == j) ? 0 : INFINITE;

    // inputting the edges
    int u, v, weight;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> weight;
        matrix[u][v] = matrix[v][u] = min(matrix[u][v], weight);
        g.add_edge(u, v, weight);
    }

    // the dp loop
    for (int k = 1; k <= n; ++k)
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

    if (matrix[1][n] == INFINITE)
        print("inf");
    else
    {
        g.bellford(n);
        g.print_path(1);

        string output;
        vector<pair<string, int>> outv;
        loop(i, 0, n) output.push_back('1');

        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
        vector<bool> visited(n + 1, false);
        int prevvert = n;
        int currenttime = 0;
        vi startingtime(n + 1, 0);

        pq.push({0, {n, 0}});
        while (!pq.empty())
        {
            int weight = pq.top().first, vertex = pq.top().second.first, parent = pq.top().second.second;
            pq.pop();
            if (visited[vertex]) continue;
            visited[vertex] = true;

            weight -= currenttime;
            output[prevvert - 1] = '0';
            if (weight) outv.push_back({output, weight});
            if (vertex == 1) break;
            prevvert = vertex;
            currenttime += weight;
            startingtime[vertex] = currenttime;

            for (auto edge : g.adj_list[vertex])
                pq.push({currenttime + edge.second, {edge.first, vertex}});
        }

        print(matrix[1][n] << gap << outv.size());
        loop(i, 0, outv.size()) print(outv[i].first << gap << outv[i].second);
    }
}
/*
        Fihad arRahman
        hellofihad@gmail.com
        01-07-2023 01:33
*/