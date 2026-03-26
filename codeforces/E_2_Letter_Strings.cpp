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

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    string in;
    cin >> n;

    map<string, int> m;
    loop(i,0,n) cin >> in, m[in]++;

    for (auto it = m.begin(); it != m.end(); it++){
        for (auto it2 = it; it2 != m.end(); it2++){
            if ((*it).first[0]!=(*it2).first[0] && (*it).first[1]==(*it2).first[1] || (*it).first[0]==(*it2).first[0] && (*it).first[1]!=(*it2).first[1])
                out += (*it).second * (*it2).second;
        }
    }
    print(out);
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com 
        08-05-2023 12:30
*/