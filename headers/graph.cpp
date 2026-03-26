// 21-01-2023 20:06
#include <bits/stdc++.h>
using namespace std;

class graph {
    vector<vector<int>> adj_list;
    bool directed;
    int n; // number of vertices

public:
    graph(int i, bool dir=false){
        n = i;
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

    void dfs(int source)
    {
        vector<bool> visited(n+1, false);
        dfs_helper(source, visited);
        cout << endl;
    }
    void dfs_helper(int source, vector<bool> &visited)
    {
        // Do some work for every node here
        cout << source << ' ';
        visited[source] = true;

        for (auto nbr: adj_list[source])
            if (!visited[nbr]) dfs_helper(nbr, visited);
    }
};

int main (void)
{
    graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);

    g.bfs(0);
    g.dfs(0);
    return 0;
}