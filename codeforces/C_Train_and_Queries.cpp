/*
        অন্তর মম বিকশিত করো অন্তরতর হে–
        নির্মল করো, উজ্জ্বল করো, সুন্দর করো হে ॥
        জাগ্রত করো, উদ্যত করো, নির্ভয় করো হে।
        মঙ্গল করো, নিরলস নিঃসংশয় করো হে ॥
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define vi vector<int>
#define msi multiset<int>
#define si set<int>
#define mi map<int, int>
#define pii pair<int, int>
#define print(str) cout << str << endl
#define gap ' '
#define loop(n) for (int i = 0; i < n; i++)
#define loop_v for (auto it = v.begin(); it != v.end(); it++)
#define loop_s for (auto it = s.begin(); it != s.end(); it++)
#define S(it) (*it).second

// for debugging
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

int low(vector<pii> m, int n, int x)
{
    int out = -1;
    int lo = 0, hi = n - 1, mid;
    while (lo <= hi)
    {
        mid = (hi + lo) / 2;
        if (m[mid].first == x)
        {
            out = m[mid].second;
            hi = mid - 1;
        }
        else if (m[mid].first > x)
            hi = mid - 1;
        else
            lo = mid + 1;
        // cout << mid << gap << (*it).first << gap << (*it).second << endl;
        // cout << out << endl;
    }
    return out;
}

int up(vector<pii> m, int n, int x)
{
    int out = -1;
    int lo = 0, hi = n - 1, mid;
    while (lo <= hi)
    {
        mid = (hi + lo) / 2;
        if (m[mid].first == x)
        {
            out = m[mid].second;
            lo = mid + 1;
        }
        else if (m[mid].first > x)
            hi = mid - 1;
        else
            lo = mid + 1;
        // cout << "up " << out << endl;
    }
    return out;
}

int32_t main()
{
    int test_cases;
    cin >> test_cases;
    for (int cases = 1; cases <= test_cases; cases++)
    {
        int n, q, in, in2, out = 0, sum = 0;
        vi v;
        msi s;
        cin >> n >> q;
        map<int, int> lower, upper;
        loop(n)
        {
            cin >> in;
            pii tpair = make_pair(in, i);
            upper[in] = i;
            if (lower.find(in) == lower.end())
                lower.insert(tpair);
        }

        while (q--)
        {
            cin >> in >> in2;
            auto low = lower.find(in), up = upper.find(in2);
            // bug(S(up), S(low));
            if (low != lower.end() && up != upper.end() && S(up) > S(low))
                print("YES");
            else
                print("NO");
        }

        /* int32_t upara[1000000001] = {0}, downara[1000000001] = {0};
        for (int i=1; i<=n; i++){
         cin >> in;
         upara[in] = i;
         if (downara[in] == 0) downara[in] = i;
        }

        while (q--){
         cin >> in >> in2;
         if (downara[in2] && downara[in] && upara[in2]>downara[in]) print("YES");
         else print("NO");
        }
        */
    }
    return 0;
}