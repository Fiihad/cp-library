#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n;
        cin >> n;
        for (int i = n + 1;; i++)
        {
            for (int j = 2; j * j <= i; j++)
                if (!(i % j))
                    goto looping;
            cout << i << endl;
            break;
        looping:;
        }
    }
    return 0;
}