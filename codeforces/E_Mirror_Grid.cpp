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
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>
#define si set<int>
#define spi set<pii>
#define msi multiset<int>
#define mi map<int, int>
#define mmi multimap<int, int>

#define gap ' '
#define endl '\n'
#define pb push_back
#define mp make_pair
#define print(str) cout << str << endl
#define loop(n) for (int i=0; i<n; i++)
#define loop_v for (auto it=v.begin(); it!=v.end(); it++)
#define loop_s for (auto it=s.begin(); it!=s.end(); it++)
#define all(v) v.begin(), v.end()
#define itf(it) (*it).F
#define its(it) (*it).S
#define F first
#define S second

// for debugging
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

int32_t main()
{
    int test_cases = 1;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        // SOLVE STARTS HERE

        int n, q, in, out=0, sum=0;
        cin >> n;
        int ara[n][n];
        loop(n)
            for (int j=0; j<n; j++){
                char c;
                scanf(" %c", &c);
                ara[i][j] = c - '0';
            }

        for (int x=0; x<=n/2; x++){
            for (int y=x; y<n-x-1; y++){
                sum = ara[x][y]+ara[y][n-x-1]+ara[n-x-1][n-y-1]+ara[n-y-1][x];
                // bug(x,y,ara[x][y],ara[y][n-x-1],ara[n-x-1][n-y-1],ara[n-y-1][x]);
                if (sum==1 || sum==2) out += sum;
                else if (sum==3) out += 1;
            }
        }
        print(out);
    }
    return 0;
}