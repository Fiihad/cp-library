/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার,
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0);  // fast IO! but only when online_judge
#define debug 0
#else
#define fast ;
#define debug 1
#endif

// some typedefs for my convenience
#define int long long int
#define pii pair<int, int>
#define vi vector<int>
#define si set<int>
#define mi map<int, int>
// some speedup macros
#define gap ' '
#define endl '\n'
#define print(str) cout << str << endl
#define YES print("YES")
#define NO print("NO")
#define loop(i, begin, end) for(__typeof(end)i=begin-(begin>end); i!=end-(begin>end); i+=1-2*(begin>end))
#define all(v) v.begin(), v.end()

// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }


void solve(int cases);
int32_t main()
{
    fast
    int total_cases = 1;
    // cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
const int MAX = 1e4;
vector<int> divisor[MAX + 1];
void sieve()
{
    for (int i = 2; i <= MAX; ++i) {
        for (int j = i; j <= MAX; j += i)
            divisor[j].push_back(i);
    }
}

void solve(int cases)
{
    sieve();
    int n, sum;
    int in;
    cin >> n;
    vi f(n+1), g(n+1);

    loop(i, 1, n+1) cin >> f[i];

    loop(i,1,n+1){
        int sum = 0;
        // printx(divisor[i]);
        for (auto x: divisor[i]){
            // bug(x);
            sum += (f[x]*g[i/x])%2007;
        }
        // bug(i, sum);
        if (i==1) g[i] = (2007+1-sum)%2007;
        else g[i] = (2007-sum)%2007;
        g[i] /= f[1];
        g[i] += 2007;
        g[i] %= 2007;
    }

    loop(i,1,n+1) cout << g[i] << gap;
    cout << endl;
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        30-05-2023 14:34
*/