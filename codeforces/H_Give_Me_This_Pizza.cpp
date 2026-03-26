#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, input;
    cin >> n;
    int inp[n], out[n][2];
    for (int i = 0; i < n; i++)
        cin >> inp[i];

    out[n - 1][0] = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (inp[i + 1] > inp[i])
        {
            out[i][0] = inp[i + 1];
            out[i][1] = i + 1;
        }
        else
        {
            for (int j = i + 1; out[j][0] != -1;)
            {
                // cout << "j=" << j << " out[j][0]=" << out[j][0] << endl;
                if (out[j][0] > inp[i])
                {
                    out[i][0] = out[j][0];
                    out[i][1] = j;
                    goto loop_end;
                }
                j = out[j][1];
            }
            out[i][0] = -1;
        }
    loop_end:;
    }

    for (int i = 0; i < n; i++)
        cout << out[i][0] << ' ';
    cout << endl;

    return 0;
}