/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার,
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define debug 0
#else
#define fast ;
#define debug 1
#endif

// for policy based data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// ordered_set: extends set to find_by_order and order_of_key
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// some typedefs for my convenience
#define int long long int
#define double long double
#define pii pair<int, int>
#define vi vector<int>
#define si set<int>
#define msi multiset<int>
#define mi map<int, int>
// some speedup macros
#define gap ' '
#define endl '\n'
#define print(str) cout << str << endl
#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define scanx(array) { for (auto &x: array) cin >> x; }
#define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }
#define loop(i, begin, end) for(__typeof(end)i=begin-(begin>end); i!=end-(begin>end); i+=1-2*(begin>end))
#define loopit(v) for (auto it=v.begin(); it!=v.end(); it++)
#define all(v) v.begin(), v.end()

// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

void solve(int cases);
int32_t main()
{
    fast // fast IO! but only when online_judge
    int test_cases = 1;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++) solve(cases);

    return 0;
}

// SOLVE STARTS HERE

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=-1, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;
    vi v(n);
    scanx(v);
    vi odds, evens;

    loop(i,0,n){
        // cin >> v[i];
        // cout << v[i];
        if (v[i] % 2){
            odds.push_back(i+1);
        }
        else evens.push_back(i+1);
    }
    // if (flag == -1){
    //     print("NO");
    //     return;
    // }
    // if (flag>0 && flag<n-1){
    //     print(flag << gap << flag+1 << gap << flag+2);
    // }
    // else if (flag==0){
    //     print(flag+1 << gap << flag+2 << gap << flag+3);
    // }
    // else if (flag==n-1){
    //     print(flag-1 << gap << flag << gap << flag+1);
    // }

    if (evens.size() >= 2 && odds.size()){
        print("YES");
        print(evens[0] << gap << evens[1] << gap << odds[0]);
    }
    else if (odds.size() > 2){
        print("YES");
        print(odds[0] << gap << odds[1] << gap << odds[2]);
    }
    else print("NO");

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        25-01-2023 20:36
*/