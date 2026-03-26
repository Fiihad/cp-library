// 01-12-2022 11:16
#include <bits/stdc++.h>
using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
unsigned long long power(unsigned long long x, int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n, int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
// modular multiplication
int multiply(int a, int b, int c)
{
    int res = 0;
    while (b)
    {
        if (b & 1)
            res = res + a, res %= c;
        a += a;
        a %= c;
        b /= 2;
    }
    return res;
}

int main(void)
{
    freopen("TestCases.txt", "r", stdin);
    freopen("Answers.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        int a = (n - q) / 2, b = a + q;
        if (a + b != n)
        {
            cout << 0 << endl;
        }

        else
        {
            int p = 1e9 + 7;
            int ncr_part = nCrModPFermat(n, a, p);
            int temp = power(2, a, p), temp1 = power(5, a, p);
            temp1 = modInverse(temp1, p);
            int prob_forward = multiply(temp, temp1, p);
            temp = power(6, b, p), temp1 = power(10, b, p);
            temp1 = modInverse(temp1, p);
            int prob_back = multiply(temp, temp1, p);
            int ans = multiply(ncr_part, prob_forward, p);
            ans = multiply(ans, prob_back, p);

            ncr_part = nCrModPFermat(n, b, p);
            temp = power(4, b, p), temp1 = power(10, b, p);
            temp1 = modInverse(temp1, p);
            prob_forward = multiply(temp, temp1, p);
            temp = power(6, a, p), temp1 = power(10, a, p);
            temp1 = modInverse(temp1, p);
            prob_back = multiply(temp, temp1, p);
            int ans2 = multiply(ncr_part, prob_forward, p);
            ans2 = multiply(ans2, prob_back, p);

            ans += ans2;
            ans %= p;

            cout << ans << endl;
        }
    }
    return 0;
}