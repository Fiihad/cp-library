/*
        অন্তর মম বিকশিত করো অন্তরতর হে–
        নির্মল করো, উজ্জ্বল করো, সুন্দর করো হে ॥
        জাগ্রত করো, উদ্যত করো, নির্ভয় করো হে।
        মঙ্গল করো, নিরলস নিঃসংশয় করো হে ॥
*/

#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#else
#define fast ;
#endif

// for policy based data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// ordered_set: extends set to find_by_order and order_of_key
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int mod = 1e9+7;

#define int long long int
#define double long double
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>
#define si ordered_set
#define spi set<pii>
#define msi ordered_multiset
#define mi map<int, int>
#define mmi multimap<int, int>

#define gap ' '
#define endl '\n'
#define pb push_back
#define mp make_pair
#define print(str) cout << str << endl
#define printp(p) cout << '(' << p.F << ',' << gap << p.S << ')' << endl;
#define printx(array) { for (auto x : array) cout << x << gap; cout << endl; }
#define scanx(array) { for (auto &x: array) cin >> x; }
#define printxp(array) { for (auto x : array) cout << '(' << x.F << ',' << gap << x.S << ')' << gap; cout << endl; }
#define loop(i, n) for (int i=0; i<n; i++)
#define loopit(v) for (auto it=v.begin(); it!=v.end(); it++)
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
    fast // fast IO! but only when online_judge
    int test_cases = 1;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        // SOLVE STARTS HERE

        int n, q, sum=0, maxi=LLONG_MIN, mini=LLONG_MAX;
        string in;
        cin >> in;

        vector<vi> v(26);
        vi out;
        for (int i=1; i<=in.size(); i++){
            v[in[i-1]-'a'].push_back(i);
        }

        if (in.front()<in.back()){
            for (int i=in.front()-'a'; i<=in.back()-'a'; i++){
                if (!v[i].empty()){
                    for (int j=0; j<v[i].size(); j++) out.pb(v[i][j]);
                }
                sum++;
            }
        }
        else {
            for (int i=in.front()-'a'; i>=in.back()-'a'; i--){
                if (!v[i].empty()){
                    for (int j=0; j<v[i].size(); j++) out.pb(v[i][j]), sum++;
                }
                sum++;
            }
        }

        // list<pair<char, int>> v;
        // vector<int> out;
        // out.pb(1);
        // for (int i=1; i<=in.size(); i++){
        //     v.pb(mp(in[i-1], i));
        // }
        // // sort(all(v));
        // v.sort();

        // auto flag = v.begin(), flagEnd = v.begin();
        // for (auto m=v.begin(); m!=v.end(); m++){
        //     if ((*m).S==1) flag = m;
        //     if ((*m).S==in.size()) flagEnd = m;

        //     if ((*flag).S==1 && (*flagEnd).S==in.size()) break;
        // }

        // while (1){
        //     if ((*flag).S == in.size()) break;

        //     auto prev = flag, next = flag;
        //     prev--; next++;
        //     if (abs((*prev).F-(*flag).F) < abs((*next).F-(*flag).F)){
        //         sum += abs((*prev).F-(*flag).F);
        //         out.push_back((*prev).S);
        //         v.erase(flag);
        //         flag = prev;
        //     }
        //     else if (abs((*prev).F-(*flag).F) > abs((*next).F-(*flag).F)){
        //         sum += abs((*next).F-(*flag).F);
        //         out.push_back((*next).S);
        //         v.erase(flag);
        //         flag = next;
        //     }
        //     else{
        //         if (abs((*prev).F-(*flagEnd).F) < abs((*next).F-(*flagEnd).F)){
        //             sum += abs((*prev).F-(*flag).F);
        //             out.push_back((*prev).S);
        //             v.erase(flag);
        //             flag = prev;
        //         }
        //         if (abs((*prev).F-(*flagEnd).F) > abs((*next).F-(*flagEnd).F)){
        //             sum += abs((*next).F-(*flag).F);
        //             out.push_back((*next).S);
        //             v.erase(flag);
        //             flag = next;
        //         }
        //     }
        // }

        print(abs(in.back()-in.front()) << gap << out.size());
        printx(out);
    }
    return 0;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        12-09-2022 20:56
*/