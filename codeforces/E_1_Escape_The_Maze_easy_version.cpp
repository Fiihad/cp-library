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
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
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
#define print(str) cout << str << '\n'
#define YES print("YES")
#define NO print("NO")
#define loop(i, begin, end) for (__typeof(end)i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
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
    si friends;

    graph(int i, bool dir=false){
        n = i;
        adj_list.resize(n+1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
        infected.resize(n+1, -2);
    }
    void add_edge(int from, int to){
        adj_list[from].insert(to);
        if (!directed) adj_list[to].insert(from);
    }

    vi infected;
    int infects(int i, int parent)
    {
        if (infected[i] != -2) return infected[i];
        if (friends.count(i)) return infected[i] = 0;
        int mini = LLONG_MAX;

        for (auto nbr: adj_list[i]){
            if (nbr != parent){
                if (infects(nbr, i) != -1) mini = min(mini, infects(nbr, i));
            }
        }
        if (mini == LLONG_MAX) return infected[i] = -1;
        else return infected[i] = mini + 1;
    }

    vector<int> parent_dfs;
    bool dfs(int source = 1)
    {
        parent_dfs.resize(n+1, -1);
        vector<bool> visited(n+1, false);
        return dfs_helper(source, 0, visited);
    }
    int count = 0;
    bool dfs_helper(int source, int step, vector<bool> &visited)
    {
        // Do some work for every node here
        visited[source] = true;
        if (infected[source] != -1 && infected[source] <= step){
            count++;
            return false;
        }

        bool flag = false, edge = true;

        for (auto nbr: adj_list[source]){
            if (!visited[nbr]){
                edge = false;
                flag |= dfs_helper(nbr, step+1, visited);
            }
        }
        return flag | edge;
    }
};

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> q;

    graph g(n);
    loop(i,0,q) cin >> in, g.friends.insert(in);

    loop(i,0,n-1){
        cin >> in >> out;
        g.add_edge(in, out);
    }

    g.infects(1, 0);
    #define printp(p) cout << '(' << p.first << ',' << ' ' << p.second << ')' << '\n';
    #define printx(array) { for (int i=0; i<array.size(); ++i) cout << array[i] << ' '; cout << '\n'; }
    #define printxp(array) { for (int i=0; i<array.size(); ++i) cout << '(' << array[i].first << ',' << ' ' << array[i].second << ')' << ' '; cout << '\n'; }
    // printx(g.infected);

    if (g.dfs()) print(-1);
    else print(g.count);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        15-08-2023 14:19
*/