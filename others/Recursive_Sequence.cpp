/*
        অন্তর মম বিকশিত করো অন্তরতর হে–
        নির্মল করো, উজ্জ্বল করো, সুন্দর করো হে ॥
        জাগ্রত করো, উদ্যত করো, নির্ভয় করো হে।
        মঙ্গল করো, নিরলস নিঃসংশয় করো হে ॥
*/

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9;

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

struct mat{
    int m, n;
    int ara[11][11];
    mat(int x, int y=0){
        if (!y) y=x;
        m=x; n=y;
        memset(ara, 0, sizeof(ara));
    }
    mat operator*(mat a){
        mat res(m, a.n);
        loop(i, m)
            loop(j, a.n)
                loop(k, a.m)
                    res.ara[i][j] += ((ara[i][k]%mod) * (a.ara[k][j]%mod)) % mod;
        return res;
    }
    mat operator^(int x){
        mat res(m, n), a=*this;
        for (int i=0; i<m; i++) res.ara[i][i] = 1;
        while (x){
            if (x&1) res = res*a;
            a = a*a;
            x /= 2;
        }
        return res;
    }
};

int32_t main()
{
    int test_cases = 1;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        // SOLVE STARTS HERE

        int k, q, in, out=0, sum=0, flag=0, max=0, min=LLONG_MAX;
        cin >> k;
        mat a(k, 1);
        for (int i=k-1; i>=0; i--) cin >> a.ara[i][0];

        mat T(k);
        loop(i, k) cin >> T.ara[0][i];
        for (int i=1, j=0; i<k; i++, j++) T.ara[i][j] = 1;

        int n; cin >> n;
        if (n<=k) print(a.ara[k-n][0]);
        else print((((T^(n-k)) * a).ara[0][0])%mod);
    }
    return 0;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        11-08-2022 15:59
*/