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
    vector<set<pii>> adj_list;
    bool directed;
    int n; // number of vertices

public:
    vi dist, parent;

    graph(int i, bool dir=false){
        n = i;
        adj_list.resize(n+1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
        dist.resize(n+1, LLONG_MAX);
        parent.resize(n+1, 0);
    }
    void add_edge(pii from, pii to){
        adj_list[from.second].insert(to);
        if (!directed) adj_list[to.second].insert(from);
    }

    vi bfsv;
    void bfs(int source)
    {
        vector<bool> visited(n+1, false);
        queue<int> q;

        q.push(source);
        // bfsv.push_back(source);
        visited[source] = true;
        dist[source] = 0;

        while (!q.empty()){
            int vertex = q.front();
            // Do some work for every node here
            // cout << vertex << ' ';
            q.pop();
            bfsv.push_back(vertex);

            for (auto nbr: adj_list[vertex])
                if (!visited[nbr.second]) q.push(nbr.second), visited[nbr.second] = true;
        }
        cout << endl;
    }
};

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;
    vector<pii> pairs;

    graph g(n);
    loop(i,0,n-1){
        cin >> in >> out;
        pairs.push_back({in, out});
    }

    vector<int> v;
    mi ids;
    loop(i, 0, n) cin >> in, ids[in] = i, v.push_back(in);

    for (auto x: pairs){
        g.add_edge({ids[x.first], x.first}, {ids[x.second], x.second});
    }
    g.bfs(1);

    #define printp(p) cout << '(' << p.first << ',' << gap << p.second << ')' << endl;
    #define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
    #define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }
    // printx(g.bfsv);

    if (g.bfsv == v) print("Yes");
    else print("No");

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        03-06-2023 15:54
*/