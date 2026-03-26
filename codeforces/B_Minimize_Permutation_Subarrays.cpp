/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার,
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); // fast IO! but only when online_judge
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
#define loop(i, begin, end) for (__typeof(end) i = begin - (begin > end); i != end - (begin > end); i += 1 - 2 * (begin > end))
#define all(v) v.begin(), v.end()

void solve(int cases);
int32_t main()
{
    fast int total_cases = 1;
    cin >> total_cases;
    loop(cases, 1, total_cases + 1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE

void solve(int cases)
{
    int n, q, out = 0, sum = 0, flag = 0, maxi = LLONG_MIN, mini = LLONG_MAX;
    int in;
    cin >> n;
    int flag1, flag2, flagn;

    loop(i, 0, n)
    {
        cin >> in;
        if (in == 1)
            flag1 = i+1;
        else if (in == 2)
            flag2 = i+1;
        else if (in == n)
            flagn = i+1;
    }

    if (flagn > flag1 && flagn < flag2 || flagn > flag2 && flagn < flag1) print(1 << gap << 1);
    else if (abs(flagn - flag1) < abs(flagn - flag2)) print(flagn << gap << flag1);
    else print (flagn << gap << flag2);


    // if (flag2 < flag1)
    //     swap(flag1, flag2);

    // if (flag2 - 0 > n - 1 - flag1)
    // {
    //     print(1 << gap << flag1 + 1);
    // }
    // else
    //     print(flag2 + 1 << gap << n);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        04-06-2023 21:01
*/