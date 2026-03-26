#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n;
        cin >> n;
        int ara[n];

        for (int i=0; i<n; i++){
            cin >> ara[i];
        }
        cout << ara[n-2] << endl;
    }
    return 0;
}