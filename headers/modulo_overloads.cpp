// 28-06-2023 12:32
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
class Modular {
public:
    int value;
    static const int MOD_value = MOD;
    
    Modular(long long v = 0) {
        value = v % MOD;
        if (value < 0) value += MOD;
    }
    // fraction
    Modular(long long a, long long b) : value(0) { *this += a, *this /= b; }

    Modular &operator+=(Modular const &b) {
        value += b.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    Modular &operator-=(Modular const &b) {
        value -= b.value;
        if (value < 0) value += MOD;
        return *this;
    }
    Modular &operator*=(Modular const &b) {
        value = (long long)value * b.value % MOD;
        return *this;
    }
    Modular &operator/=(Modular const &b) { return *this *= inverse(b); }

    friend Modular power(Modular a, long long e) {
        Modular res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a, e >>= 1;
        }
        return res;
    }
    friend Modular inverse(Modular a) { return power(a, MOD - 2); }

    friend Modular operator+(Modular a, Modular const b) { return a += b; }
    friend Modular operator-(Modular a, Modular const b) { return a -= b; }
    friend Modular operator-(Modular const a) { return 0 - a; }
    friend Modular operator*(Modular a, Modular const b) { return a *= b; }
    friend Modular operator/(Modular a, Modular const b) { return a /= b; }
    friend Modular &operator++(Modular &a, int) { return a += 1; }
    friend Modular operator++(Modular const &a, int) { return Modular(a)++; }
    friend Modular &operator--(Modular &a, int) { return a -= 1; }
    friend Modular operator--(Modular const &a, int) { return Modular(a)--; }
    friend bool operator==(Modular const &a, Modular const &b) { return a.value == b.value; }
    friend bool operator!=(Modular const &a, Modular const &b) { return a.value != b.value; }

    friend std::ostream &operator<<(std::ostream &os, Modular const &a) { return os << a.value; }
    friend std::istream &operator>>(std::istream &is, Modular &a) {
        is >> a.value;
        a.value %= MOD;
        if (a.value < 0) a.value += MOD;
        return is;
    }
};

vector<Modular> _fact;
vector<Modular> _invfact;
vector<Modular> _inv;
void init(int m) {
    _fact.resize(m + 1); _invfact.resize(m + 1); _inv.resize(m + 1);
    _fact[0] = 1; _invfact[0] = 1; _inv[0] = 0;
    for (int i = 1; i <= m; i++) _fact[i] = _fact[i - 1] * i;
    _invfact[m] = inverse(_fact[m]);
    for (int i = m; i > 1; i--)
        _invfact[i - 1] = _invfact[i] * i,
        _inv[i] = _invfact[i] * _fact[i - 1];
}
inline Modular fact(int m) { return _fact[m]; }
inline Modular invfact(int m) { return _invfact[m]; }
inline Modular inv(int m) { return _inv[m]; }
inline Modular C(int n, int m) { return fact(n) * invfact(m) * invfact(n - m); }

int main(void)
{
    Modular a, b, c;
    cin >> a >> b >> c;
    init(a.value);
    cout << C(a.value, b.value) << endl;
    return 0;
}