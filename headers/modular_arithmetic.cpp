// 04-09-2022 19:55
// modular functions
// for a^b where b is large, see the .h file
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int m = 1e9+7;

int addm(int x, int y) { return (x+y)%m; }

int subm(int x, int y) { return ((x-y)%m + m)%m; }

int mulm(int x, int y) { return (x*y)%m; }

int powrm(int x, int y){    // recursive method, when y is small
    int res = 1;
    while (y) {
        if (y&1) res = mulm(res, x);
        y /= 2;
        x = mulm(x, x);
    }
    return res;
}

int invm(int x) { return powrm(x, m-2); }   // fermat's little theorem

int divm(int x, int y) { return mulm(x, powrm(y, m-2)); }
