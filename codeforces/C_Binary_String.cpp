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
#define br '\n'
#define pb push_back
#define print(str) cout << str << endl
#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define scanx(array) { for (auto &x: array) cin >> x; }
#define printxp(array) { for (auto x : array) cout << '(' << x.F << ',' << gap << x.S << ')' << gap; cout << endl; }
#define loop(i, begin, end) for (int i=begin; i<end; i++)
#define loopit(v) for (auto it=v.begin(); it!=v.end(); it++)
#define all(v) v.begin(), v.end()
#define found(value, s) s.find(value) != s.end()

// for debugging
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

bool isPoss(vi &forw, vi &back, vi &forw1, vi &back1, int cost)
{
    int sum;

    int rem = forw.size()-cost;
    int i=rem;
    if (rem > 0) while (true){
        if (i==0) sum = max(cost, back[rem-i-1]);
        else if (i==rem) sum = max(cost, forw[i-1]);
        else sum = max(cost, forw[i-1]+back[rem-i-1]);
        if (sum==cost) return true;
        i--;
        if (i<0) break;
    }

    int zeros = forw.size();
    i=cost;
    if (forw1.size()>cost) while (true){
        if (cost==0) sum = zeros;
        else if (i==0) sum = max(cost, zeros-back1[cost-i-1]);
        else if (i==cost) sum = max(cost, zeros-forw1[i-1]);
        else sum = max(cost, zeros-forw1[i-1]-back1[cost-i-1]);

        // bug(cost, i, sum);
        if (sum==cost) return true;
        i--;
        if (i<0) break;
    }

    return false;
}

int32_t main()
{
    fast // fast IO! but only when online_judge
    int test_cases = 1;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        // SOLVE STARTS HERE

        int n, q, out=0, sum=0, sum1=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
        string in;
        cin >> in;
        n = in.size();

        vi forw, back, forw1, back1;
        loop(i,0,n){
            if (in[i]=='1') sum++, forw1.pb(sum1);
            else sum1++, forw.pb(sum);
        }
        sum = sum1 = 0;
        for(int i=n-1; i>=0; i--){
            if (in[i]=='1') sum++, back1.pb(sum1);
            else sum1++, back.pb(sum);
        }


        int hi = max(forw.size(), forw1.size()), lo = 0;
        while (hi >= lo){
            int mid = (hi+lo)/2;
            // bug(mid);
            if (isPoss(forw, back, forw1, back1, mid)) out = mid, hi = mid-1;
            else lo = mid+1;

            // bug(out);
        }

        // if (cases==114) cout << in << '+';
        print(out);

    END:;
    }
    return 0;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        04-10-2022 23:32
*/