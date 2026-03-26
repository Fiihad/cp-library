/*
        আমার অমনোযোগী ক্লাসরুম... আমার মগজে নষ্ট ধুম...
        আমার বাহিরে বুদ্ধ, ভেতরে হিটলার... লাশের মোড়কে ঘুম :)
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define debug 0
#else
// #define fast ;
#define debug 1
#endif
#define fast ios_base::sync_with_stdio(0); cin.tie(0);  // fast IO! but only when online_judge
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
    // cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
int n, x;
vi v;

vector<pii> dp(pow(2, 20) + 5);

pii rec(int mask){
    if (dp[mask].first) return dp[mask];

    if ( __builtin_popcount(mask) == 1){
        loop(i,0,n){
            if ((mask >> i) & 1) return dp[mask] = {1, v[i]};
        }
    }
    pii out = {INT_MAX, INT_MAX}, temp;

    for (int m = mask, i = 0; m; i++, m = m >> 1){
        if (m & 1){
            temp = rec(mask ^ (1 << i));
            if (temp.second + v[i] <= x) temp.second += v[i];
            else temp.first++, temp.second = min(temp.second, v[i]);
            out = min(out, temp);
        }
    }
    return dp[mask] = out;
}

void solve(int cases)
{
    cin >> n >> x;

    loop(i,0,n){
        int in;
        cin >> in;
        v.push_back(in);
    }

    int mask = pow(2, n) - 1;
    print((rec(mask)).first);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        18-11-2023 21:12
*/