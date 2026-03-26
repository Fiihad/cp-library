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
    cout << setprecision(9) << fixed;
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double a = 2*x2 - 2*x1, b = 2*y2 - 2*y1, c = x2*x2 + y2*y2 - x1*x1 - y1*y1;
    double d = 2*x3 - 2*x1, e = 2*y3 - 2*y1, f = x3*x3 + y3*y3 - x1*x1 - y1*y1;

    // center
    double x = -(b*f-c*e)/(a*e-b*d), y = -(c*d-a*f)/(a*e-b*d);
    double radius = sqrtl((x-x1)*(x-x1) + (y-y1)*(y-y1));

    // double m1 = (y1-y)/(x1-x), m2 = (y2-y)/(x2-x), m3 = (y3-y)/(x3-x);
    // double theta1 = atan2((m2-m1),(1+m2*m1)), theta2 = atan2((m3-m2),(1+m3*m2)), theta3 = atan2((m1-m3),(1+m3*m1));
    double theta1 = atan2(y1-y, x1-x)-atan2(y2-y, x2-x), theta2 = atan2(y2-y, x2-x)-atan2(y3-y, x3-x), theta3 = atan2(y3-y, x3-x)-atan2(y1-y, x1-x);

    int n = 3, edges = n;
    while (n <= 100){
        double check = (2*acos((double)-1))/n;
        double check1 = theta1/check, check2 = theta2/check, check3 = theta3/check;

        if (fabs(check1-round(check1)) <= 1e-5 && fabs(check2-round(check2)) <= 1e-5 && fabs(check3-round(check3)) <= 1e-5){
            edges = n;
            break;
        }
        n++;
    }

    double area = edges * 0.5 * radius * radius * sin((2*acos((double)-1))/edges);
    print(area);
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        05-12-2022 22:18
*/