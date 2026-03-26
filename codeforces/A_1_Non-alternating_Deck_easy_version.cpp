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
    int n, q, out=0, sum=0, flag=0, flagw = 1, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;

    int alice = 1, bob = 0;
    int a1=0, a2=0, b1=0, b2=0, i1, i2;
    for (int i=1; ; i++){
        if (n < i) i = n, flag = 1;
        // print(i << n);
        if (i%2){
            if (flagw){
                i1 = i/2+1, i2 = i-i1;
                flagw = 0;
            }
            else{
                i2 = i/2+1, i1 = i-i2;
                flagw = 1;
            }
        }
        else i1 = i2 = i/2;
        if (alice < 2){
            a1 += i1;
            a2 += i2;
            alice++;
            bob = 0;
        }
        else {
            b1+=i1, b2+=i2;
            bob++;
            if (bob == 2) alice = 0;
        }
        n -= i;
        if (flag) break;
    }
    print(a1 << gap << a2 << gap << b1 << gap << b2);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        05-02-2023 18:07
*/