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

int anshu(int x, int y, vi &w) {
    int out = 0;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] < 0) {
            if (x >= -w[i]) x -= -w[i], out += -w[i];
            else {

            }
        }
    }
}


void solve(int cases)
{
    int n, k, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> k;

    vector<pii> v;

    loop(i,0,n) {
        cin >> in;
        v.push_back({in, i});
    }

    sort(all(v));
    maxi = v[0].first;

    loop(i,0,n-1) {
        if (k == 0) break;

        int diff = v[i+1].first - v[i].first;
        if (k >= diff * (i+1)) {
            k -= diff * (i+1);
            maxi = v[i+1].first;
        }
        else if (k < diff * (i+1)) {
            maxi = v[i].first + (k/(i+1));
            k = k%(i+1);
            break;
        }
    }
    if (k >= n) {
        maxi = maxi + (k/n);
        k = k%n;
    }

    out = maxi * n - (n-1);
    
    loop(i,0,n)
        out += v[i].first > maxi;
    out += k;

    print(out);


}

/*
        Fihad arRahman
        hellofihad@gmail.com
        30-04-2024 21:48
*/