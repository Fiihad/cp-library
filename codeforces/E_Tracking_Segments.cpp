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
    cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
bool isp(int q, int n, vector<pii> &segments, vi &que){
    vi pref(n+1, 0);

    vi v(n+1, 0);

    loop(i,1,q+1){
        v[que[i]] = 1;
    }
    loop(i,1,n+1) pref[i] = pref[i-1]+v[i];

    for (auto x: segments){
        if (pref[x.second]-pref[x.first-1] > (x.second-x.first+1)/2) return true;
    }
    return false;
}

void solve(int cases)
{
    int n, q, out=-1, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int m;
    cin >> n >> m;

    vector<pii> segments(m);
    loop(i, 0, m) cin >> segments[i].first >> segments[i].second;

    cin >> q;
    vi que(q+1);
    loop(i, 1, q+1) cin >> que[i];

    int l = 1, r = q;
    while (l <= r){
        int mid = (r+l)/2;
        if (isp(mid, n, segments, que)) out = mid, r = mid-1;
        else l = mid+1;
    }
    print(out);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        20-06-2023 22:15
*/