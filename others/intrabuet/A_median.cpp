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
vector<pair<pii, int>> v;

bool cmp(pair<pii, int> a, pair<pii, int> b)
{
	pair<pii, int> vec1, vec2;
	vec1.first.first = a.first.first - v[0].first.first;
    vec1.first.second = a.first.second - v[0].first.second;
	vec2.first.first = b.first.first - v[0].first.first;
    vec2.first.second = b.first.second - v[0].first.second;
	
	return vec1.first.first * vec2.first.second - vec2.first.first * vec1.first.second > 0;
}

void solve(int cases)
{
    int n;
    cin >> n;

    double in, out;
    int minx=LLONG_MAX, miny=LLONG_MAX, minid;
    loop(i,0,n){
        cin >> in >> out;
        v.push_back({{in, out}, i+1});

        if (in < minx || in == minx && out < miny) minx = in, miny = out, minid = i+1, swap(v.back(), v.front());
    }
    sort(v.begin()+1, v.end(), cmp);

    print(v[0].second << gap << v[n/2].second);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        30-05-2023 13:56
*/