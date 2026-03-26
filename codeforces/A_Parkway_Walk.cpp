#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n, m;
        cin >> n >> m;

        int sum = 0;
        while (n--)
        {
            int x;
            cin >> x;
            sum += x;
        }

        int output = sum>m? sum-m : 0;
        cout << output << endl;
    }
    return 0;
}