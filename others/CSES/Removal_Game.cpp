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
vi prefix;
int dp[5001][5001];

int rec(int i, int j, vi &v)
{
    if (i == j) return dp[i][j] = v[i];
    if (dp[i][j] != -1) return dp[i][j];

    int firsttake = prefix[j] - prefix[i-1] - rec(i+1, j, v),
        secondtake = prefix[j] - prefix[i-1] - rec(i, j-1, v);
    
    return dp[i][j] = max(firsttake, secondtake);
}

void solve(int cases)
{
    memset(dp, -1, sizeof(dp));
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;

    vi v(n+1);
    prefix.resize(n+1);
    loop(i, 1, n+1) cin >> v[i];
    prefix[1] = v[1];
    loop(i,2,n+1) prefix[i] = v[i] + prefix[i-1];

    print(rec(1, n, v));
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        09-07-2023 00:17
*/