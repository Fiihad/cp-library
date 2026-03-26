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
#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    string in;
    cin >> n >> in;

    stack<int> shoja, ulta;
    vi v(n);
    loop(i,0,n){
        if (in[i]=='('){
            if (ulta.size()) v[i]=2, ulta.pop();
            else shoja.push(i), v[i]=1;
        }
        else{
            if (shoja.size()) v[i]=1, shoja.pop();
            else ulta.push(i), v[i]=2;
        }
    }
    if (ulta.size() || shoja.size()) print(-1);
    else{
        si s(all(v));
        print(s.size());
        if (s.size()==1){
            loop(i,0,n) cout << 1 << gap;
            cout << endl;
        }
        else printx(v);
    }

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        25-05-2023 21:20
*/