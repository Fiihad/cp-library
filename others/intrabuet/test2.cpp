/*
        আমার অমনোযোগী ক্লাসরুম... আমার মগজে নষ্ট ধুম...
        আমার বাহিরে বুদ্ধ, ভেতরে হিটলার... লাশের মোড়কে ঘুম :)
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
// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
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
#define loop(i, begin, end) for (__typeof(end)i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define all(v) v.begin(), v.end()


void solve(int cases);
int32_t main()
{
    fast
    int total_cases = 1;
    cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE
#define printp(p) cout << '(' << p.first << ',' << ' ' << p.second << ')' << '\n';
#define printx(array) { for (auto x: array) cout << x << ' '; cout << '\n'; }
#define printxp(array) { for (int i=0; i<array.size(); ++i) cout << '(' << array[i].first << ',' << ' ' << array[i].second << ')' << ' '; cout << '\n'; }

void solve(int cases)
{
    int n, k;
    cin >> n >> k;
    string in[n];

    loop(i,0,n) cin >> in[i];

    int pref1[n][n] = {0}, pref2[n][n] = {0};

    loop(i,0,n){
        loop(j,0,n){
            if (j == 0) pref1[i][j] = in[i][j] - '0';
            else pref1[i][j] = pref1[i][j-1] + in[i][j] - '0';
        }
    }
    loop(i,n,0){
        loop(j,n,0){
            if (j == n-1) pref2[i][j] = in[i][j] - '0';
            else pref2[i][j] = pref2[i][j+1] + in[i][j] - '0';
        }
    }

    int pref3[n+1] = {0};
    loop(i,1,n+1){
        pref3[i] = pref3[i-1] + pref1[i-1][n-1];
    }

    cout << "Case " << cases << ":\n";

    int q;
    cin >> q;
    loop(i, 0, q){
        int a, b, out = 0, out2 = 0;
        cin >> a >> b;
        int rowbig = a / (n*k);
        int rowsmall = rowbig/k;
        int covered_row = (rowsmall+1) * k;
        int rem_row = covered_row - rowbig;

        int colbig = a % (n*k);
        int colsmall = colbig/k;

        out += pref1[rowsmall][colsmall] * k * (rem_row-1);
        if (colsmall+1 < n) out += pref2[rowsmall][colsmall+1] * k * rem_row;

        int covered_col = colbig + 1 - colsmall*k;
        covered_col = k - covered_col + 1;
        out += (in[rowsmall][colsmall] - '0') * covered_col;


        int rowbig2 = b/(n*k), rowsmall2 = (b/(n*k))/k;
        int colbig2 = b % (n*k);

        if (rowbig2 % k != (k-1) || colbig2 != n*k-1){
            b++;
            int rowbig2 = b / (n*k);
            int rowsmall2 = rowbig2/k;
            int covered_row2 = (rowsmall2+1) * k;
            int rem_row2 = covered_row2 - rowbig2;

            int colbig2 = b % (n*k);
            int colsmall2 = colbig2/k;

            out2 += pref1[rowsmall2][colsmall2] * k * (rem_row2-1);
            if (colsmall2+1 < n) out2 += pref2[rowsmall2][colsmall2+1] * k * rem_row2;

            int covered_col2 = colbig2 + 1 - colsmall2*k;
            covered_col2 = k - covered_col2 + 1;
            out2 += (in[rowsmall2][colsmall2] - '0') * covered_col2;

            b--;
        }

        int out3 = 0;
        if (rowsmall2 + 1 < n+1 && rowsmall + 1 < n+1)
            out3 = pref3[rowsmall2+1] - pref3[rowsmall+1];
        out3 *= (k*k);

        // bug(out, out2, out3);
        out = out + out3 - out2;

        print(out);
    }
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        13-10-2023 18:26
*/