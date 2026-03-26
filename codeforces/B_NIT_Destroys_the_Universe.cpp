#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n, input=1, yes=0, output=0;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            cin >> input;
            if (!input) yes=1;

            if ((i==0 && input) || (yes && input)){
                yes = 0;
                output++;
            }
        }
        if (output>2) output=2;
        cout << output << endl;
    }
    return 0;
}