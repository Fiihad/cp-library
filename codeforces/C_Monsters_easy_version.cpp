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
#define scanx(array) { for (auto &x: array) cin >> x; }

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;
    
    vi v(n);
    scanx(v);

    sort(all(v));
    // flag = v.back();
    q = n;

    // loop(i, 1, n){
    //     if (v[i] - v[i-1] <= 1) continue;
    //     flag = v[i-1];
    //     q = i;
    //     break;
    // }

    // loop(i, q, n){
    //     flag++;
    //     if (flag > v[i]) continue;
    //     out += v[i]-flag;
    // }

    loop(i, 0, n){
        if (i == 0){
            out += v[i]-1, v[i]=1;
        }
        else if (v[i] - v[i-1] > 1) out += v[i]-v[i-1]-1, v[i] = v[i-1]+1;
    }

    print(out);
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        05-02-2023 18:54
*/