#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        long long n;
        cin >> n;
        long long i=2, count=0;
        while (i*(i+1) <= 2*n)
        {
            if (i%2){
                if (n%i==0) count++;
            }
            else if (n%i == i/2) count++;
            i++;
        }

        cout << "Case " << cases << ": " << count << endl;
        
    }
    return 0;
}