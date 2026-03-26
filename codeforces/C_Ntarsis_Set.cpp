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
vi v;
int n, k;
bool ispos(int mid)
{
    // loop(i,0,k){
    //     if (binary_search(all(v), mid)) return false;

    //     mid -= (lower_bound(all(v), mid) - v.begin());
    // }
    // if (mid == 1) return true;
    // return false;

    int rem = 0;
    loop(i, n, 0){
        if (v[i] > mid) continue;

        int koyta_porpor = i+1;
        int ache_koyta = mid - v[i] + rem;
        mid = v[i];
        int jabe_koyta = min((ache_koyta/koyta_porpor), k-1);
        rem = ache_koyta - jabe_koyta - 1;
        // bug(v[i], ache_koyta, jabe_koyta, rem);
    }
    if (rem >= 0) return true;
    return false;
}

void solve(int cases)
{
    int out;
    cin >> n >> k;
    v.clear();
    int in;
    loop(i,0,n) cin >> in, v.push_back(in);
    if (v[0] != 1){
        print(1);
        return;
    }

    int lo = 1, hi = 1e18;
    while (lo <= hi){
        int mid = (hi+lo)/2;
        // bug(mid, ispos(mid));
        if (ispos(mid)) out = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    // bug(ispos(9));
    print(out);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        23-07-2023 22:08
*/