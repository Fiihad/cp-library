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
struct dsu
{
    vector<int> parent;
    int count_of_components;
    dsu(int n) : parent(n + 1), count_of_components(n)
    {
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }
    void init(int n){
        parent.resize(n+1);
        count_of_components = n;
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
struct edge {
    int node1, node2, weight, index;
    edge(int f, int t, int w, int i){ node1 = f, node2 = t, weight = w, index = i; }
    bool operator <(edge &e){ return weight < e.weight; } // comparator for sorting
};

class graph {
public:
    int n; // number of vertices
    vector<edge> edge_list;
    dsu forest;
    si any, atleast;
    map<int, vector<edge>> weights;

    graph(int i) : n(i), forest(n) {}
    void add_edge(int from, int to, int weight, int index){
        edge_list.push_back({from, to, weight, index});
        weights[weight].push_back({from, to, weight, index});
    }

    int mst_kruskal()
    {
        sort(edge_list.begin(), edge_list.end());
        int total_weight = 0;
        dsu d(n);
        // forest.init(n);

        for (auto edge: edge_list){
            if (d.same_set(edge.node1, edge.node2)) continue;

            total_weight += edge.weight;
            if (weights[edge.weight].size() == 1) forest.merge(edge.node1, edge.node2), any.insert(edge.index);
            d.merge(edge.node1, edge.node2);
        }
        
        return total_weight;
    }

    void finalwork(){

        for (auto w : weights){
            if (w.second.size() <= 1) continue;

            map<pii, vi> m;
            for (auto x: w.second){
                if (forest.same_set(x.node1, x.node2)) continue;

                m[{min(forest.find_set(x.node1), forest.find_set(x.node2)), max(forest.find_set(x.node1), forest.find_set(x.node2))}].push_back(x.index);
            }
            for (auto x: m){
                if (x.second.size() == 1) any.insert(x.second.front());
                else for (auto y: x.second) atleast.insert(y);

                forest.merge(x.first.first, x.first.second);
            }
        }
    }
};

void solve(int cases)
{
    int n, m, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> m;

    graph g(n);
    loop(i, 0, m){
        int f, t, w;
        cin >> f >> t >> w;
        g.add_edge(f, t, w, i);
    }

    // g.listing();
    g.mst_kruskal();
    g.finalwork();
    

    loop(i, 0, m){
        if (g.any.count(i)) print("any");
        else if (g.atleast.count(i)) print("at least one");
        else print("none");
    }

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        26-06-2023 01:01
*/