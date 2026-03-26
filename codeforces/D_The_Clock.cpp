#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    set<int> pall;
    for(int i=0; i<24; i++)
    {
        if (i<6 || i>9&&i<16 || i>19)
            pall.insert(i*60 + (i%10 * 10 + i/10));
    }
    cin >> test_cases;
    while (test_cases--)
    {
        int h, m, start, round, count=0, started=0;
        scanf("%d:%d %d", &h, &m, &round);
        // cout << h << m << round << endl;
        start = h*60+m;
        for (int i=start;; i+=round)
        {
            if (i>=1440) i-=1440;
            if(started && i==start) break;
            started = 1;
            if (pall.find(i) != pall.end()) count++;
        }

        cout << count << endl;
    }
    return 0;
}