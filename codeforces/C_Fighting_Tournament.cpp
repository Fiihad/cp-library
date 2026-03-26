/*
        অন্তর মম বিকশিত করো অন্তরতর হে–
        নির্মল করো, উজ্জ্বল করো, সুন্দর করো হে ॥
        জাগ্রত করো, উদ্যত করো, নির্ভয় করো হে।
        মঙ্গল করো, নিরলস নিঃসংশয় করো হে ॥
*/

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

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
#define loopit(v) for (auto it=v.begin(); it!=v.end(); it++)
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
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        // SOLVE STARTS HERE

        int n, q, in, out=0, sum=0, flag=0, max=0, max_ind, min=LLONG_MAX;
        cin >> n >> q;
        vi v(n);
        vector<vi> win(n+1);
        cin >> v[0];
        max = v[0];

        for (int i=1; i<n; i++){
            cin >> v[i];
            if (v[i]==n) max_ind = i+1;
            if (v[i] > max){
                max = v[i];
                win[v[i]].pb(i);
            }
            else win[max].pb(i);
        }

        while (q--){
            cin >> in >> flag;
            in = v[in-1];
            if (win[in].empty()) { print(0); continue; }

            out = lower_bound(all(win[in]), flag) - win[in].begin();

            if (flag >= n && in == n) print(win[in].size() + flag - n + 1);
            else if (out == win[in].size()) print(win[in].size());
            else if (win[in][out] == flag) print(out+1);
            else if (out == 0) print(0);
            else if (win[in][out] == win[in].size()) print(win[in].size());
            else print(out);
        }
    }
    return 0;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        17-08-2022 16:56
*/