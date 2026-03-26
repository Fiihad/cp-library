#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define print(str) cout << str << endl
#define loop(n) for (int i=0; i<n; i++)
#define loop_v for (auto it=v.begin(); it!=v.end(); it++)
#define loop_s for (auto it=s.begin(); it!=s.end(); it++)

bool check(int x, int ara[], int n, int q)
{
    int total=0;
    for (int i=1; i<=n; i++){
        total += x<=ara[i]? x : ara[i] + (x-ara[i])/2;
    }
    // print(total << ' ' << x);
    if (total>=q) return true;
    return false;
}

int32_t main()
{
    int test_cases;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        int n, q, in, out, sum=0;
        vector<int> v;
        multiset<int> s;
        cin >> n >> q;
        int ara[n+1] = {0};
        loop(q){
            cin >> in;
            ara[in]++;
        }

        int lo=1, hi=q*2, mid;
        while (hi>=lo){
            mid = lo + (hi-lo)/2;
            if (check(mid, ara, n, q)){
                // print("yes");
                out = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        print(out);
    }
    return 0;
}