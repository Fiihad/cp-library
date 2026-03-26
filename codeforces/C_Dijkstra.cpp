// 21-06-2023 13:36
#include <bits/stdc++.h>
using namespace std;

#define int long long

class graph {
    vector<vector<pair<int, int>>> adj_list;
    bool directed;
    int n; // number of vertices

public:
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
                int neighbor = edge.first, weight = abs(edge.second);

                if (distance_dijkstra[neighbor] > distance_dijkstra[vertex] + weight){
                    distance_dijkstra[neighbor] = distance_dijkstra[vertex] + weight;
                    q.push({distance_dijkstra[neighbor], neighbor});
                    parent_dijkstra[neighbor] = vertex;
                }
            }
        }
    }

    void print_path(int destination, int mode)
    // mode 1: bellman-ford, mode 2: dijkstra
    {
        vector<int> path;
        int vertex = destination; 
        while (vertex != -1){
            path.push_back(vertex);
            vertex = mode == 1 ? 0 : parent_dijkstra[vertex];
        }
        reverse(path.begin(), path.end());
        
        for (auto x: path) cout << x << " ";
        cout << endl;
    }
};

int32_t main (void)
{
    int n, m;
    cin >> n >> m;
    graph g(n, false);
    for (int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }

    int source = 1, destination = n;

    g.dijkstra(source);
    if (g.distance_dijkstra[destination] != LLONG_MAX)
        g.print_path(destination, 2);
    else cout << -1 << endl;

    return 0;
}