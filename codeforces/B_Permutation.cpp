#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define print(str) cout << str << endl
#define loop(n) for (int i=0; i<n; i++)
#define loop_v for (auto it=v.begin(); it!=v.end(); it++)
#define loop_s for (auto it=s.begin(); it!=s.end(); it++)

int32_t main()
{
    int test_cases;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        int n, q, in, out, sum=0;
        vector<int> v;
        multiset<int> s;
        cin >> n;

        cout << 2 << endl;
        for (int i=1; i<=n; i+=2)
        {
            cout << i << ' ';
            for (int j=2*i; j<=n; j=2*j)
                cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}