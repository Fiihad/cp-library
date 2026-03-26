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

void solve(int cases)
{
    string in;
    cin >> in;
    int n = in.size(), flag = 1;
    vi v(n);

    loop(i, 0, in.size()){
        int digit;
        if (in[i] >= 'A' && in[i] <= 'Z') digit = in[i]-'A'+10;
        else digit = in[i]-'0';
        v[n-i-1] = digit;
        flag = max(flag, digit);
    }

    loop(k, flag+1, 37){
        int sum = 0;
        loop(i, 0, n){
            sum += v[i];
            sum %= k-1;
        }
        if (!sum){
            print(k);
            return;
        }
    }
    print("No solution.");

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        29-05-2023 02:33
*/