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
int dfs(int n, int row, vector<bool> &visited, int exit_row)
{
    if (n <= 0 || row <= exit_row) return 0;
    if (visited[n]) return 0;
    if (n == 1){
        visited[1] = true;
        return 1;
    }

    visited[n] = true;
    int out = n*n;
    if ((row*(row+1))/2 == n) out += dfs(n-row, row-1, visited, exit_row);
    else if ((row*(row-1))/2 == n-1) out += dfs(n-row+1, row-1, visited, exit_row);
    else out += dfs(n-row, row-1, visited, exit_row) + dfs(n-row+1, row-1, visited, exit_row);

    return out;
}

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;

    int row;
    for (row=1; row<=2023; row++)
        if ((row*(row+1))/2 >= n) break;
    
    int row_shuru = (row*(row-1))/2+1, row_shesh = (row*(row+1))/2;
    int exit_row = min(n-row_shuru+1, row_shesh-n+1);
    int x = (exit_row*(exit_row+1))/2;

    vector<bool> visited(n+1, 0);
    out = dfs(n, row, visited, exit_row) + (x*(x+1)*(2*x+1))/6;

    print(out);
END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        07-05-2023 01:08
*/