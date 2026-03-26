/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার
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
#define si ordered_set
#define msi ordered_multiset
#define mi map<int, int>
#define mmi multimap<int, int>
// some speedup macros
#define gap ' '
#define endl '\n'
#define pb push_back
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
    // cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++) solve(cases);

    return 0;
}

// SOLVE STARTS HERE

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> q;

    vi rookrows(n+1,0), rookcols(n+1,0);
    set<int> freeRows, freeCols;
    loop(i,1,n+1) freeRows.insert(i), freeCols.insert(i);

    while (q--)
    {
        int mode;
        cin >> mode;

        if (mode==1)
        {
            int r, c;
            cin >> r >> c;
            rookrows[r]++; rookcols[c]++;
            if (rookrows[r]==1) freeRows.erase(r);
            if (rookcols[c]==1) freeCols.erase(c);
        }

        else if (mode==2)
        {
            int r, c;
            cin >> r >> c;
            rookrows[r]--; rookcols[c]--;
            if (!rookrows[r]) freeRows.insert(r);
            if (!rookcols[c]) freeCols.insert(c);
        }

        else
        {
            int r1,r2,c1,c2;
            cin >> r1 >> c1 >> r2 >> c2;
            
            auto rch_it = freeRows.lower_bound(r1), cch_it = freeCols.lower_bound(c1);
            if (rch_it == freeRows.end() || cch_it == freeCols.end()) print("Yes");
            else if (*rch_it > r2 || *cch_it > c2) print("Yes");
            else print("No");
    END:;
        }
    }
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        01-11-2022 14:03
*/