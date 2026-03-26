/*
        অন্তর মম বিকশিত করো অন্তরতর হে–
        নির্মল করো, উজ্জ্বল করো, সুন্দর করো হে ॥
        জাগ্রত করো, উদ্যত করো, নির্ভয় করো হে।
        মঙ্গল করো, নিরলস নিঃসংশয় করো হে ॥
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>
#define si set<int>
#define spi set<pii>
#define msi multiset<int>
#define mi map<int, int>
#define mmi multimap<int, int>

#define gap ' '
#define endl '\n'
#define pb push_back
#define mp make_pair
#define print(str) cout << str << endl
#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define scanx(array) { for (auto &x: array) cin >> x; }
#define printxp(array) { for (auto x : array) cout << '(' << x.F << ',' << gap << x.S << ')' << gap; cout << endl; }
#define loop(i, n) for (int i=0; i<n; i++)
#define loop_v for (auto it=v.begin(); it!=v.end(); it++)
#define loop_s for (auto it=s.begin(); it!=s.end(); it++)
#define all(v) v.begin(), v.end()
#define itf(it) (*it).F
#define its(it) (*it).S
#define F first
#define S second

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

int32_t main()
{
    int test_cases = 1;
    // cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        // SOLVE STARTS HERE

        int n, q, in, out=0;
        cin >> n >> q;
        int prev;
        vi sum, sum_rev;
        sum.reserve(n);
        sum_rev.reserve(n);

        cin >> prev;
        sum.pb(0);
        sum_rev.pb(0);
        loop(i, n-1){
            cin >> in;
            if (in < prev){
                sum.pb(sum[i] + prev-in);
                sum_rev.pb(sum_rev[i]);
            }
            else{
                sum.pb(sum[i]);
                sum_rev.pb(sum_rev[i] + in-prev);
            }
            prev = in;
        }

        while (q--)
        {
            int a, b;
            cin >> a >> b;
            if (b>a) print(sum[b-1]-sum[a-1]);
            else print(sum_rev[a-1]-sum_rev[b-1]);
        }
    }
    return 0;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        22-07-2022 01:25
*/