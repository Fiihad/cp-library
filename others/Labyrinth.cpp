/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার,
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define debug 0
#else
#define fast ;
#define debug 1
#endif

// for policy based data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// ordered_set: extends set to find_by_order and order_of_key
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// some typedefs for my convenience
// #define int long long int
#define double long double
#define pii pair<int, int>
#define vi vector<int>
#define si set<int>
#define msi multiset<int>
#define mi map<int, int>
// some speedup macros
#define gap ' '
#define endl '\n'
#define print(str) cout << str << endl
#define YES print("YES")
#define NO print("NO")
#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define scanx(array) { for (auto &x: array) cin >> x; }
#define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }
#define loop(i, begin, end) for(__typeof(end)i=begin-(begin>end); i!=end-(begin>end); i+=1-2*(begin>end))
#define loopit(v) for (auto it=v.begin(); it!=v.end(); it++)
#define all(v) v.begin(), v.end()

// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

void solve(int cases);
int32_t main()
{
    fast // fast IO! but only when online_judge
    int test_cases = 1;
    // cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++) solve(cases);

    return 0;
}

// SOLVE STARTS HERE
int n=1000, q=1000;
string in;
pii flagA = {-1, -1}, flagB = {-1, -1};
vector<string> paths(n);
string out;
vector<vi> dist(n, vi(q, -1));
vector<vector<tuple<int, int, char>>> parents(n, vector<tuple<int, int, char>>(q));

void bfs(int i, int j)
{
    queue<pii> q;
    q.push({i, j});
    dist[i][j] = 0;
    while (!q.empty())
    {
        int ci = q.front().first, cj = q.front().second;
        if (ci == flagB.first && cj == flagB.second) return;
        q.pop();

        if (ci>0 && dist[ci-1][cj]==-1 && paths[ci-1][cj] != '#'){
            dist[ci-1][cj] = dist[ci][cj] + 1;
            parents[ci-1][cj] = {ci, cj, 'U'};
            q.push({ci-1, cj});
        }
        if (ci<paths.size()-1 && dist[ci+1][cj]==-1 && paths[ci+1][cj] != '#'){
            dist[ci+1][cj] = dist[ci][cj] + 1;
            parents[ci+1][cj] = {ci, cj, 'D'};
            q.push({ci+1, cj});
        }
        if (cj>0 && dist[ci][cj-1]==-1 && paths[ci][cj-1] != '#'){
            dist[ci][cj-1] = dist[ci][cj] + 1;
            parents[ci][cj-1] = {ci, cj, 'L'};
            q.push({ci, cj-1});
        }
        if (cj<paths[ci].size()-1 && dist[ci][cj+1]==-1 && paths[ci][cj+1] != '#'){
            dist[ci][cj+1] = dist[ci][cj] + 1;
            parents[ci][cj+1] = {ci, cj, 'R'};
            q.push({ci, cj+1});
        }
    }
}

void solve(int cases)
{
    // freopen("test_input.txt", "r", stdin);
    cin >> n >> q;

    loop(i,0,n){
        cin >> in;
        paths[i] = in;
        if (flagA.first == -1 || flagB.first == -1) loop(j,0,q){
            if (in[j] == 'A') flagA = {i, j};
            else if (in[j] == 'B') flagB = {i, j};
        }
    }
    bfs(flagA.first, flagA.second);

    if (dist[flagB.first][flagB.second] != -1){
        YES;
        // print(dist[flagB.first][flagB.second]);
        int i=flagB.first, j=flagB.second;
        string output;
        while (!(i==flagA.first && j==flagA.second)){
            int parenti = get<0>(parents[i][j]), parentj = get<1>(parents[i][j]);
            output.push_back(get<2>(parents[i][j]));
            i = parenti;
            j = parentj;
        }
        reverse(all(output));
        print(output.size());
        print(output);
    }
    else NO;
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        28-01-2023 18:29
*/