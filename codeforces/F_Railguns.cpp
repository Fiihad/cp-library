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

void solve(int cases)
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<set<int>>> guns(2);
    guns[0].resize(n+1), guns[1].resize(m+1);
    loop(i,0,q){
        int mode, row, time;
        cin >> time >> mode >> row;
        guns[mode-1][row].insert(time);
    }

    if (guns[0][1].count(0) || guns[1][1].count(0)){
        print(-1);
        return;
    }

    bool dp[n+1][m+1][q+1];

    loop(i,0,n+1){
        loop(j,0,m+1){
            loop(k,0,q+1){
                if (!i && !j && !k) dp[i][j][k] = true;

                else if (guns[0][i].count(i+j+k) || guns[1][j].count(i+j+k)) dp[i][j][k] = false;
                else{
                    bool out = 0;
                    if (i-1 >= 0) out |= dp[i-1][j][k];
                    if (j-1 >= 0) out |= dp[i][j-1][k];
                    if (k-1 >= 0) out |= dp[i][j][k-1];
                    dp[i][j][k] = out;
                }
            }
        }
    }

    loop(i,0,q+1){
        if (dp[n][m][i]){
            print(n+m+i);
            return;
        }
    }
    print(-1);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        06-06-2023 21:59
*/