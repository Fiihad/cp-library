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
    vector<vector<pair<int, int>>> adj_list;
    bool directed;
    int n; // number of vertices

public:
    mi train, usedtrain;
    graph(int i, bool dir=true){
        n = i;
        adj_list.resize(n+1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
    }
    void add_edge(int from, int to, int weight){
        adj_list[from].push_back({to, weight});
        // edge_list.push_back({from, to, weight});

        if (!directed)
            adj_list[to].push_back({from, weight});
            // edge_list.push_back({to, from, weight});
    }

    // Dijkstra Algorithm
    int ans = 0;
    vector<int> parent_dijkstra, distance_dijkstra;
    void dijkstra(int source)
    {
        parent_dijkstra.resize(n+1, -1);
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
                int neighbor = edge.first, weight = edge.second;

                if (distance_dijkstra[neighbor] >= distance_dijkstra[vertex] + weight){
                    if (usedtrain.count(neighbor)) ans++, usedtrain.erase(usedtrain.find(neighbor));
                    distance_dijkstra[neighbor] = distance_dijkstra[vertex] + weight;
                    q.push({distance_dijkstra[neighbor], neighbor});
                    parent_dijkstra[neighbor] = vertex;
                }
            }

            if (vertex == 1){
                for (auto x: train){
                    int neighbor = x.first;
                    if (distance_dijkstra[neighbor] > train[neighbor]){
                        distance_dijkstra[neighbor] = train[neighbor];
                        q.push({distance_dijkstra[neighbor], neighbor});
                        usedtrain[neighbor] = train[neighbor];
                        ans--;
                    }
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
    for (int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }
    int ans = 0;
    for (int i = 0; i < k; ++i){
        int u, v, w;
        cin >> v >> w;
        if (g.train.count(v)) {
            g.train[v] = min(g.train[v], w);
            ans++;
        }
        else g.train[v] = w;
    }
    g.dijkstra(1);

    ans += g.ans;
    ans += g.train.size();
    print(ans);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        21-06-2023 21:28
*/