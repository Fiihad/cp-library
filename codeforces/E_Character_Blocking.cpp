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
    int n, t, q;
    vector<string> s(2);
    cin >> s[0] >> s[1];
    n = s[0].size();
    cin >> t >> q;

    si mismatc;
    loop(i,0,n) if (s[0][i] != s[1][i]) mismatc.insert(i);

    int time = 0;
    vi task(q+1, -1);

    loop(i, 0, q){
        time++;
        if (task[time] != -1) mismatc.insert(task[time]);

        int mode;
        cin >> mode;
        if (mode == 1){
            int blocked;
            cin >> blocked;
            if (time + t <= q && mismatc.count(blocked-1)) task[time+t] = blocked-1;
            mismatc.erase(blocked-1);
        }

        if (mode == 2){
            int swap1, swap2, swap1ind, swap2ind;
            cin >> swap1 >> swap1ind >> swap2 >> swap2ind;
            swap1--, swap2--, swap1ind--, swap2ind--;

            swap(s[swap1][swap1ind], s[swap2][swap2ind]);
            if (s[0][swap1ind] != s[1][swap1ind]) mismatc.insert(swap1ind);
            else mismatc.erase(swap1ind);
            if (s[0][swap2ind] != s[1][swap2ind]) mismatc.insert(swap2ind);
            else mismatc.erase(swap2ind);
        }

        if (mode == 3){
            if (mismatc.size()==0) YES;
            else NO;
        }
    }

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        08-06-2023 00:12
*/