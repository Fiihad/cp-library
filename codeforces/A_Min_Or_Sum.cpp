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

        int output=0, x;
        while (n--)
        {
            cin >> x;
            output |= x;
        }
        cout << output << endl;
    }
    return 0;
}