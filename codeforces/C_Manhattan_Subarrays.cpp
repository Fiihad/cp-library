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
bool inordec(int x, int y, int z){
    return (x <= y && y <= z || x >= y && y >= z);
}

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;
    vi v(n);
    #define scanx(array) { for (int i=0; i<array.size(); ++i) cin >> array[i]; }
    scanx(v);

    sum = n + n - 1;
    loop(i,0,n-2){
        if (i < 0) break;
        if (!inordec(v[i], v[i+1], v[i+2])) sum++;
    }
    loop(i,0,n-3){
        if (i < 0) break;
        int w = v[i], x = v[i+1], y = v[i+2], z = v[i+3];
        if (!inordec(w, x, y) && !inordec(w, x, z) && !inordec(w, y, z) && !inordec(x, y, z)) sum++;
    }
    print(sum);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        17-08-2023 12:31
*/