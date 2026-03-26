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
string a, b;
int dp[3001][3001];

int rec(int i, int j){
    if (i<0 || j<0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (a[i]==b[j]) return dp[i][j] = rec(i-1, j-1)+1;
    return dp[i][j] = max(rec(i-1,j), rec(i,j-1));
}

void solve(int cases)
{
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    rec(a.size()-1, b.size()-1);

    string out;
    for (int i=a.size()-1,j=b.size()-1; i>=0 && j>=0;)
    {
        if (a[i]==b[j]) out.push_back(a[i]), i--, j--;
        else if (i && dp[i][j] == dp[i-1][j]) i--;
        else if (j && dp[i][j] == dp[i][j-1]) j--;
        else break;
    }

    reverse(all(out));
    print(out);
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        16-05-2023 12:50
*/