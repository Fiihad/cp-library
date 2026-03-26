#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define print(str) cout << str << endl

void solve(int cases);
int32_t main()
{
    int test_cases = 1;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++) solve(cases);
    return 0;
}

// SOLVE STARTS HERE

double C(int n, int r) {
    double ans = 1;
    for(int i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
        ans *= .4;
    }
    return ans;
}

void solve(int cases)
{
    cout << setprecision(8) << fixed;
    double n, q, out=0;
    cin >> n >> q;

    int a = (n-q)/2, b = a+q;
    if (a + b != n || a < 0 || b < 0)
    {
        print(0.0);
        return;
    }

    out = C(n, a) * powl(.6, b);
    if (a!=b) out += C(n, b) * powl(.6, a);

    print(out);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        01-12-2022 15:13
*/