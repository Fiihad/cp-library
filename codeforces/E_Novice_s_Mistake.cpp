/*
        আমার অমনোযোগী ক্লাসরুম... আমার মগজে নষ্ট ধুম...
        আমার বাহিরে বুদ্ধ, ভেতরে হিটলার... লাশের মোড়কে ঘুম :)
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); // fast IO! but only when online_judge
#define debug 0
#else
#define fast ;
#define debug 1
#endif
// for debugging
#define bug(...) \
    if (debug)   \
    __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

// some typedefs for my convenience
#define int long long int
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
// some speedup macros
#define print(str) cout << str << '\n'
#define YES print("YES")
#define NO print("NO")
#define loop(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(v) v.begin(), v.end()

void solve(int cases);
int32_t main()
{
    fast int total_cases = 1;
    cin >> total_cases;
    loop(cases, 1, total_cases + 1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE

int calculate_x(int n, int a, int b)
{
    int l = to_string(n).size();
    int len = l * a - b;
    int intrep = len / l;

    int x = 0;
    while (intrep--)
        x = x * powl(10, l) + n;

    int frep = len % l;
    if (frep) {
        int f = n / powl(10, l - frep);
        x = x * powl(10, to_string(f).size()) + f;
    }
    return x;
}

void solve(int cases)
{
    int n;
    cin >> n;

    int a = 1;
    vector<pii> ans;

    while (a <= 10000)
    {
        int digits_string = to_string(n).size() * a;

        for (int b = digits_string - 6; b <= digits_string - 1; b++)
            if (b > 0 && calculate_x(n, a, b) == n * a - b)
                ans.push_back({a, b});
        a++;
    }

    print(ans.size());
    loop(i, 0, ans.size())
        print(ans[i].first << ' ' << ans[i].second);

}

/*
        Fihad arRahman
        hellofihad@gmail.com
        11-07-2024 22:18
*/