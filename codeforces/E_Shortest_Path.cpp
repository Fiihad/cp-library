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
class graph {
    vector<set<int>> adj_list;
    bool directed;
    int n; // number of vertices

public:
    map<pii, si> forbid;

    graph(int i, bool dir=true){
        n = i;
        adj_list.resize(n+1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
    }
    void add_edge(int from, int to){
        adj_list[from].insert(to);
        if (!directed) adj_list[to].insert(from);
    }

    // Dijkstra Algorithm
    vector<pii> parent_dijkstra;
    vi distance_dijkstra;
    void dijkstra(int source)
    {
        parent_dijkstra.resize(n+1, {-1, -1});
        distance_dijkstra.resize(n+1, LLONG_MAX);

        vector<bool> visited(n+1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        distance_dijkstra[source] = 0;
        q.push({0, source});

        while (!q.empty())
        {
            int vertex = q.top().second;
            q.pop();
            if (visited[vertex]) continue;
            visited[vertex] = true;

            for (auto edge: adj_list[vertex]){
                int neighbor = edge, weight = 1;

                if (distance_dijkstra[neighbor] > distance_dijkstra[vertex] + weight){
                    if (forbid[{parent_dijkstra[vertex].first, vertex}].count(neighbor)){
                        if (distance_dijkstra[neighbor] > distance_dijkstra[vertex] + weight + 2){
                            for (auto x : adj_list[vertex]){
                                if (!forbid[{parent_dijkstra[vertex].first, vertex}].count(x) && !forbid[{x, vertex}].count(neighbor)){
                                    distance_dijkstra[neighbor] = distance_dijkstra[vertex] + weight + 2;
                                    q.push({distance_dijkstra[neighbor], neighbor});
                                    parent_dijkstra[neighbor] = {vertex, x};
                                    break;
                                }
                            }
                        }
                        if (distance_dijkstra[neighbor] > distance_dijkstra[vertex] + weight + 1){
                            for (auto x : adj_list[parent_dijkstra[vertex].first]){
                                if (adj_list[x].count(vertex) && !forbid[{parent_dijkstra[vertex].first, x}].count(vertex) && !forbid[{x, vertex}].count(neighbor)){
                                    distance_dijkstra[neighbor] = distance_dijkstra[vertex] + weight + 1;
                                    q.push({distance_dijkstra[neighbor], neighbor});
                                    parent_dijkstra[neighbor] = {vertex, vertex};
                                    parent_dijkstra[vertex] = {x, x};
                                    break;
                                }
                            }
                        }
                        continue;
                    }

                    distance_dijkstra[neighbor] = distance_dijkstra[vertex] + weight;
                    q.push({distance_dijkstra[neighbor], neighbor});
                    parent_dijkstra[neighbor] = {vertex, vertex};
                }
            }
        }
    }
};

void solve(int cases)
{
    int n, m, k;
    cin >> n >> m >> k;

    graph g(n, false);
    loop(i,0,m){
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }
    loop(i,0,k){
        int a, b, c;
        cin >> a >> b >> c;
        g.forbid[{a, b}].insert(c);
    }
    g.dijkstra(1);

    if (g.distance_dijkstra[n] == LLONG_MAX) print(-1);
    else {
        vi path;
        for (int v = n; v != -1; v = g.parent_dijkstra[v].first){
            path.push_back(v);
            if (g.parent_dijkstra[v].first != g.parent_dijkstra[v].second)
                path.push_back(g.parent_dijkstra[v].first),
                path.push_back(g.parent_dijkstra[v].second);
        }
        reverse(all(path));
        print(path.size() - 1);
        for (auto x: path) cout << x << gap;
        cout << endl;
    }

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        22-06-2023 01:03
*/