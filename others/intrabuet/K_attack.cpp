/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার,
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0);  // fast IO! but only when online_judge
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
#define loop(i, begin, end) for(__typeof(end)i=begin-(begin>end); i!=end-(begin>end); i+=1-2*(begin>end))
#define all(v) v.begin(), v.end()

// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}


void solve(int cases);
int32_t main()
{
    fast
    int total_cases = 1;
    // cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
map<char, vector<pii>> teleport;
pii direction[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

void BFS(vector<string> &field, pii src, vector<pii> &dest, vector<vi> &dist)
{
    int n = field.size(), m = field[0].size();
    list<pii> queue;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    visited[src.first][src.second] = true;
    dist[src.first][src.second] = 0;
    queue.push_back(src);

    while (!queue.empty()) {
        pii u = queue.front();
        queue.pop_front();

        for (auto x: direction){
            int i = u.first+x.first, j = u.second+x.second;
            if (i<0 || i>=n || j<0 || j>=m || field[i][j] == '#' || field[i][j] == '*' || visited[i][j]) continue;

            visited[i][j] = true;
            dist[i][j] = dist[u.first][u.second] + 1;
            queue.push_back({i, j});

            if (field[i][j] >= 'A' && field[i][j] <= 'Z'){
                for (auto z: teleport[field[i][j]]){
                    if (visited[z.first][z.second]) continue;
                    visited[z.first][z.second] = true;
                    dist[z.first][z.second] = dist[u.first][u.second] + 1;
                    queue.push_back({z.first, z.second});
                }
            }

            for (auto y: dest) if (dist[y.first][y.second] == LLONG_MAX)
                goto looping;
            return;
        looping:;
        }
    }
}

void solve(int cases)
{
    int n, m;
    cin >> n >> m;
    vector<string> field(n);
    loop(i, 0, n) cin >> field[i];

    pii army1, army2, fort;
    
    loop(i, 0, n) loop(j, 0, m){
        if (field[i][j] == '!') army1 = {i, j};
        else if (field[i][j] == '$') army2 = {i, j};
        else if (field[i][j] == '*') fort = {i, j};
        else if (field[i][j] >= 'A' && field[i][j] <= 'Z') teleport[field[i][j]].push_back({i, j});
    }

    vector<pii> dest;
    for (auto x: direction){
        int i = fort.first+x.first, j = fort.second+x.second;
        if (i<0 || i>=n || j<0 || j>=m || field[i][j] == '#') continue;
        dest.push_back({i, j});
    }
    vector<vi> dist1(n, vi(m, LLONG_MAX)), dist2(n, vi(m, LLONG_MAX));

    BFS(field, army1, dest, dist1);
    BFS(field, army2, dest, dist2);

    int out = LLONG_MAX;
    for (auto x: dest){
        if (dist1[x.first][x.second] != LLONG_MAX && dist2[x.first][x.second] != LLONG_MAX)
            out = min(out, max(dist1[x.first][x.second], dist2[x.first][x.second]));
    }

    if (out == LLONG_MAX) print("Impossible");
    else print(out+1);
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        30-05-2023 16:11
*/