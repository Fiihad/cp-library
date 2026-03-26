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
    // cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE

void solve(int cases)
{
    int n, q, sum1, sum2, in, m;
    cin >> n >> m >> q;
    vi u, v;
    loop(i,0,n) cin >> in, u.push_back(in);
    loop(i,0,m) cin >> in, v.push_back(in);

    sum1 = accumulate(all(u), 0LL); 
    sum2 = accumulate(all(v), 0LL);

    vector<bool> ispos1(2*n + 1, false), ispos2(2*m + 1, false);
    loop(i,0,n) ispos1[u[i] + n] = true;
    loop(i,0,m) ispos2[v[i] + m] = true;

    while (q--) {
        int x;
        cin >> x;

        auto check = [&](int x, int y)->bool
        {
            int idx1 = sum1 - x + n;
            int idx2 = sum2 - y + m;
            return (0 <= idx1 && idx1 <= 2*n && 0 <= idx2 && idx2 <= 2*m && ispos1[idx1] && ispos2[idx2]);
        };

        for (int i = 1; i * i <= abs(x); i++)
            if (x % i == 0) {
                if (check(i, x/i) || check(-i, -x/i) || check(x/i, i) || check(-x/i, -i)) {
                    YES;
                    goto loop;
                }
            }
        NO;
    loop:;
    }

}

/*
        Fihad arRahman
        hellofihad@gmail.com
        15-12-2024 16:35
*/