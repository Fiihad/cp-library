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
struct segmenttree
{
    int n;			// size of the input array
    vector<int> st; // segment tree array

    segmenttree(vector<int> &v) // pass the main array to the constructor
    {
        n = v.size();
        st.resize(4 * n, 0); // max 4*n size needed for segment tree array
        build(0, n - 1, 0, v);
    }

    void build(int start, int ending, int node, vector<int> &v)
    // start and ending denotes the range (0 based indexes of the main array) the segment is covering
    // (int)log2(ending-start+1) will denote the height of the node (height of leaves are zero)
    {
        // leaf node base case
        if (start == ending)
        {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;
        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);
        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        // the operation statement
        st[node] = (st[node * 2 + 1] ^ st[node * 2 + 2]);
    }

    int query(int l, int r){ return query(0, n - 1, l, r, 0); }	// main function will call this overload
    int query(int start, int ending, int l, int r, int node)
    {
        // non overlapping case
        if (start > r || ending < l) { return 0; }

        // complete overlap
        if (start >= l && ending <= r){ return st[node]; }

        // partial case
        int mid = (start + ending) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        // the operation statement
        return (q1 ^ q2);
    }

    void update(int x, int y) { update(0, n - 1, 0, x, y); }	// main function will call this overload
    void update(int start, int ending, int node, int index, int value)
    {
        // base case
        if (start == ending)
        {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid) update(start, mid, 2 * node + 1, index, value); // left subtree
        else update(mid + 1, ending, 2 * node + 2, index, value); // right

        // the operation statement
        st[node] = (st[node * 2 + 1] + st[node * 2 + 2]);
    }
};

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n >> q;

    vi v(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(v);

    segmenttree s(v);
    loop(i,0,q){
        int mode, in1, in2;
        cin >> in1 >> in2;
        // if (mode == 1) s.update(in1-1, in2);
        print(s.query(in1-1, in2-1));
    }

END:;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        08-06-2023 11:12
*/