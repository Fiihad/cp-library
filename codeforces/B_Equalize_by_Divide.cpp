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
    int in;
    cin >> n;

    vi v(n);
    #define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
    #define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
    #define scanx(array) { for (auto &x: array) cin >> x; }
    #define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }
    scanx(v);

    if (*min_element(all(v)) == *max_element(all(v))){
        print(0);
        return;
    }
    if (*min_element(all(v)) == 1){
        print(-1);
        return;
    }

    int min_index = min_element(all(v)) - v.begin();
    mini = *min_element(all(v));
    vector<pii> ans;

again:
    loop(i,0,n){
        if (v[i] == mini) continue;
        flag = v[i];
        while (flag > mini){
            flag = ceil(((double)flag)/mini);
            ans.push_back({i, min_index});
        }
        v[i] = flag;
        if (flag < mini){
            min_index = i;
            mini = flag;
            // ans.clear();
            // flag = v[i];
            // while (flag > mini){
            //     flag = ceil(((double)flag)/mini);
            //     ans.push_back({i, min_index});
            // }
            // // ans.push_back({min_index, i});
            // v[i] = flag;
            // // v[min_index] = 2;
            // // out = 1;
            // // break;
            // min_index = i;
            // mini = flag;
            goto again;
        }
    }

    // if (out){
    //     loop(i,0,n){
    //         flag = v[i];
    //         while (flag != 2){
    //             flag = ceil(((double)flag)/2);
    //             ans.push_back({i, min_index});
    //         }
    //     }
    // }

    print(ans.size());
    for (auto x: ans){
        print(x.first+1 << gap << x.second+1);
    }

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        27-02-2023 21:40
*/