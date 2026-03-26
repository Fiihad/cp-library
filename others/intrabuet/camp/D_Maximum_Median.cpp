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
#define printp(p) cout << '(' << p.first << ',' << gap << p.second << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> q;

    vi v(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(v);
    sort(all(v));

    mi freq;
    loop(i, n/2, n) freq[v[i]]++;

    vector<pii> finalv(all(freq));

    loop(i, 0, finalv.size()-1){
        q -= (finalv[i+1].first - finalv[i].first) * finalv[i].second;
        if (q < 0) {
            q += (finalv[i+1].first - finalv[i].first) * finalv[i].second;
            print(finalv[i].first + q/finalv[i].second);
            return;
        }
        finalv[i+1].second += finalv[i].second;
    }

    print(finalv.back().first + q/finalv.back().second);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        03-06-2023 17:12
*/