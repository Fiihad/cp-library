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
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;
 
    mi m;
    loop(i,0,n) cin >> in, m[in]++, maxi = max(in, maxi);
 
    for (auto x: m){
        if (x.second >= 3) out += x.second*(x.second-1)*(x.second-2);
 
        for (int b=1; b*b<=x.first && x.first*b<=maxi; b++){
            if (x.first%b) continue;
            if (b!=1 && m.count(x.first/b) && m.count(x.first*b))
                out += x.second*m[x.first/b]*m[x.first*b];
            if (b*b!=x.first && m.count(b) && m.count(x.first*x.first/b))
                out += x.second*m[x.first/b*x.first]*m[b];
            // bug(out, x.first, b);
        }
    }
    print(out);
 
END:;
}
 
/*
        Fihad arRahman
        hellofihad@gmail.com
        10-05-2023 11:24
*/