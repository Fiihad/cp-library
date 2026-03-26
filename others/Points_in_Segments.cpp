/*
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define print(str) cout << str << endl
#define loop(n) for (int i=0; i<n; i++)

int32_t main (void)
{
    int test_cases;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        int n, q, in, out;
        cin >> n >> q;
        set<int> ara;
        loop(n){
            cin >> in;
            ara.insert(in);
        }
        cout << "Case " << cases << ":" << endl;
        loop(q){
            int r, l;
            cin >> r >> l;
            auto right = ara.lower_bound(r);
            auto left = ara.upper_bound(l);
            cout << distance(right, left) << endl;
        }
    }
    return 0;
}
*/


#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        int n, q, input;
        cin >> n >> q;
        vector<int> ara;
        for (int i=0; i<n; i++)
        {
            cin >> input;
            ara.push_back(input);
        }
        cout << "Case " << cases << ":" << endl;

        while (q--)
        {
            int r, l, mid;
            cin >> r >> l;

            int lo=0, hi=n-1;
            while(hi-lo>1){
                // cout << lo << hi << endl;
                mid = (lo+hi)/2;
                if (ara[mid]<r) lo=mid+1;
                else if (ara[mid]==r){
                    lo = hi = mid;
                    break;
                }
                else hi = mid;
            }
            r = ara[lo]>=r? lo:hi;
            // cout << lo << hi << endl;
            // cout << r << endl;
            lo=0, hi=n-1;
            while(hi-lo>1){
                // cout << lo << hi << endl;
                mid = (lo+hi)/2;
                if (ara[mid]<l) lo=mid+1;
                else if (ara[mid]==l){
                    hi = lo = mid+1;
                    break;
                }
                else hi = mid;
            }
            l = ara[lo]>l? lo: ara[hi]>l? hi: hi+1;
            // cout << lo << hi << endl;
            // cout << l << endl;
            cout << l-r << endl;
        }
    }
    return 0;
}