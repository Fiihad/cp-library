/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার,
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
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

// some typedefs for my convenience
#define int long long int
#define pii pair<int, int>
#define vi vector<int>
#define si set<int>
#define mi map<int, int>
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
    cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}
// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}
// SOLVE STARTS HERE
int dfs(vector<vi> &v, vector<vi> &isVis, int prev, int i, int j)
{
    if (i>=v.size() || i<0 || j>=v[i].size() || j<0 || isVis[i][j] || v[i][j] == 0) return 0;
    isVis[i][j] = true;
    bug(i, j, prev, "ula");

    prev += v[i][j];
    prev += dfs(v, isVis, 0, i+1, j);
    prev += dfs(v, isVis, 0, i-1, j);
    prev += dfs(v, isVis, 0, i, j+1);
    prev += dfs(v, isVis, 0, i, j-1);

    bug(i, j, prev);
    return prev;
}

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> q;

    vector<vi> v(n, vi(q)), isVis(n, vi(q, 0));
    loop(i,0,n)
        loop(j,0,q)
            cin >> v[i][j];

    loop(i,0,n)
        loop(j,0,q)
            if (isVis[i][j] == 0){
                out = max(dfs(v, isVis, 0, i, j), out);
                bug(i, j, out);
            }


    print(out);
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        06-05-2023 21:59
*/