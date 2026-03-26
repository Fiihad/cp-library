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
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        // SOLVE STARTS HERE

        int n, q, in, out=0, sum=0;
        cin >> n;
        vi v(n);
        scanx(v);

        if (n%2){
            for (int i=1; i<n-1; i+=2){
                if (v[i]<=v[i+1] || v[i]<=v[i-1])
                    out += v[i+1]>v[i-1]? (v[i+1]-v[i]+1) : (v[i-1]-v[i]+1);
            }
        }
        else{
            for (int i=2; i<n-1; i+=2){
                if (v[i]<=v[i+1] || v[i]<=v[i-1])
                    out += v[i+1]>v[i-1]? (v[i+1]-v[i]+1) : (v[i-1]-v[i]+1);
            }
            sum = out;
            for (int j=1; j<n-1; j+=2){
                if (v[j]<=v[j+1] || v[j]<=v[j-1])
                    sum += v[j+1]>v[j-1]? (v[j+1]-v[j]+1) : (v[j-1]-v[j]+1);
                if (v[j+1]<=v[j+2] || v[j+1]<=v[j])
                    sum -= v[j+2]>v[j]? (v[j+2]-v[j+1]+1) : (v[j]-v[j+1]+1);
                if (sum < out) out = sum;
            }
        }
        print(out);
    }
    return 0;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        19-07-2022 00:56
*/