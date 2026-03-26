#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int count = 0, check = 0, output, dont = 0, i, last;
        char c;
        for (i = 1; i <= 64; i++)
        {
            scanf(" %c", &c);
            if (dont == 0)
            {
                if (c == '#'){
                    count++;
                    last = i;
                }
                if (i % 8 == 0)
                {
                    if (check && count == 1)
                    {
                        output = last;
                        dont = 1;
                    }
                    if (count == 2)
                        check = 1;
                    else
                        check = 0;
                    count = 0;
                }
            }
        }
        cout << output / 8 + 1 << ' ' << output % 8 << endl;
    }
    return 0;
}