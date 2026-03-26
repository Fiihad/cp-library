/*
        অন্তর মম বিকশিত করো অন্তরতর হে–
        নির্মল করো, উজ্জ্বল করো, সুন্দর করো হে ॥
        জাগ্রত করো, উদ্যত করো, নির্ভয় করো হে।
        মঙ্গল করো, নিরলস নিঃসংশয় করো হে ॥
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#else
#define fast ;
#endif

// for policy based data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// ordered_set: extends set to find_by_order and order_of_key
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

#define int long long int
#define double long double
#define pii pair<int, int>
#define vi vector<int>
#define si ordered_set
#define msi ordered_multiset
#define mi map<int, int>
#define mmi multimap<int, int>

#define gap ' '
#define endl '\n'
#define pb push_back
#define print(str) cout << str << endl
#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define scanx(array) { for (auto &x: array) cin >> x; }
#define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }
#define loop(i, begin, end) for(int i=begin; i<end; i+=2)
#define loopit(v) for (auto it=v.begin(); it!=v.end(); it++)
#define all(v) v.begin(), v.end()

// for debugging
int debug = 1;
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}


// SOLVE STARTS HERE
void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in, in2;
    cin >> n;

    mi rows, cols;
    set<pii> L;
    for(int i=0; i<3; i++){
        cin >> in >> in2;
        rows[in]++, cols[in2]++;
        L.insert({in, in2});
    }

    
    int r,c;
    cin >> r >> c;
    for (auto x:rows){
        if (r==x.first and x.second==2){
            print("YES");
            return;
        }
    }
    for (auto x:cols){
        if (c==x.first and x.second==2){
            print("YES");
            return;
        }
    }

    if (L.count({1,1}) && L.count({1,2}) && L.count({2,1})){
        if (r==1 && c&1 or c==1 && r&1) print("YES");
        else print("NO");
        return;
    }
    if (L.count({n,1}) && L.count({n,2}) && L.count({n-1,1})){
        if (r==n && c&1 or c==1 && r&1==n&1) print("YES");
        else print("NO");
        return;
    }
    if (L.count({1,n}) && L.count({1,n-1}) && L.count({2,n})){
        if (r==1 && c&1==n&1 or c==n && r&1) print("YES");
        else print("NO");
        return;
    }
    if (L.count({n,n}) && L.count({n-1,n}) && L.count({n,n-1})){
        if (r==n && c&1==n&1 or c==n && r&1==n&1) print("YES");
        else print("NO");
        return;
    }

    int unr, unc;
    for (auto x:rows) if (x.second==1){ unr=(x.first)%2; break; }
    for (auto x:cols) if (x.second==1){ unc=(x.first)%2; break; }

    loop(i,unr,n+1){
        if (i>r) break;
        if (i==r){
            loop(j,unc,n+1){
                if (j>c) goto END;
                if (j==c){
                    print("NO");
                    return;
                }
            }
        }
    }
END:
    print("YES");

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
        08-10-2022 16:04
*/