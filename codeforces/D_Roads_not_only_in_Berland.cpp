/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার,
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
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

// some typedefs for my convenience
#define int long long int
#define pii pair<int, int>
#define vi vector<int>
#define si set<int>
#define mi map<int, int>
// some speedup macros
#define gap ' '
#define endl '\n'
#define print(str) cout << str << endl
#define YES print("YES")
#define NO print("NO")
#define loop(i, begin, end) for (__typeof(end) i = begin - (begin > end); i != end - (begin > end); i += 1 - 2 * (begin > end))
#define all(v) v.begin(), v.end()

void solve(int cases);
int32_t main()
{
    fast int total_cases = 1;
    // cin >> total_cases;
    loop(cases, 1, total_cases + 1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
struct DSU
{
    vector<int> par, rnk, sz;
    int c;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n)
    {
        for (int i = 1; i <= n; ++i)
            par[i] = i;
    }
    int find(int i)
    {
        return (par[i] == i ? i : (par[i] = find(par[i])));
    }
    bool same(int i, int j)
    {
        return find(i) == find(j);
    }
    int get_size(int i)
    {
        return sz[find(i)];
    }
    int count()
    {
        return c; // connected components
    }
    int merge(int i, int j)
    {
        if ((i = find(i)) == (j = find(j)))
            return -1;
        else
            --c;
        if (rnk[i] > rnk[j])
            swap(i, j);
        par[i] = j;
        sz[j] += sz[i];
        if (rnk[i] == rnk[j])
            rnk[j]++;
        return j;
    }
};

void solve(int cases)
{
    int n, q, out = 0, sum = 0, flag = 0, maxi = LLONG_MIN, mini = LLONG_MAX;
    int in;
    cin >> n;

    vector<pii> edges;
    DSU d(n);

    loop(i, 0, n-1){
        cin >> in >> out;

        if (d.same(in, out)) edges.push_back({in, out});
        else d.merge(in, out);
    }

    si parentset;
    loop(i, 1, n+1) parentset.insert(d.find(i));
    vi parentvec(all(parentset));

    print(edges.size());
    loop(i, 0, edges.size()){
        cout << edges[i].first << gap << edges[i].second << gap;
        print(parentvec[i] << gap << parentvec[i+1]);
    }

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        20-06-2023 17:41
*/