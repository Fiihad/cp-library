// 01-12-2022 12:48
#include <bits/stdc++.h>
using namespace std;


double C(int n, int r) {
    double ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
        ans *= .4;
    }

    return ans;
}

double solve(double n, double q)
{
    int a = (n-q)/2, b = a+q;
    if (a + b != n)
    {
        return 0;
    }

    double out = C(n, a) * powl(.6, b);
    out += C(n, b) * powl(.6, a);

    return out;

END:;
}

int main (void)
{
    freopen("TestCases.txt", "w", stdout);
    int t = 100;
    cout << t << endl;

    while (t--){
        int a = rand()%1001;
        int b = rand()%a;
        if (solve(a,b)<0.0000001){
            t++; continue;
        }
        cout << a << ' ' << b << endl;
    }
    return 0;
}