#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    double n, m, a;
    cin >> n >> m >> a;

    long long out = ceil(n / a) * ceil(m / a);
    cout << out << endl;
    return 0;
}