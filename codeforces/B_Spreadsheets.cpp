/*
        ফেরা হলো না ঘরে, নাহি ফিরলো ঘর দিকে আমার
        এসে পথেরই মাঝে,
        পেছনে তাকিয়ে ফিরে আবার
        হেঁটে যাই আমি খুঁজতে কিছু, আমি আজও জানিনা কিসেরি পিছু!
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define debug 0
#else
#define fast ;
#define debug 1
#endif

// for policy based data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// ordered_set: extends set to find_by_order and order_of_key
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// some typedefs for my convenience
#define int long long int
#define double long double
#define pii pair<int, int>
#define vi vector<int>
#define si ordered_set
#define msi ordered_multiset
#define mi map<int, int>
#define mmi multimap<int, int>
// some speedup macros
#define gap ' '
#define endl '\n'
#define pb push_back
#define print(str) cout << str << endl
#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define scanx(array) { for (auto &x: array) cin >> x; }
#define printxp(array) { for (auto x : array) cout << '(' << x.first << ',' << gap << x.second << ')' << gap; cout << endl; }
#define loop(i, begin, end) for(__typeof(end)i=begin-(begin>end); i!=end-(begin>end); i+=1-2*(begin>end))
#define loopit(v) for (auto it=v.begin(); it!=v.end(); it++)
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
    fast // fast IO! but only when online_judge
    int test_cases = 1;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++) solve(cases);

    return 0;
}

// SOLVE STARTS HERE

void solve(int cases)
{
    string in, out;
    cin >> in;

    if (in[0]=='R' && in[1]>'0' && in[1]<='9' && in.find('C')!=string::npos){
        int row, col;
        string row_s, col_s;
        bool c_found = false;
        for (int i=1; i<in.size(); i++){
            if (in[i]=='C') c_found = true;
            else if (!c_found) row_s.pb(in[i]);
            else col_s.pb(in[i]);
        }
        row = stoll(row_s), col = stoll(col_s);

        int i;
        for (i=1; ; i++){
            int check = powl(26, i);
            if (col <= check) break;
            col -= powl(26, i);
        }
        i--;
        for (; i>=0; i--){
            int check = ceil(col / powl(26, i));
            char letter = 'A' + check - 1;
            out.pb(letter);
            col -= (check-1)*powl(26, i);
        }
        out += row_s;
    }
    else {
        string row_s, col_s;
        for (int i=0; i<in.size(); i++){
            if (in[i] >= '0' && in[i] <= '9') row_s.pb(in[i]);
            else col_s.pb(in[i]);
        }
        int col=0;
        for (int i=1; i<col_s.size(); i++) col += powl(26, i);
        bug(col);
        int i = col_s.size()-1;
        for (int j=0; i>=0; j++,i--){
            int check = in[j]-'A';
            col += powl(26,i) * check;
            bug(col, check);
        }
        col++;
        out = 'R' + row_s + 'C' + to_string(col);
    }
    print(out);

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        07-12-2022 00:43
*/