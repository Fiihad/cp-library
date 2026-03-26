/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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


// SOLVE STARTS HERE
void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=0, mini=LLONG_MAX;
    string in;
    cin >> n;

    map<pair<char, char>, int> doubles;
    map<char, int> singles;
    loop(i,0,n){
        cin >> in;
        set<char> str;
        loop(j,0,in.size()) str.insert(in[j]);
        auto itr = str.begin();
        if (str.size()==1) singles[*itr]+=in.size();
        else if (str.size()==2) doubles[{*(itr++), *itr}]+=in.size();
    }
    for (auto &x: doubles){
        maxi = max(maxi, x.second+singles[x.first.first]+singles[x.first.second]);
    }
    vi single_values;
    for (auto x:singles) single_values.pb(x.second);
    sort(all(single_values));
    if(single_values.size()>=2) maxi = max(maxi, single_values.back()+*(single_values.end()-2));
    else if (single_values.size()==1) maxi = max(maxi, single_values.back());
    print(maxi);

END:;
}

int32_t main()
{
    fast // fast IO! but only when online_judge
    int test_cases = 1;
    // cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++) solve(cases);

    return 0;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        09-10-2022 16:07
*/