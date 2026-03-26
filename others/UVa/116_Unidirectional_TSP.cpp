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


vector<vi> matrix;
int m, n;

int dp[11][101][11];

int rec(int i1, int j1, int i2){
    if (dp[i1][j1][i2] != -1) return dp[i1][j1][i2];
    if (i1 == i2 && j1 == n-1) return dp[i1][j1][i2] = matrix[i2][j1];
    if (j1 == n-1) return dp[i1][j1][i2] = INT32_MAX * 10LL;

    int dest = i1-1;
    if (dest < 0) dest = m-1;
    int out = matrix[i1][j1] + rec(dest, j1+1, i2);

    dest = i1;
    out = min(out, matrix[i1][j1] + rec(dest, j1+1, i2));

    dest = i1+1;
    if (dest >= m) dest = 0;
    out = min(out, matrix[i1][j1] + rec(dest, j1+1, i2));

    return dp[i1][j1][i2] = out;
}

int32_t main()
{
    while (cin >> m)
    {
        memset(dp, -1, sizeof dp);
        // print(dp[0][1][2]);
        cin >> n;
        matrix.clear();
        matrix.resize(m);
        loop(i,0,m){
            loop(j,0,n){
                int x;
                cin >> x;
                matrix[i].push_back(x);
            }
        }
        int out = INT32_MAX, prevout = out, start, end;
        loop(i,0,m)
            loop(j,0,m){
                out = min(out, rec(i, 0, j));
                if (out != prevout) start = i, end = j;
                prevout = out;
            }
        
        
        int i = start;

        loop(j,1,n){
            cout << i + 1 << ' ';
            if (j == n-1) break;
            
            int d1 = i-1, d2 = i, d3 = i+1;
            if (d1 < 0) d1 = m-1;
            if (d3 >= m) d3 = 0;

            int dest1 = min({d1, d2, d3}),
                dest3 = max({d1, d2, d3}),
                dest2 = d1+d2+d3 -dest1-dest3;

            if (dp[dest1][j][end] <= min(dp[dest2][j][end], dp[dest3][j][end])) i = dest1;
            else if (dp[dest2][j][end] <= min(dp[dest1][j][end], dp[dest3][j][end])) i = dest2;
            else i = dest3;
        }
        cout << end+1 << "\n";
        
        print(out);
    }
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        16-11-2023 00:46
*/