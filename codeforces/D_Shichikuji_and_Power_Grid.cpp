/*
        আমার অমনোযোগী ক্লাসরুম... আমার মগজে নষ্ট ধুম...
        আমার বাহিরে বুদ্ধ, ভেতরে হিটলার... লাশের মোড়কে ঘুম :)
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
// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
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
struct dsu
{
    vector<int> parent;
    int count_of_components;
    dsu(int n) : parent(n + 1), count_of_components(n)
    {
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }
    int find_set(int i) { return (parent[i] == i ? i : (parent[i] = find_set(parent[i]))); }
    bool same_set(int i, int j) { return find_set(i) == find_set(j); }
    int merge(int i, int j)
    {
        if ((i = find_set(i)) == (j = find_set(j)))
            return -1;
        
        count_of_components--;
        parent[i] = j;
        return j;
    }
};

class graph {
public:
    struct edge {
        int node1, node2, weight;
        edge(int f, int t, int w){ node1 = f, node2 = t, weight = w; }
        bool operator <(edge &e){ return weight < e.weight; } // comparator for sorting
    };

    int n; // number of vertices
    vector<edge> edge_list, mst_edges;

    graph(int i) : n(i), d(n) {}
    void add_edge(int from, int to, int weight){
        edge_list.push_back({from, to, weight});
    }

    dsu d;
    int mst_kruskal()
    {
        sort(edge_list.begin(), edge_list.end());
        int total_weight = 0;

        for (auto edge: edge_list){
            if (d.same_set(edge.node1, edge.node2)) continue;

            total_weight += edge.weight;
            mst_edges.push_back(edge);
            d.merge(edge.node1, edge.node2);
        }
        
        return total_weight;
    }
    void print_mst()
    {
        // print(mst_edges.size());
        for (auto x: mst_edges) if (x.node1) cout << x.node1 << ' ' << x.node2 << endl;
    }
};

inline int dist(int x1, int x2, int y1, int y2)
{
    return llabs(x1 - x2) + llabs(y1 - y2);
}

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;

    vector<pii> cordinates;
    loop (i,0,n){
        int x, y;
        cin >> x >> y;
        cordinates.push_back({x, y});
    }
    vi cost_of_power(n+1);
    loop(i,0,n) cin >> cost_of_power[i+1];
    vi kyen(n+1);
    loop(i,0,n) cin >> kyen[i+1];
    
    graph g(n);
    loop(i,1,n+1) g.add_edge(0, i, cost_of_power[i]);
    loop(i,0,n){
        loop(j,i+1,n){
            int weight = dist(cordinates[i].first, cordinates[j].first, cordinates[i].second, cordinates[j].second);
            weight *= (kyen[i+1]+kyen[j+1]);
            g.add_edge(i+1, j+1, weight);
        }
    }

    out = g.mst_kruskal();

    print(out);
    vi powers;
    for (auto x: g.mst_edges) if (x.node1 == 0) powers.push_back(x.node2);
    print(powers.size());
    for (auto x: powers) cout << x << gap;
    cout << endl;
    cout << g.mst_edges.size() - powers.size() << endl;
    g.print_mst();
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        10-07-2023 00:22
*/