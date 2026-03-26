#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int count=0;
        int stick, diamond;
        cin >> stick >> diamond;

        /* while (1)
        {
            if (stick<diamond){
                diamond -= 2;
                stick--;
                if (stick>=0 && diamond>=0) count++;
                else break;
            }
            else {
                diamond--;
                stick -= 2;
                if (stick>=0 && diamond>=0) count++;
                else break;
            }
        }*/

        count = min(stick, min(diamond, (stick+diamond)/3));
        cout << count << endl;
    }
    return 0;
}