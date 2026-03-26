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
double dp[301][301][301];
// map<tuple<int, int, int, int>, double> dp;
int n;
double rec(int a, int b, int c, int d, int n){
    // bug(a, b, c, d, dp[a][b][c]);
    if (dp[a][b][c] != -1) return dp[a][b][c];

    double ans = n;
    if (b) ans += b * rec(a+1, b-1, c, d, n);
    if (c) ans += c * rec(a, b+1, c-1, d, n);
    if (d) ans += d * rec(a, b, c+1, d-1, n);
    if (n - a) ans /= (n - a);
    else ans = 0;
    return dp[a][b][c] = ans;
}

void solve(int cases)
{
    loop(i, 0, 301) loop(j, 0, 301) loop(k, 0, 301) dp[i][j][k] = -1;
    cout << setprecision(10) << fixed;
    cin >> n;
    vi freq(4, 0);

    loop(i, 0, n){
        int in;
        cin >> in;
        freq[in]++;
    }

    print(rec(freq[0], freq[1], freq[2], freq[3], n));
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        01-07-2023 23:47
*/