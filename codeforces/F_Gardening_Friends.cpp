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

class graph {
    vector<vector<int>> adj_list;
    bool directed;
    int n; // number of vertices
    vi fromroot, fromleaf;
    int leaf;

public:
    graph(int i, bool dir=false){
        n = i;
        adj_list.resize(n+1); // n+1 so will work for both 1 or 0 based indexing
        fromroot.resize(n+1);
        fromleaf.resize(n+1);
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
        fromroot[source] = 0;
        visited[source] = true;

        while (!q.empty()){
            int vertex = q.front();
            q.pop();

            for (auto nbr: adj_list[vertex])
                if (!visited[nbr]) fromroot[nbr]=fromroot[vertex]+1, q.push(nbr), visited[nbr] = true;

            if (q.empty()) leaf = vertex;
        }
    }
    void bfs1()
    {
        int source = leaf;
        vector<bool> visited(n+1, false);
        queue<int> q;

        q.push(source);
        fromleaf[source] = 0;
        visited[source] = true;

        while (!q.empty()){
            int vertex = q.front();
            q.pop();

            for (auto nbr: adj_list[vertex])
                if (!visited[nbr]) fromleaf[nbr]=fromleaf[vertex]+1, q.push(nbr), visited[nbr] = true;
        }
    }

    int calc(int k, int c)
    {
        int profit = 0;
        loop(i,1,n+1)
            profit = max(profit, k*fromleaf[i]-c*fromroot[i]);
        return profit;
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

void solve(int cases)
{
    int n, k, c, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> k >> c;

    graph g(n);
    loop(i,0,n-1){
        cin >> in >> q;
        g.add_edge(in, q);
    }

    g.bfs(1);
    g.bfs1();
    print(g.calc(k, c));

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        09-05-2023 14:00
*/