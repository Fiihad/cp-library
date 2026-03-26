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

    int specialnode = 0;
    vector<int> cyc;
    vector<int> extraedge;
    void printing(){
        vector<bool> visited(n+1, false);
        cyc.clear();

        int flag = 0;
        cycle(specialnode, specialnode, 0, flag, visited);

        set<int> cycs(all(cyc));
        for (auto nbr: adj_list[specialnode]){
            if (cycs.count(nbr) == 0) extraedge.push_back(nbr);
            if (extraedge.size() == 2) return;
        }
    }
    void cycle(int specialnode, int vertex, int parent, int &flag, vector<bool> &visited){
        visited[vertex] = true;
        if (adj_list[vertex].count(specialnode) && parent != specialnode)
            flag = 1;

        for (auto nbr : adj_list[vertex])
            if (!visited[nbr] && !flag) 
                cycle(specialnode, nbr, vertex, flag, visited);
        
        if (flag) cyc.push_back(vertex);
    }

    bool detection(){
        loop(i, 1, n+1){
            int flag = 0;
            vector<bool> visited(n+1, false);
            cycle(i, i, 0, flag, visited);
            if (flag && adj_list[i].size() >= 4){
                specialnode = i;
                return true;
            }
        }
        return false;
    }
};

void solve(int cases)
{
    int n, q;
    int in, out;
    cin >> n >> q;
    graph g(n);
    loop(i, 0, q)
        cin >> in >> out, g.add_edge(in, out);

    if (g.detection()){
        YES;
        g.printing();
        print(g.cyc.size()+2);
        loop(i,1,g.cyc.size()) print(g.cyc[i-1] << gap << g.cyc[i]);
        print(g.cyc.back() << gap << g.cyc.front());
        print(g.specialnode << gap << g.extraedge.front());
        print(g.specialnode << gap << g.extraedge.back());
    }
    else NO;

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        05-06-2023 23:01
*/