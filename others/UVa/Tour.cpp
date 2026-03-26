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


void solve();
// USE OF cin.eof() GIVES WRONG ANSWER!
// int32_t main()
// {
//     fast
//     int total_cases = 1;
//     while (!cin.eof()) solve();
//     return 0;
// }

// SOLVE STARTS HERE
int n;
vector<vector<double>> dp;
// double dist[1010][1010]; // FOR APPROACH 0

double dist(pair<double, double> a, pair<double, double> b){
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return hypot(dx, dy);
}

// APPROACH 0 - COPIED FROM GITHUB
// double rec(int a, int b)
// {
//     if (dp[a][b]!=-1.0) return dp[a][b];
//     if (a==n-1) return dp[a][b] = dp[b][a] = dist[b][n-1];
//     return dp[a][b] = dp[b][a] = min(rec(a+1,b) + dist[a][a+1] , rec(a+1, a) + dist[b][a+1]);
// }

// APPROACH 2
double rec(vector<pair<double, double>> &v, int i, int j){
    if (dp[i][j] != -1.0) return dp[i][j];

    if (i == n-1) return dp[i][j] = dp[j][i] = dist(v[i], v[j]);
    if (i > n-1) return 0;
    return dp[i][j] = dp[j][i] = min(dist(v[i+1], v[i]) + rec(v, i+1, j), dist(v[i+1], v[j]) + rec(v, i+1, i));
}

// APPROACH 1
// double rec(vector<pair<double, double>> &v, int i, int j){
//     if (dp[i][j] != -1.0) return dp[i][j];

//     int dest = min(n-1, max(i, j) + 1);
//     if (dest <= 0) return 0;

//     if (dest == n-1) return dp[i][j] = dist(v[i], v[dest]) + dist(v[j], v[dest]);
//     return dp[i][j] = min(dist(v[i], v[dest]) + rec(v, dest, j), dist(v[j], v[dest]) + rec(v, i, dest));
// }

int32_t main()
{
    while (cin >> n){
        dp.clear();
        dp.resize(n+1, vector<double>(n+1, -1));

        vector<pair<double, double>> v;
        loop(i,0,n){
            double x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }

        // FOR APPROACH 0
        // for (int i = 0; i < n-1; i++)
        //         for (int j = i + 1; j < n; j++)
        //             dist[i][j] = dist[j][i] = di(v[i],v[j]);

        cout << fixed << setprecision(2);
        print(rec(v, 0, 0));
    }

    return 0;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        15-11-2023 17:52
*/