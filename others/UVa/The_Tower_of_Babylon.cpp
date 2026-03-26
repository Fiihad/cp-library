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
int n;
int dp[200][200];

int rec(vector<pair<pii, int>> &v, int i, int last_taken){
    if (i >= n) return 0;
    if (dp[i][last_taken] != -1) return dp[i][last_taken];
    // bug(i);

    int out = 0;
    // int nexti = n;
    // for (int j = i+1; j < n; j++){
    //     if (v[j].first.first < v[i].first.first && v[j].first.second < v[i].first.second){
    //         nexti = j;
    //         break;
    //     }
    // }
    // bug(i, nexti);
    if (last_taken == n || v[i].first.first < v[last_taken].first.first && v[i].first.second < v[last_taken].first.second)
        out = v[i].second + rec(v, i+1, i);
    out = max(rec(v, i+1, last_taken), out);
    return dp[i][last_taken] = out;
}

void solve(int cases)
{
    int q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;

    while (1){
        flag++;
        memset(dp, -1, sizeof(dp));
        cin >> n;

        if (!n) return;

        vector<pair<pii, int>> v;
        loop(i,0,n){
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back({{a, b}, c});
            v.push_back({{b, a}, c});
            v.push_back({{a, c}, b});
            v.push_back({{c, a}, b});
            v.push_back({{b, c}, a});
            v.push_back({{c, b}, a});
        }
        sort(all(v));
        reverse(all(v));

        n = v.size();
        // loop(i,0,n) cout << v[i].first.first << ' ' << v[i].first.second << ' ' << v[i].second << '\n';

        cout << "Case " << flag << ": maximum height = " << rec(v, 0, n) << '\n';
    }

}

/*
        Fihad arRahman
        hellofihad@gmail.com
        12-11-2023 19:15
*/