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
int M = 1e9+7;
int m = 1e9+7;

int mulm(int x, int y) { return (x*y)%m; }

int powrm(int x, int y){    // recursive method, when y is small
    int res = 1;
    while (y) {
        if (y&1) res = mulm(res, x);
        y /= 2;
        x = mulm(x, x);
    }
    return res;
}

int invm(int x) { return powrm(x, m-2); }   // fermat's little theorem

int divm(int x, int y) { return mulm(x, powrm(y, m-2)); }

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in, m;
    cin >> n >> m;

    mi counts;
    loop(i,0,n) cin >> in, counts[in]++;
    vector<pii> v;
    v.assign(all(counts));

    vi pref;
    pref.push_back(v[0].second);
    loop(i,1,v.size()){
        pref.push_back((v[i].second*pref.back())%M);
    }
    
    q = m-1;
    loop(i,0,v.size()){
        if (i+q >= v.size() || v[i].first+q > v.back().first) break;
        if (v[i+q].first > v[i].first + q) continue;
        int mult = pref[i+q];
        if (i) mult = divm(mult, pref[i-1]);
        // for (int j=i; j<i+m; j++) mult *= (v[j].second)%M, mult%=M;
        out += mult;
        out %= M;
    }
    print(out);
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        21-05-2023 13:46
*/