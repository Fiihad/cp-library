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
#define printxp(array) { for (auto x : array) cout << '(' << x.F << ',' << gap << x.S << ')' << gap; cout << endl; }
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
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;

    vi u(27,0), v(27, 0);
    u[0]=1, v[0]=1;
    bool notA = false;
    int usize=1, vsize=1, uA=1;

    while (n--){
        int a, k;
        string str;

        cin >> a >> k >> str;
        if (a==1){
            usize += str.size()*k;
            loop(i,0,str.size()) if (str[i]=='a') uA+=k;
        }
        else{
            vsize += str.size()*k;
            if (!notA) loop(i,0,str.size()) if (str[i]!='a') notA=true;
        }

        if (notA) print("YES");
        else{
            if (usize - uA > 0) print("NO");
            else if (usize<vsize) print("YES");
            else print("NO");
        }


        // loop(i, 0, str.size()){
        //     if (a==1) u[str[i]-'a'] += k, usize += k;
        //     else v[str[i]-'a'] += k, vsize += k;
        // }

        // loop(i, 0, 27){
        //     if (u[i]>v[i] and v[i]!=0 and vsize>u[i]){
        //         print("YES");
        //         goto END;
        //     }
        // }
        // print("NO");
        // END:;
    }
}

int32_t main()
{
    fast // fast IO! but only when online_judge
    int test_cases = 1;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++) solve(cases);

    return 0;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        09-10-2022 16:07
*/