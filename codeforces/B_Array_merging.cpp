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

// SOLVE STARTS HERE
// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

void solve(int cases)
{
    int n, out=1, sum=1;
    int in;
    cin >> n;
    vi u(n), v(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(u);
    scanx(v);
    mi um, vm;

    int flag = 1;
    um[u[0]] = vm[v[0]] = 1;
    loop(i,1,n){
        if (u[i]==u[i-1]) flag++;
        else flag = 1;

        if (flag > um[u[i]]) um[u[i]] = flag;
    }
    flag = 1;
    loop(i,1,n){
        if (v[i]==v[i-1]) flag++;
        else flag = 1;

        if (flag > vm[v[i]]) vm[v[i]] = flag;
    }
    
    for (auto x: um) out = max(out, x.second+vm[x.first]);
    for (auto x: vm) out = max(out, x.second+um[x.first]);
    print(out);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        28-05-2023 23:51
*/