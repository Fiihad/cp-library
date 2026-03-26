#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n, k;
        cin >> n >> k;
        int ara[n];
        for (int i=0; i<n; i++)
            cin >> ara[i];

        if (k==1){
            if (n%2){
                cout << n/2 << endl;
                continue;
            }
            else{
                cout << n/2-1 << endl;
                continue;
            }
        }
        int count = 0;
        for (int i=1; i<n-1; i++)
            if (ara[i] > ara[i+1]+ara[i-1]) count++;
        cout << count << endl;

    }
    return 0;
}