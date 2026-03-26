#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define print(str) cout << str << endl
#define loop(n) for (int i=0; i<n; i++)

int32_t main()
{
    int test_cases;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        int n, q, in, out, sum=0;
        cin >> n >> q;
        multiset<int, greater<>> ara;
        vector<int> sums;
        loop(n){
            cin >> in;
            ara.insert(in);
        }
        int i=0;
        for (auto it=ara.begin(); it!=ara.end(); it++, i++) {
            sum += *it;
            sums.push_back(sum);
        }
        while (q--)
        {
            cin >> in;
            out = lower_bound(sums.begin(), sums.end(), in) - sums.begin();
            if (out == n) print(-1);
            else print(out+1);
        }
    }
    return 0;
}