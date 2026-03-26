#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        string a, b;
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int counta=0, countb=0;

        for (int i=0, ai=0, bi=0; bi<m && ai<n; i++)
        {
            if ((counta<k && a[ai]<b[bi]) || countb>=k)
            {
                cout << a[ai];
                ai++;
                counta++;
                countb = 0;
            }
            else if ((countb<k && b[bi]<a[ai]) || counta>=k){
                cout << b[bi];
                bi++;
                counta = 0;
                countb++;
            }
        }

        cout << endl;
    }
    return 0;
}