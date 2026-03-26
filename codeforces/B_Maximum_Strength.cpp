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
    string L, R;
    cin >> L >> R;

    n = max(L.size(), R.size());

    reverse(all(L));
    reverse(all(R));

    loop(i,L.size(),n) L.push_back('0');
    loop(i,R.size(),n) R.push_back('0');

    if (L.back() == R.back()){
        for (int i=n-1; i>=0; i--){
            if (flag){
                out += 9;
                continue;
            }

            if (L[i]==R[i]) continue;

            else{
                flag = 1;
                out += llabs(L[i] - R[i]);
            }
        }
    }

    else{
        out = 9*(n-1);
        out += llabs(L[n-1]-R[n-1]);
    }
    print(out);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        18-06-2023 14:26
*/