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
    int a,b,c,k, out=1;
    cin >> a >> b >> c >> k;

    int check = (a+b+c)/3;

    if (a == b && b == c) out = 1;
    else if (check*3 != (a+b+c)) out = 0;

    else if ((a<k&&b<k) || (b<k&&c<k) || (a<k&&c<k)) out=0;

    else if (llabs(check-a)%k != 0 || llabs(check-b)%k != 0 || llabs(check-c)%k != 0) out = 0;

    if (out) print("Case " << cases << ": Peaceful");
    else print("Case " << cases << ": Fight");

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        11-02-2023 15:49
*/