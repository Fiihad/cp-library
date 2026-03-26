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

    vector<int> parent_bfs, distance;
    void bfs(int source)
    {
        parent_bfs.resize(n+1, -1);
        distance.resize(n+1, LLONG_MAX);

        vector<bool> visited(n+1, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;
        distance[source] = 0;

        while (!q.empty()){
            int vertex = q.front();
            // Do some work for every node here
            q.pop();

            for (auto nbr: adj_list[vertex]){
                if (!visited[nbr]){
                    q.push(nbr), visited[nbr] = true;
                    parent_bfs[nbr] = vertex;
                    distance[nbr] = distance[vertex] + 1;
                }
            }
        }
    }

    vector<int> parent_dfs;
    vi edges;
    void dfs(int source = 1)
    {
        edges.resize(n+1);
        parent_dfs.resize(n+1, -1);
        vector<bool> visited(n+1, false);
        dfs_helper(source, visited);
    }
    void dfs_helper(int source, vector<bool> &visited)
    {
        // Do some work for every node here
        visited[source] = true;
        edges[source] = 0;
        int flag = 0;

        for (auto nbr: adj_list[source]){
            if (!visited[nbr]){
                flag = 1;
                parent_dfs[nbr] = source;
                dfs_helper(nbr, visited);
                edges[source] += edges[nbr];
            }
        }
        if (!flag) edges[source] = 1;
    }
};

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;
    graph g(n);

    loop(i, 0, n-1){
        cin >> in >> out;
        g.add_edge(in, out);
    }

    cin >> q;
    g.dfs(1);
    loop(i, 0, q){
        cin >> in >> out;
        print(g.edges[in] * g.edges[out]);
    }

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        20-06-2023 20:53
*/