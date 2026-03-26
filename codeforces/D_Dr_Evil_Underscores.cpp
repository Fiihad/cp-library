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
int dc(vi &v, int bit, int cases)
{
    if (bit == -1) return 0;

    vi ones, zeros;
    int ocount = 0, zcount = 0, out = 0;

    for (auto x: v){
        if ((x>>bit) & 1) ocount++, ones.push_back(x);
        else zcount++, zeros.push_back(x);
    }

    if (ocount && zcount){
        out = 1 << bit;
        out |= min(dc(zeros, bit-1, cases), dc(ones, bit-1, cases));
    }
    else if (ocount) out = dc(ones, bit-1, cases);
    else if (zcount) out = dc(zeros, bit-1, cases);
    return out;
}


void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;

    vi v(n);
    #define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
    #define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
    #define scanx(array) { for (auto &x: array) cin >> x; }
    #define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }
    scanx(v);

    print(dc(v, 31 - __builtin_clz(*max_element(all(v))), n));

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        18-02-2023 20:32
*/