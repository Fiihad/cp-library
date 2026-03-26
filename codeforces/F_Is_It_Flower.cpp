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

#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array)         \
    {                         \
        for (auto x : array)  \
            cout << x << gap; \
        cout << endl;         \
    }
#define scanx(array)          \
    {                         \
        for (auto &x : array) \
            cin >> x;         \
    }
#define printxp(array)                                                      \
    {                                                                       \
        for (auto x : array)                                                \
            cout << '(' << x.first << ',' << gap << x.second << ')' << gap; \
        cout << endl;                                                       \
    }

// for debugging
#define bug(...) \
    if (debug)   \
    __f(#__VA_ARGS__, __VA_ARGS__)
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

void solve(int cases);
int32_t main()
{
    fast int total_cases = 1;
    cin >> total_cases;
    loop(cases, 1, total_cases + 1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
class graph
{
    vector<vector<int>> adj_list;
    bool directed;
    int n; // number of vertices
    si cent;

public:
    graph(int i, bool dir = false)
    {
        n = i;
        adj_list.resize(n + 1); // n+1 so will work for both 1 or 0 based indexing
        directed = dir;
    }
    void add_edge(int from, int to)
    {
        adj_list[from].push_back(to);
        if (!directed)
            adj_list[to].push_back(from);
    }
    bool cent_dic(int q)
    {
        int m = sqrtl(n);
        if (m * m != n)
            return false;
        if (q != n + m)
            return false;
        for (int i = 1; i < adj_list.size(); i++)
        {
            if (adj_list[i].size() != 4 && adj_list[i].size() != 2)
                return false;
            if (adj_list[i].size() == 4)
                cent.insert(i);
        }
        // printx(cent);
        // bug(cent.size(), m);
        if (cent.size() != m)
            return false;
        return true;
    }
    bool totaldic()
    {
        int start = *cent.begin();
        vector<bool> visited(n + 1, false);

        int q = start, flag = 1;
        while (1)
        {
            int prev_q = q;
            visited[q] = true;
            // bug (q);
            for (int i = 0; i < adj_list[q].size(); i++)
            {
                if (cent.count(adj_list[q][i]) && !visited[adj_list[q][i]])
                {
                    q = adj_list[q][i];
                    flag++;
                    break;
                }
            }
            if (q == prev_q)
                break;
        }
        if (flag != (int)sqrtl(n))
            return false;
        for (int i = 0; i < adj_list[q].size(); i++)
        {
            if (adj_list[q][i] == start)
                goto here;
        }
        return false;
    here:
        visited.resize(n + 1, false);
        for (auto x : cent)
        {
            q = x, flag = 1;
            while (1)
            {
                visited[q] = true;
                int prev_q = q;
                for (int i = 0; i < adj_list[q].size(); i++)
                {
                    if (!cent.count(adj_list[q][i]) && !visited[adj_list[q][i]])
                    {
                        q = adj_list[q][i];
                        flag++;
                        break;
                    }
                }
                if (q == prev_q)
                    break;
            }
            if (flag != (int)sqrtl(n))
                return false;
            for (int i = 0; i < adj_list[q].size(); i++)
            {
                if (adj_list[q][i] == x)
                    goto there;
            }
            return false;
        there:;
        }
        return true;
    }

    void dfs(int source)
    {
        vector<bool> visited(n + 1, false);
        dfs_helper(source, visited);
        cout << endl;
    }
    void dfs_helper(int source, vector<bool> &visited)
    {
        // Do some work for every node here
        cout << source << ' ';
        visited[source] = true;

        for (auto nbr : adj_list[source])
            if (!visited[nbr])
                dfs_helper(nbr, visited);
    }
};

void solve(int cases)
{
    int n, q, out = 0, sum = 0, flag = 0, maxi = LLONG_MIN, mini = LLONG_MAX;
    int in;
    cin >> n >> q;

    graph g(n);
    loop(i, 0, q) cin >> in >> out, g.add_edge(in, out);

    if (!g.cent_dic(q))
    {
        NO;
        return;
    }
    if (g.totaldic())
        YES;
    else
        NO;

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        12-05-2023 11:22
*/