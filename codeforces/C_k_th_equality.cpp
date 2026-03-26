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
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    if (c < max(a,b) || c > max(a,b)+1) print(-1);

    else {
        string temp = "1";
        loop(i,0,a-1) temp.push_back('0');
        int A = stoll(temp);

        temp = "1";
        loop(i,0,b-1) temp.push_back('0');
        int Bmin = stoll(temp);

        temp = "1";
        loop(i,0,c-1) temp.push_back('0');
        int Cmin = stoll(temp);

        temp.clear();
        loop(i,0,a) temp.push_back('9');
        int Amax = stoll(temp);

        temp.clear();
        loop(i,0,b) temp.push_back('9');
        int Bmax = stoll(temp);

        temp.clear();
        loop(i,0,c) temp.push_back('9');
        int Cmax = stoll(temp);

        while (k > 0 && A <= Amax){
            int Bshuru = max(Cmin-A, Bmin);
            int Bshesh = min(Cmax-A, Bmax);
            int combi = Bshesh - Bshuru + 1;

            if (combi <= 0){
                A++;
                continue;
            }

            if (combi >= k){
                int B = Bshuru + k - 1;
                print(A << " + " << B << " = " << A+B);
                return;
            }

            k -= combi;
            A++;
        }

        print(-1);
    }

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        18-06-2023 21:38
*/