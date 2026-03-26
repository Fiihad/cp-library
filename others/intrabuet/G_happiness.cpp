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

// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

// SOLVE STARTS HERE
vi happ;

class graph {
public:
    vector<vector<int>> adj_list;
    bool directed;
    int n; // number of vertices
    vector<mi> dp;
    map<pii, int> edges;
    vector<bool> visited;

    vi tracked;

    graph(int i, bool dir=false){
        n = i;
        dp.resize(n+1);
        visited.resize(n+1, 0);
        adj_list.resize(n+1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
    }
    void add_edge(int from, int to, int value){
        adj_list[from].push_back(to);
        if (!directed) adj_list[to].push_back(from);

        edges[{from, to}] = value;
        edges[{to, from}] = value;
    }

    pii solve(int vertex){
        int out1 = rec(vertex, 0);
        tracking(vertex, 0);
        int lastnode = tracked.back();
        int out2 = rec(lastnode, 0);
        tracked.clear();
        return {out2, lastnode};
    }

    int rec(int vertex, int parent){
        visited[vertex] = true;
        if (dp[vertex].count(parent)) return dp[vertex][parent];
        int maxi = happ[vertex];

        for (auto nbr: adj_list[vertex]){
            if (nbr == parent) continue;
            maxi = max(maxi, rec(nbr, vertex) + happ[vertex]);
        }

        return dp[vertex][parent] = maxi + edges[{vertex, parent}];
    }

    void tracking(int flag, int parent){
        tracked.push_back(flag);
        int maxi = 0, next = -1;

        for (auto nbr: adj_list[flag]){
            if (nbr == parent) continue;
            if (dp[nbr][flag] > maxi) maxi = dp[nbr][flag], next = nbr;
        }
        if (next != -1) tracking(next, flag);
    }
};

int32_t main()
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> q;
    happ.resize(n+1);
    loop(i,1,n+1) cin >> happ[i];

    graph g(n);
    loop(i,0,q){
        cin >> in >> out >> flag;
        g.add_edge(in, out, flag);
    }

    loop(i,1,n+1){
        if (g.adj_list[i].size() > 1 || g.visited[i]) continue;
        auto kijani = g.solve(i);
        if (kijani.first > maxi) maxi = kijani.first, flag = kijani.second;
    }
    print(maxi);

    g.tracking(flag, 0);
    print(g.tracked.size());
    #define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
    printx(g.tracked);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        29-05-2023 15:38
*/