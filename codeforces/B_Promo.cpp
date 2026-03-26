#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, q;
    cin >> n >> q;
    int ara[n];
    long long sum_map[n];
    long long total = 0;

    for (int i = 0; i < n; i++)
        cin >> ara[i];
    sort(ara, ara + n, greater<int>());

    for (int i = 0; i < n; i++)
    {
        total += ara[i];
        sum_map[i] = total;
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (x == y)
            cout << sum_map[x - 1] << endl;
        else
            cout << sum_map[x - 1] - sum_map[x - y - 1] << endl;
    }
    return 0;
}