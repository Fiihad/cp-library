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

        int n, q, in, out=0, sum=0, flag=0;
        cin >> n;
        int ara[2][n];
        loop(i,2)
            loop(j,n)
                cin >> ara[i][j];

        for (int i=1; i<n; i++){
            if (sum<ara[0][i]) sum += (ara[0][i]-sum+1);
            else sum++;
        }
        if (sum<ara[1][n-1]) sum += (ara[1][n-1]-sum+1);
        else sum++;
        for (int i=n-2; i>=0; i--){
            if (sum<ara[1][i]) sum += (ara[1][i]-sum+1);
            else sum++;
        }

        out = sum;
        sum = 0;

        if (sum<ara[1][0]) sum += (ara[1][0]-sum+1);
        else sum++;
        for (int i=1; i<n; i++){
            if (sum<ara[1][i]) sum += (ara[1][i]-sum+1);
            else sum++;
        }
        if (sum<ara[0][n-1]) sum += (ara[0][n-1]-sum+1);
        else sum++;
        for (int i=n-2; i>=0; i--){
            if (sum<ara[0][i]) sum += (ara[0][i]-sum+1);
            else sum++;
        }
        if (sum<out) out = sum;

        
    }
    return 0;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        05-08-2022 00:11
*/